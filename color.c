/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viforget <viforget@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/22 12:48:30 by viforget          #+#    #+#             */
/*   Updated: 2020/11/22 14:30:45 by viforget         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MiniRT.h"

void	bzero_vect(float v[3])
{
	v[0] = 0;
	v[1] = 0;
	v[2] = 0;
}

int		v_to_color(float v[3])
{
	int ret;

	ret = 0;
	ret += (int)(v[RED] * 255 * 0x10000);
	ret += (int)(v[GREEN] * 255 * 0x100);
	ret += (int)(v[BLUE] * 255);
	return (ret);
}

void	col_to_com(int color, float ret[3])
{
	ret[RED] = (float)(color / 0x10000) / 255;
	ret[GREEN] = ((float)((color / 0x100) % 0x100) / 255);
	ret[BLUE] = ((float)(color % 0x100) / 255);
}

void	intens_add(float col[3], int l_color, float intensity, int color)
{
	float	l_c[3];
	float	o_c[3];

	col_to_com(l_color, l_c);
	col_to_com(color, o_c);
	col[RED] += l_c[RED] * intensity * o_c[RED];
	if (col[RED] >= 1)
		col[RED] = 1;
	col[GREEN] += l_c[GREEN] * intensity * o_c[GREEN];
	if (col[GREEN] >= 1)
		col[GREEN] = 1;
	col[BLUE] += l_c[BLUE] * intensity * o_c[BLUE];
	if (col[BLUE] >= 1)
		col[BLUE] = 1;
}

float	diff_angle(float u[3], float v[3])
{
	float	ang;

	ang = (u[X] * v[X] + u[Y] * v[Y] + u[Z] * v[Z]);
	//ang /= sqrtf(u[X] * u[X] * u[Y]  * u[Y] * u[Z] * u[Z]) 
	//	* sqrtf(v[X] * v[X] * v[Y]  * v[Y] * v[Z] * v[Z]);
	return (acos(ang) * (180 / M_PI));
}

float	rat_ang(float p[3], float ct[3], float v[3])
{
	float	d[3];

	printf("A\n");
	vect_to(ct, p, d, NULL);
	printf("B\n");
	return (diff_angle(v, d));
}
