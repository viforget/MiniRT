/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viforget <viforget@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/08 16:08:58 by viforget          #+#    #+#             */
/*   Updated: 2020/11/08 16:40:55 by viforget         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viforget <viforget@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 13:37:14 by viforget          #+#    #+#             */
/*   Updated: 2020/11/08 16:08:34 by viforget         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MiniRT.h"

float	dist_sp(t_obj *obj, float v[3], float p[3])
{
	float	di[3];
	float	d1;
	float	d2;
	float	discr;
	float	a;
	float	b;
	float	c;

	a = scal_vector(v, v);
	vector_sub(p, obj->c0, di);
	b = 2 * scal_vector(v ,di);
	c = scal_vector(di, di) - (obj->dia / 2) * (obj->dia / 2);
	discr = b * b - 4 * a * c;
	if (b * b - 4 * a * c < 0)
		return (-1);
	discr = sqrtf(discr);
	printf("%f %f\n", b, discr);
	d1 = (-b + discr) / 2;
	d2 = (b - discr) / 2;
	printf("%f\n", d1);
	printf("%f\n", d2);
	if (d1 > d2 || d1 < 0)
		d1 = d2;
	
	return (d1 < 0 ? -1 : d1);
}

int		call_pixel(t_obj *obj, float v[3], float p[3])
{
	float dist;
	float buf;
	int color;

	color = -1;
	dist = -1;
	while(obj)
	{
		if (obj->type == SP)
		{
			buf = dist_sp(obj, v, p);
			if (buf >= 0 && (buf < dist || dist == -1))
			{
				dist = buf;
				color = obj->color;
			}
		}
		obj = obj->next;
	}
	return (color);
	
}

//void	display_screen(t_mlx mlx, )
