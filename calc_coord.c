/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_coord.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viforget <viforget@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/11 08:42:22 by viforget          #+#    #+#             */
/*   Updated: 2020/11/16 11:09:08 by viforget         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MiniRT.h"

int		is_pos(float nb)
{
	if (nb > 0)
		return (1);
	else if (nb < 0)
		return (-1);
	else
		return (0);
}

void	calc_coord(float c[3], float v[3], float dist, float ret[3])
{
	float f;

	f = (dist * dist) / ((v[X] * v[X]) + (v[Y] * v[Y]) + (v[Z] * v[Z]));
	f = sqrtf(f);
	ret[X] = is_pos(v[X]) * v[X] * f; 
	ret[Y] = is_pos(v[Y]) * v[Y] * f; 
	ret[Z] = is_pos(v[Z]) * v[Z] * f;
	ret[X] += c[X];
	ret[Y] += c[Y];
	ret[Z] += c[Z];
}

float	maxf(float a, float b, float c)
{
	if (a >= b && a >= c)
		return (a);
	if (b >= c)
		return (b);
	return (c);
}

void	vect_to(float ori[3], float des[3], float v[3], float *d)
{
	float t;

	v[X] = des[X] - ori[X];
	v[Y] = des[Y] - ori[Y];
	v[X] = des[Z] - ori[Z];
	//t = v[X] * v[X] + v[Y] * v[Y] + v[Z] * v[Z];
	*d = sqrtf(v[X] * v[X] + v[Y] * v[Y] + v[Z] * v[Z]);
	normalize_vect(v);
}
