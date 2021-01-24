/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylindre.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viforget <viforget@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/06 15:31:25 by viforget          #+#    #+#             */
/*   Updated: 2021/01/24 14:59:58 by viforget         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MiniRT.h"

int	calc_equ(float p[3], float v[3], float dia, float ret[2][3])
{
	float	a;
	float	b;
	float	delta;
	float	x;
	float	x2;

	float d_a;
	float d_b;
	float d_c;

	normalize_vect(v);
	if (v[X] > ZE || v[X] < ZE * -1)
	{
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
	return (-1);
}

double	reper_change(t_obj *cy, float v[3], float p[3])
{
	float	u[3];
	float	c_v[3];
	float	c_p[3];
	float	c_p2[3];
	double	r[2];
	float	inter[2][3];

	u[X] = cy->vec[X] / 2;
	u[Y] = cy->vec[Y] / 2;
	u[Z] = (1 + cy->vec[Z]) / 2;
	normalize_vect(u);
	rotation(v, u, radian(180), c_v);
	vector_sub(p, cy->c0, c_p);
	rotation(c_p, u, radian(180), c_p2);
	c_v[X] = -c_v[X];
	c_v[Y] = -c_v[Y];
	c_v[Z] = -c_v[Z];
	if (!calc_equ(c_p2, c_v, cy->dia, inter))
		return (-1);
	vector_sub(c_p2, inter[0], inter[0]);
	vector_sub(c_p2, inter[1], inter[1]);
	r[0] = sqrtf(scal_vector(inter[0], inter[0]));
	r[1] = sqrtf(scal_vector(inter[1], inter[1]));
	if (inter[0][Z] > cy->height / 2 ||  inter[0][Z] < cy->height / -2)
		r[0] = -1;
	if (inter[1][Z] > cy->height / 2 ||  inter[1][Z] < cy->height / -2)
		r[1] = -1;
	printf("%3f %3f %3f\n", r[0], r[1] , r[0] < r[1] || r[1] < ZE ? r[0] : r[1]);
	return(r[0] < r[1] || r[1] < ZE ? r[0] : r[1]);
}

double	dist_cy(t_obj *cy, float v[3], float p[3])
{
	double a;

	a = reper_change(cy, v, p);
	return (a);
}
