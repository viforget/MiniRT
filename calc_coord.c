/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_coord.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viforget <viforget@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/11 08:42:22 by viforget          #+#    #+#             */
/*   Updated: 2020/11/22 14:34:26 by viforget         ###   ########.fr       */
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

	ret[X] = v[X] * dist; 
	ret[Y] = v[Y] * dist; 
	ret[Z] = v[Z] * dist;
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

void	vect_to(float ori[3], float des[3], float v[3], double *d)
{
	printf("%f\n", v[X]);
	printf("%f\n", des[X]);
	printf("%f\n", ori[X]);
	v[X] = des[X] - ori[X];
	printf("C2\n");
	v[Y] = des[Y] - ori[Y];
	printf("C3\n");
	v[Z] = des[Z] - ori[Z];
	printf("%p\n", d);
	if (d)
		*d = normalize_vect(v);
	else
		normalize_vect(v);
}
