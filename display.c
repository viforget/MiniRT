/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viforget <viforget@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 13:37:14 by viforget          #+#    #+#             */
/*   Updated: 2020/11/11 17:47:16 by viforget         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MiniRT.h"

float	dist_sp(t_obj *obj, float v[3], float p[3])
{
	float	di[3];
	float	d1;
	float	d2;
	float	discr;
	float	a;
	float	b;
	float	c;

	a = scal_vector(v, v);
	vector_sub(p, obj->c0, di);
	b = 2 * scal_vector(v ,di);
	c = scal_vector(di, di) - (obj->dia / 2) * (obj->dia / 2);
	discr = b * b - 4 * a * c;
	if (b * b - 4 * a * c < ZE)
		return (-1);
	discr = sqrtf(discr);
	d1 = (-b + discr) / 2;
	d2 = (-b - discr) / 2;
	if ((d2 > ZE && d1 > d2) || d1 < ZE)
		d1 = d2;
	if (d1 == 0.000010)
		printf("CHECK\n");
	return (d1 < ZE ? -1 : d1);
}

float	dist_obj(t_obj *obj, float v[3], float p[3])
{
	if (obj->type == SP)
		return(dist_sp(obj, v, p));
	return (-1);
}

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
		//afv("p", p);
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
			p[X] = cam->c[X] + ((- (arg.res_x / 2) + x) * 0.1);
			//p[X] = cam->c[X];
			p[Y] = cam->c[Y] + ((- (arg.res_y / 2) + y) * 0.1);
			//p[Y] = cam->c[Y];
			p[Z] = cam->c[Z];
			p[Z] = 0;
//			v[X] =
			color = call_pixel(arg, cam->vec, p);
			display[y * arg.res_x + x] = color;
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(mlx.mlx, mlx.win, mlx.img, 0, 0);
}
