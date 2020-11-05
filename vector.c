/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viforget <viforget@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 13:47:15 by viforget          #+#    #+#             */
/*   Updated: 2020/11/05 14:05:35 by viforget         ###   ########.fr       */
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
