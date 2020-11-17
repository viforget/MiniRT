/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viforget <viforget@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/16 10:55:51 by viforget          #+#    #+#             */
/*   Updated: 2020/11/17 15:00:45 by viforget         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MiniRT.h"

double	normalize_vect(float v[3])
{
	float sum;

	sum = v[X] * v[X] + v[Y] * v[Y] + v[Z] * v[Z];
	sum = sqrtf(sum);
	v[X] /= sum;
	v[Y] /= sum;
	v[Z] /= sum;
	return (sum);
}
