/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viforget <viforget@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/16 10:55:51 by viforget          #+#    #+#             */
/*   Updated: 2020/11/16 11:00:42 by viforget         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MiniRT.h"

void	normalize_vect(float v[3])
{
	float sum;

	sum = v[X] * v[X] + v[Y] * v[Y] + v[Z] * v[Z];
	v[X] /= sqrtf(sum);
	v[Y] /= sqrtf(sum);
	v[Z] /= sqrtf(sum);
}
