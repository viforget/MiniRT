/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viforget <viforget@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 13:37:14 by viforget          #+#    #+#             */
/*   Updated: 2020/11/20 14:01:20 by viforget         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MiniRT.h"

int		call_pixel(t_arg arg, float v[3], float p[3])
{
	t_obj	*cobj;
	float	temp[3];
	float	dist;
	float	buf;
	int		color;

	cobj = arg.obj;
	color = 0;
	dist = -1;
	while(cobj)
	{
		buf = dist_obj(cobj, v, p);
		if (buf >= 0 && (buf < dist || dist == -1))
		{	
			dist = buf;
			color = cobj->color;
		}
		cobj = cobj->next;
	}
	if (dist > ZE)
	{
		calc_coord(p, v, dist, temp);
		color = calc_light(temp, color, arg);
	}
	return (color);
	
}

void	display_screen(t_mlx mlx, t_arg arg, t_cam *cam)
{
	int 	x;
	int 	y;
	float	p[3];
	float	v[3];
	float	t[3];
	int		color;
	int		*display;

	y = 0;
	v[Y] = cam->vec[Y];
	v[Z] = cam->vec[Z];
	mlx.img = mlx_new_image(mlx.mlx, arg.res_x, arg.res_y);
	display = (int *)mlx_get_data_addr(mlx.img, &mlx.bpp, &mlx.size_l, &mlx.endian);

	while (y < arg.res_y)
	{
		x = 0;
		while(x < arg.res_x)
		{
			//p[X] = cam->c[X] + ((- (arg.res_x / 2) + x) * 0.1);
			p[X] = cam->c[X];
			//p[Y] = cam->c[Y] + ((- (arg.res_y / 2) + y) * 0.075);
			p[Y] = cam->c[Y];
			p[Z] = cam->c[Z];

			v[Y] = 0;
			rhor(cam->vec, calc_angle_x(cam->fov, arg.res_x, x), t);
			rver(t, calc_angle_y(cam->fov, arg.res_x, y - (arg.res_y / 2)),
					v);
			color = call_pixel(arg, v, p);
			display[y * arg.res_x + x] = color;
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(mlx.mlx, mlx.win, mlx.img, 0, 0);
}
