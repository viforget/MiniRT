/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylindre.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viforget <viforget@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/06 15:31:25 by viforget          #+#    #+#             */
/*   Updated: 2021/01/27 16:31:25 by viforget         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MiniRT.h"

int		circle_inter(float p[3], float v[3], float dia, float ret[2][3])
{
	float	a;
	float	b;
	float	delta;
	float	x;
	float	x2;

	float d_a;
	float d_b;
	float d_c;

	a = v[Y] / v[X];
	b =  p[Y] - (a * p[X]);

	d_a = 1 + a * a;
	d_b = 2 * a * b;
	d_c = (b * b) - ((dia / 2) * (dia / 2));

	delta = (d_b * d_b) - (4 * d_a * d_c);
	if (delta < ZE)
		return (-1);
	delta = sqrtf(delta);
	x = (-d_b + delta) / (2 * d_a);
	x2 = (-d_b - delta) / (2 * d_a);

	ret[0][X] = x;
	ret[0][Y] = a * x + b; 
	ret[0][Z] = p[Z] + v[Z] * ((x - p[X]) / v[X]);


	ret[1][X] = x2;
	ret[1][Y] = a * x2 + b; 
	ret[1][Z] = p[Z] + v[Z] * ((x2 - p[X]) / v[X]);

	return (1);
}

int		check_equ(float p[3], float v[3], float dia, float ret[2][3])
{
	float buf;

	normalize_vect(v);
	if (v[X] != 0)
		return (circle_inter(p, v, dia, ret));
	else if (v[Y] != 0)
	{
		buf = p[X];
		p[X] = p[Y];
		p[Y] = buf;
		buf = v[X];
		v[X] = v[Y];
		v[Y] = buf;
		return(circle_inter(p, v, dia, ret));
	}
	return (-1);	
}
double	reper_change(t_obj *cy, float v[3], float p[3])
{
	float	u[3];
	float	c_v[3];
	float	c_p[3];
	float	c_p2[3];
	double	r[2];
	float	ir[2][3];
	float	ir2[2][3];

	r[0] = 0;
	r[1] = 0;

	half_vector(cy->vec, u);

	rotation(v, u, radian(180), c_v);
	vector_sub(p, cy->c0, c_p);
	rotation(c_p, u, radian(180), c_p2);

	if (check_equ(c_p2, c_v, cy->dia, ir) == -1)
		return (-1);

	if (ir[0][Z] > cy->height / 2 ||  ir[0][Z] < cy->height / -2
			|| (ir[0][X] - c_p2[X]) / c_v[X] < 0)
		r[0] = -1;
	if (ir[1][Z] > cy->height / 2 ||  ir[1][Z] < cy->height / -2
			|| (ir[1][X] - c_p2[X]) / c_v[X] < 0)
		r[1] = -1;

	vector_sub(ir[0], c_p2, ir2[0]);
	vector_sub(ir[1], c_p2, ir2[1]);

	if (r[0] == 0)
		r[0] = sqrtf(scal_vector(ir2[0], ir2[0]));
	if (r[1] == 0)
		r[1] = sqrtf(scal_vector(ir2[1], ir2[1]));

	if (r[0] < ZE)
		return (r[1]);
	if (r[1] < ZE)
		return (r[0]);
	return(r[0] < r[1] ? r[0] : r[1]);
}

double	dist_cy(t_obj *cy, float v[3], float p[3])
{
	double a;

	a = reper_change(cy, v, p);
	if (a != -1)
	if (a == INFINITY || a != a)
		return (-1);
	return (a);
}
