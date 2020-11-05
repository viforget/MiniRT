/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viforget <viforget@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 13:37:14 by viforget          #+#    #+#             */
/*   Updated: 2020/11/05 15:30:46 by viforget         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MiniRT.h"

float	dist_sp(t_obj *obj, float v[3], float p[3])
{
	float	di[3];
	float	discr;
	float	a;
	float	b;
	float	c;

	a = scal_vector(v, v);
	vector_sub(p, obj->c0, di);
	b = 2 * scal_vector(v ,di);
	c = scal_vector(di, di) - (obj->dia / 2) * (obj->dia / 2);
	discr = b * b - 4 * a * c;
	printf("%f\n", discr);
	return (discr);
}

void	call_pixel(t_obj *obj, float v[3], float p[3])
{
	float dist;
	float buf;
	int color;

	dist = -1;
	printf("%i\n", obj->type);
	while(obj)
	{
		printf("AA\n");
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
	
}

//void	display_screen(t_mlx mlx, )
