/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viforget <viforget@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 18:06:31 by viforget          #+#    #+#             */
/*   Updated: 2020/11/10 13:50:05 by viforget         ###   ########.fr       */
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

void	rver()
{

}

void	rhor()
{
	
}

int 	main()
{
	float x[3];
	x[0] = 0.7;
	x[1] = 0;
	x[2] = 0.7;
	ry(x, 45);
	printf("%f %f %f\n", x[0], x[1], x[2]);
}
