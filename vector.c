/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viforget <viforget@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 13:47:15 by viforget          #+#    #+#             */
/*   Updated: 2020/12/15 15:44:01 by viforget         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MiniRT.h"

float	scal_vector(float v1[3], float v2[3])
{
	return (v1[X] * v2[X] + v1[Y] * v2[Y] + v1[Z] * v2[Z]);
}

void	vector_sub(float v1[3], float v2[3], float ret[3])
{
	ret[X] = v1[X] - v2[X];
	ret[Y] = v1[Y] - v2[Y];
	ret[Z] = v1[Z] - v2[Z];
}

void	invert_vector(float v[3], float ret[3])
{
	ret[0] = -v[0];
	ret[1] = -v[1];
	ret[2] = -v[2];
}

void	ortho_vector(float v[3], float u[3], float ret[3])
{
	ret[X] = v[Y] * u[Z] + (v[Z] * u[Y] * - 1);
	ret[Y] = v[Z] * u[X] + (v[X] * u[Z] * - 1);
	ret[Z] = v[X] * u[Y] + (v[Y] * u[X] * - 1);
}

void	ortho_triangle(t_obj *triangle)
{
	float v[3];
	float u[3];

	link_point(triangle->c0, triangle->c1, v);
	normalize_vect(v);
	link_point(triangle->c1, triangle->c2, u);
	normalize_vect(u);
	ortho_vector(v, u, triangle->vec);
	normalize_vect(triangle->vec);
}
