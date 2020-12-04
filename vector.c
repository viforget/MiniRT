/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viforget <viforget@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 13:47:15 by viforget          #+#    #+#             */
/*   Updated: 2020/12/04 17:57:30 by viforget         ###   ########.fr       */
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
