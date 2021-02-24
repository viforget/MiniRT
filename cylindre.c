/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylindre.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viforget <viforget@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/06 15:31:25 by viforget          #+#    #+#             */
/*   Updated: 2021/02/24 10:10:38 by viforget         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int		circle_inter(float p[3], float v[3], float dia, float ret[2][3])
{
	float	a;
	float	b;
	float	delta;
	float	x[2];
	float	d[3];

	a = v[Y] / v[X];
	b = p[Y] - (a * p[X]);
	d[A] = 1 + a * a;
	d[B] = 2 * a * b;
	d[C] = (b * b) - ((dia / 2) * (dia / 2));
	delta = (d[B] * d[B]) - (4 * d[A] * d[C]);
	if (delta < ZE)
		return (-1);
	delta = sqrtf(delta);
	x[0] = (-d[B] + delta) / (2 * d[A]);
	x[1] = (-d[B] - delta) / (2 * d[A]);
	ret[0][X] = x[0];
	ret[0][Y] = a * x[0] + b;
	ret[0][Z] = p[Z] + v[Z] * ((x[0] - p[X]) / v[X]);
	ret[1][X] = x[1];
	ret[1][Y] = a * x[1] + b;
	ret[1][Z] = p[Z] + v[Z] * ((x[1] - p[X]) / v[X]);
	return (1);
}

int		check_equ(float p[3], float v[3], float dia, float ret[2][3])
{
	float buf;

	normalize_vect(v);
	if (v[X] > ZE || v[X] < ZE * -1)
		return (circle_inter(p, v, dia, ret));
	else if (v[Y] != 0)
	{
		buf = p[X];
		p[X] = p[Y];
		p[Y] = buf;
		buf = v[X];
		v[X] = v[Y];
		v[Y] = buf;
		return (circle_inter(p, v, dia, ret));
	}
	return (-1);
}

double	reper_change(t_obj *cy, float v[3], float p[3])
{
	float	u[3];
	float	c[2][3];
	double	r[2];
	float	ir[2][3];
	float	ir2[2][3];

	bzero_d2(r);
	set_cy(cy, v, p, c);
	if (check_equ(c[1], c[0], cy->dia, ir) == -1)
		return (-1);
	if (ir[0][Z] > cy->height / 2 || ir[0][Z] < cy->height / -2
			|| (ir[0][X] - c[1][X]) / c[0][X] < 0)
		r[0] = -1;
	if (ir[1][Z] > cy->height / 2 || ir[1][Z] < cy->height / -2
			|| (ir[1][X] - c[1][X]) / c[0][X] < 0)
		r[1] = -1;
	vector_sub(ir[0], c[1], ir2[0]);
	vector_sub(ir[1], c[1], ir2[1]);
	r[0] = (r[0] == 0 ? sqrtf(scal_vector(ir2[0], ir2[0])) : -1);
	r[1] = (r[1] == 0 ? sqrtf(scal_vector(ir2[1], ir2[1])) : -1);
	if (r[0] < ZE)
		return (r[1]);
	if (r[1] < ZE)
		return (r[0]);
	return (r[0] < r[1] ? r[0] : r[1]);
}

double	dist_cy(t_obj *cy, float v[3], float p[3])
{
	double a;

	a = reper_change(cy, v, p);
	if (a == INFINITY || a != a)
		return (-1);
	return (a);
}
