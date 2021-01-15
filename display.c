/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viforget <viforget@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 13:37:14 by viforget          #+#    #+#             */
/*   Updated: 2021/01/15 15:29:05 by viforget         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MiniRT.h"

void	setup_call_pixel(t_obj *obj, float *d, int *c)
{
	obj = NULL;
	*d = -1;
	*c = 0;
}

int		call_pixel(t_arg arg, float v[3], float p[3], int *color)
{
	t_obj	*cobj;
	float	temp[3];
	float	dist;
	float	buf;
	t_obj	*obj;

	cobj = arg.obj;
	setup_call_pixel(obj, &dist, color);
	while (cobj)
	{
		buf = dist_obj(cobj, v, p);
		if (buf >= 0 && (buf < dist || dist == -1))
		{
			dist = buf;
			obj = cobj;
		}
		cobj = cobj->next;
	}
	if (dist > ZE)
	{
		calc_coord(p, v, dist, temp);
		*color = calc_light(temp, arg, obj, 1);
	}
	return (*color);
}

void	display_screen(t_mlx mlx, t_arg arg, t_cam *cam)
{
	int		c[2];
	float	v[3];
	float	t[3];
	int		color;
	int		*display;

	c[Y] = 0;
	while (c[Y] < arg.res_y)
	{
		c[X] = 0;
		while (c[X] < arg.res_x)
		{
			rhor(cam->vec, calc_angle_x(cam->fov, arg.res_x, c[X]), t);
			rver(t, calc_angle_y(cam->fov, arg.res_x, c[Y] - (arg.res_y / 2)),
					v);
			call_pixel(arg, v, cam->c, &color);
			cam->disp[c[Y] * arg.res_x + c[X]] = color;
			c[X]++;
		}
		c[Y]++;
	}
}
