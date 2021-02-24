/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viforget <viforget@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 18:06:31 by viforget          #+#    #+#             */
/*   Updated: 2021/02/24 10:11:18 by viforget         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	set_cy(t_obj *cy, float v[3], float p[3], float c[2][3])
{
	float u[3];

	half_vector(cy->vec, u);
	rotation(v, u, radian(180), c[0]);
	vector_sub(p, cy->c0, c[1]);
	rotation(c[1], u, radian(180), c[1]);
}

void	rot_fov(t_arg *arg, float v[3], int x, int y)
{
	float t[3];

	rhor(arg->cam->vec, calc_angle_x(arg->cam->fov, arg->res_x, x), t);
	rver(t, calc_angle_y(arg->cam->fov, arg->res_x, y - (arg->res_y / 2)), v);
}

void	rotation(float v[3], float u[3], float a, float ret[3])
{
	float	buf[3];

	buf[X] = v[X] * (u[X] * u[X] * (1 - cos(a)) + cos(a))
		+ v[Y] * (u[X] * u[Y] * (1 - cos(a)) + u[Z] * sin(a))
		+ v[Z] * (u[X] * u[Z] * (1 - cos(a)) - u[Y] * sin(a));
	buf[Y] = v[X] * (u[X] * u[Y] * (1 - cos(a)) - u[Z] * sin(a))
		+ v[Y] * (u[Y] * u[Y] * (1 - cos(a)) + cos(a))
		+ v[Z] * (u[Y] * u[Z] * (1 - cos(a)) + u[X] * sin(a));
	buf[Z] = v[X] * (u[X] * u[Z] * (1 - cos(a)) + u[Y] * sin(a))
		+ v[Y] * (u[Y] * u[Z] * (1 - cos(a)) - u[X] * sin(a))
		+ v[Z] * (u[Z] * u[Z] * (1 - cos(a)) + cos(a));
	ret[0] = buf[0];
	ret[1] = buf[1];
	ret[2] = buf[2];
}

void	rver(float v[3], float a, float ret[3])
{
	float u[3];

	u[X] = v[Z];
	u[Y] = 0;
	u[Z] = -v[X];
	normalize_vect(u);
	ret[X] = v[X] * (u[X] * u[X] * (1 - cos(a)) + cos(a))
		+ v[Y] * (u[X] * u[Y] * (1 - cos(a)) + u[Z] * sin(a))
		+ v[Z] * (u[X] * u[Z] * (1 - cos(a)) - u[Y] * sin(a));
	ret[Y] = v[X] * (u[X] * u[Y] * (1 - cos(a)) - u[Z] * sin(a))
		+ v[Y] * (u[Y] * u[Y] * (1 - cos(a)) + cos(a))
		+ v[Z] * (u[Y] * u[Z] * (1 - cos(a)) + u[X] * sin(a));
	ret[Z] = v[X] * (u[X] * u[Z] * (1 - cos(a)) + u[Y] * sin(a))
		+ v[Y] * (u[Y] * u[Z] * (1 - cos(a)) - u[X] * sin(a))
		+ v[Z] * (u[Z] * u[Z] * (1 - cos(a)) + cos(a));
}

void	rhor(float v[3], float ang, float ret[3])
{
	ret[X] = (v[X] * cos(ang)) + (v[Z] * sin(ang) * -1);
	ret[Y] = v[Y];
	ret[Z] = (v[X] * sin(ang)) + (v[Z] * cos(ang));
}
