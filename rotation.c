/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viforget <viforget@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 18:06:31 by viforget          #+#    #+#             */
/*   Updated: 2020/11/18 14:34:12 by viforget         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MiniRT.h"

void	rx(float c[3], float angle)
{
	float t[3];
	
	t[Y] = c[Y] * cos(radian(angle)) - c[Z] * sin(radian(angle));
	t[Z] = c[Y] * sin(radian(angle)) + c[Z] * cos(radian(angle));
	c[Y] = t[Y];
	c[Z] = t[Z];
}

void	ry(float c[3], float angle)
{
	float t[3];
	
	t[X] = c[X] * cos(radian(angle)) - c[Z] * sin(radian(angle));
	t[Z] = c[X] * -sin(radian(angle)) + c[Z] * cos(radian(angle));
	c[X] = t[X];
	c[Z] = t[Z];
}

void	rz(float c[3], float angle)
{
	float t[3];
	
	t[X] = c[X] * cos(radian(angle)) - c[Y] * sin(radian(angle));
	t[Y] = c[X] * sin(radian(angle)) + c[Y] * cos(radian(angle));
	c[X] = t[X];
	c[Y] = t[Y];
}

void	rver(float v[3], float a, float ret[3])
{
	float u[3];

	u[X] = v[Z];
	u[Y] = 0;
	u[Z] = -v[X];
	normalize_vect(u);

	ret[X] = v[X] * (u[X] * u[X] * (1 - cos(a)) + cos(a))
		+ v[Y] * (u[X] * u[Y] * (1 - cos(a)) + u[Z] * sin(a))
		+ v[Z] * (u[X] * u[Z] * (1 - cos(a)) - u[Y] * sin(a));
	ret[Y] = v[X] * (u[X] * u[Y] * (1 - cos(a)) - u[Z] * sin(a))
		+ v[Y] * (u[Y] * u[Y] * (1 - cos(a)) + cos(a))
		+ v[Z] * (u[Y] * u[Z] * (1 - cos(a)) + u[X] * sin(a));
	ret[Z] = v[X] * (u[X] * u[Z] * (1 - cos(a)) + u[Y] * sin(a))
		+ v[Y] * (u[Y] * u[Z] * (1 - cos(a)) - u[X] * sin(a))
		+ v[Z] * (u[Z] * u[Z] * (1 - cos(a)) + cos(a));
}

void	rhor(float v[3], float ang, float ret[3])
{
	ret[X] = (v[X] * cos(ang)) + (v[Z] * sin(ang) * -1);
	ret[Y] = v[Y];
	ret[Z] = (v[X] * sin(ang)) + (v[Z] * cos(ang));
}

/*int		main()
{
	float v[3];
	float r[3];
	v[X] = 0;
	v[Y] = 0;
	v[Z] = 1;
	rver(v, radian(90), r);
	afv("r ", r);
}*/
