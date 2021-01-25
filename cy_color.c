/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cy_color.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viforget <viforget@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/25 16:04:30 by viforget          #+#    #+#             */
/*   Updated: 2021/01/25 16:40:42 by viforget         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MiniRT.h"

void	half_vector(float v[3], float u[3])
{
	u[X] = v[X] / 2;
	u[Y] = v[Y] / 2;
	u[Z] = (1 + v[Z]) / 2;
	normalize_vect(u);
}

float	cy_color(float p[3], float v[3], t_obj *cy)
{
	float	u[3];
	float	c_v[3];
	float	c_p[3];
	float	c_p2[3];

	half_vector(v, u);
	rotation(v, u, radian(180), c_v);
	vector_sub(p, cy->c0, c_p);
	rotation(c_p, u, radian(180), c_p2);
	c_p2[Z] = 0;
	normalize_vect(c_p2);
	//return(90);
	return(90 - diff_angle(c_p2, c_v));
}
