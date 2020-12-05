/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viforget <viforget@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/22 12:48:30 by viforget          #+#    #+#             */
/*   Updated: 2020/12/05 13:45:10 by viforget         ###   ########.fr       */
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
	ret += (int)(v[RED] * 255) * 0x10000;
	ret += (int)(v[GREEN] * 255) * 0x100;
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

	if (intensity < 0)
		intensity = 0;
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
	return (acos(ang) * (180 / M_PI));
}

float	rat_ang(float p[3], float v[3], t_obj *obj)
{
	float d[3];
	float ret;

	ret = 0;
	if (obj->type == SP)
	{
		vect_to(obj->c0, p, d, NULL);
		ret =  90 - diff_angle(v, d);
	}
	else if (obj->type == PL)
	{
		invert_vector(obj->vec, d);
		ret = 90 - diff_angle(d, v);
	}
	ret /= 90;
	return (ret > 1 ? 1 - (ret - 1) : ret);
}

/*int main()
{
	float p[3] = {0, 0, 30};
	float v[3] = {0, 0, 1};
	float ct[3] = {0, 0, 35};
	t_obj *obj;
	obj = malloc(sizeof(t_obj));
	obj->type = SP;
	obj->c0[0] = 0;
	obj->c0[1] = -5;
	obj->c0[2] = 30;
	obj->dia = 10;
	printf("%g\n", ang_obj(p, v, obj));
}*/
