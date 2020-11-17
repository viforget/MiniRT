/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   distance.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viforget <viforget@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/17 14:51:47 by viforget          #+#    #+#             */
/*   Updated: 2020/11/17 14:52:00 by viforget         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MiniRT.h"

double	dist_sp(t_obj *obj, float v[3], float p[3])
{
	float	di[3];
	double	d1;
	double	d2;
	double	discr;
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
	discr = sqrt(discr);
	d1 = (-b + discr) / 2;
	d2 = (-b - discr) / 2;
	//printf("d :%f %f\n",  d1, d2);
	if ((d2 > ZE && d1 > d2) || d1 < ZE)
		d1 = d2;
	return (d1 < ZE ? -1 : d1);
}

double	dist_obj(t_obj *obj, float v[3], float p[3])
{
	if (obj->type == SP)
		return(dist_sp(obj, v, p));
	return (-1);
}
