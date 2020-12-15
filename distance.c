/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   distance.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viforget <viforget@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/17 14:51:47 by viforget          #+#    #+#             */
/*   Updated: 2020/12/15 16:13:22 by viforget         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MiniRT.h"

double	dist_sp(t_obj *obj, float v[3], float p[3])
{
	float	di[3];
	double	d1;
	double	d2;
	double	discr;
	float	val[3];

	val[A] = scal_vector(v, v);
	vector_sub(p, obj->c0, di);
	val[B] = 2 * scal_vector(v, di);
	val[C] = scal_vector(di, di) - (obj->dia / 2) * (obj->dia / 2);
	discr = val[B] * val[B] - 4 * val[A] * val[C];
	if (val[B] * val[B] - 4 * val[A] * val[C] < ZE)
		return (-1);
	discr = sqrt(discr);
	d1 = (-val[B] + discr) / 2;
	d2 = (-val[B] - discr) / 2;
	if ((d2 > ZE && d1 > d2) || d1 < ZE)
		d1 = d2;
	return (d1 < ZE ? -1 : d1);
}

double	dist_pl(t_obj *obj, float v[3], float p[3])
{
	double	d;
	float	a_o;
	float	d_po;
	float	v_po[3];
	float	v_obj[3];

	invert_vector(obj->vec, v_obj);
	vector_sub(obj->c0, p, v_po);
	d_po = sqrtf(v_po[0] * v_po[0] + v_po[1] * v_po[1] + v_po[2] * v_po[2]);
	normalize_vect(v_po);
	a_o = diff_angle(v_obj, v_po);
	d_po = cos(radian(a_o)) * d_po;
	a_o = diff_angle(v, v_obj);
	d = d_po / cos(radian(a_o));
	return (d);
}

double	dist_tr(t_obj *obj, float v[3], float p[3])
{
	return (dist_pl(obj, v, p));
}

double	dist_obj(t_obj *obj, float v[3], float p[3])
{
	if (obj->type == SP)
		return (dist_sp(obj, v, p));
	else if (obj->type == PL)
		return (dist_pl(obj, v, p));
	else if (obj->type == TR)
		return (dist_tr(obj, v, p));
	return (-1);
}
