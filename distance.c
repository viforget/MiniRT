/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   distance.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viforget <viforget@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/17 14:51:47 by viforget          #+#    #+#             */
/*   Updated: 2020/11/24 11:57:05 by viforget         ###   ########.fr       */
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
	if ((d2 > ZE && d1 > d2) || d1 < ZE)
		d1 = d2;
	return (d1 < ZE ? -1 : d1);
}

double	dist_pl(t_obj *obj, float v[3], float p[3])
{
	float	d; //distance of the light/cam ray
	float	a_r; //angle of the ray and vect to obejct
	float	a_o; //angle vect to obejc and vec to pointt
	float	d_obj; //shortest distance of the plan
	float	d_po; //distance of the relative point of the plane
	float	v_po[3]; //vector of the relative point of the plane
	float	v_obj[3]; //vector to the shortest distance of the plan

	invert_vector(obj->vec, v_obj);
	vector_sub(obj->c0, p, v_po);
	d_po = sqrtf(v_po[0] * v_po[0] + v_po[1] * v_po[1] + v_po[2] * v_po[2]);
	normalize_vect(v_po);
	a_o = diff_angle(v_obj, v_po);
	d_obj = cos(radian(a_o)) * d_po;
	a_r = diff_angle(v, v_obj);
	d = d_obj / cos(radian(a_r));
	return (d);
}

double	dist_obj(t_obj *obj, float v[3], float p[3])
{
	if (obj->type == SP)
		return(dist_sp(obj, v, p));
	else if (obj->type == PL)
		return(dist_pl(obj, v, p));
	return (-1);
}
