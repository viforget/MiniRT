/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylindre.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viforget <viforget@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/06 15:31:25 by viforget          #+#    #+#             */
/*   Updated: 2021/01/19 15:25:01 by viforget         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MiniRT.h"

void	calc_equ(float p[3], float v[3], float dia, float ret[2][3])
{
	float	a;
	float	b;
	float	delta;
	float	x;
	float	x2;

	a = v[Y] / v[X];
	b = -(a * p[X] - p[Y]);
	
	delta = (a * b) * (a * b) - 4 * ((1 - a) * b * b - (dia / 2) * (dia / 2));
	if (delta < ZE)
		//return (-1);
	delta = sqrtf(delta);
	x = (-a * b + delta) / (2 * (1 + a));
	x2 = (-a * b - delta) / (2 * (1 + a));
	ret[0][X] = x;
	ret[0][Y] = a * x + b; 
	ret[0][Z] = p[Z] + v[Z] * ((x - p[X]) / v[X]);
	ret[1][X] = x2;
	ret[1][Y] = a * x2 + b; 
	ret[1][Z] = p[Z] + v[Z] * ((x2  - p[X])/ v[X]);

}

void	reper_change(t_obj *cy, float v[3], float p[3])
{
	float	u[3];
	float	c_v[3];
	float	c_p[3];
	float	inter[2][3];

	u[X] = cy->vec[X] / 2;
	u[Y] = cy->vec[Y] / 2;
	u[Z] = (1 + cy->vec[Z]) / 2;
	normalize_vect(u);
	rotation(v, u, radian(180), c_v);
	vector_sub(c_p, cy->c0, c_p);
	rotation(p, u, radian(180), c_p);
	calc_equ(c_p, c_v, cy->dia, inter);
}

double	dist_cy(t_obj *cy, float v[3], float p[3])
{
	reper_change(cy, v, p);
	return (-1);
}
