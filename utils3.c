/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viforget <viforget@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/16 10:55:51 by viforget          #+#    #+#             */
/*   Updated: 2021/02/24 10:11:37 by viforget         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	bzero_vect(float v[3])
{
	v[0] = 0;
	v[1] = 0;
	v[2] = 0;
}

void	bzero_d2(double d[2])
{
	d[0] = 0;
	d[1] = 0;
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
	angle = -(div * fov) + (fov / 2);
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
