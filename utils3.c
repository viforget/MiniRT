/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viforget <viforget@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/16 10:55:51 by viforget          #+#    #+#             */
/*   Updated: 2021/01/15 15:31:37 by viforget         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MiniRT.h"

void	bzero_vect(float v[3])
{
	v[0] = 0;
	v[1] = 0;
	v[2] = 0;
}

float	calc_angle_x(float fov, int res, int x)
{
	float	angle;
	float	div;

	div = (float)x / res;
	angle = (fov / 2) - (fov * div);
	return (radian(angle));
}

float	calc_angle_y(float fov, int res, int y)
{
	float	angle;
	float	div;

	div = (((float)res / 2) + y) / res;
	angle = - (div * fov) + (fov / 2);
	return (radian(angle));
}

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

void	link_point(float p1[3], float p2[3], float ret[3])
{
		ret[0] = p1[0] - p2[0];
		ret[1] = p1[1] - p2[1];
		ret[2] = p1[2] - p2[2];
}
