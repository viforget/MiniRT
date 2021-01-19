/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   distance.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viforget <viforget@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/17 14:51:47 by viforget          #+#    #+#             */
/*   Updated: 2021/01/19 14:44:32 by viforget         ###   ########.fr       */
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
	if (discr < ZE)
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
	double	a_o;
	double	d_po;
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

double	dist_tr(t_obj *tr, float v[3], float p[3])
{
	float edge[2][3];
	float h[3];
	float q[3];
	float s[3];
	float a[3];

	vector_sub(tr->c1, tr->c0, edge[0]);
	vector_sub(tr->c2, tr->c0, edge[1]);
	ortho_vector(v, edge[1], h);
	a[0] = scal_vector(edge[0], h);
	if (a[0] > -ZE && a[0] < ZE)
		return (-1);
	a[0] = 1.0 / a[0];
	vector_sub(p, tr->c0, s);
	a[2] = a[0] * scal_vector(s, h);
	if (a[2] < 0.0 || a[2] > 1.0)
		return (-1);
	ortho_vector(s, edge[0], h);
	a[1] = a[0] * scal_vector(v, h);
	if (a[1] < 0.0 || a[2] + a[1] > 1.0)
		return (-1);
	a[0] = a[0] * scal_vector(edge[1], h);
	if (a[0] > ZE)
		return (a[0]);
	return (-1);
}

double	dist_sq(t_obj *sq, float v[3], float p[3])
{
	double d;
	float tem;

	d = dist_pl(sq, v, p);
	tem = p[X] + d * v[X];
	if (tem < sq->c1[X] - ZE || tem > sq->c2[X] + ZE)
		return (-1);
	tem = p[Y] + d * v[Y];
	if (tem < sq->c1[Y] - ZE || tem > sq->c2[Y] + ZE)
		return (-1);
	tem = p[Z] + d * v[Z];
	if (tem < sq->c1[Z] - ZE || tem > sq->c2[Z] + ZE)
		return (-1);
	return (d);
}

double	dist_obj(t_obj *obj, float v[3], float p[3])
{
	if (obj->type == SP)
		return (dist_sp(obj, v, p));
	else if (obj->type == PL)
		return (dist_pl(obj, v, p));
	else if (obj->type == TR)
		return (dist_tr(obj, v, p));
	else if (obj->type == SQ)
		return (dist_sq(obj, v, p));
	else if (obj->type == CY)
		return (dist_cy(obj, v, p));
	return (-1);
}
