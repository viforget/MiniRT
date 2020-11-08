/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viforget <viforget@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 18:06:31 by viforget          #+#    #+#             */
/*   Updated: 2020/11/04 19:03:04 by viforget         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MiniRT.h"

void	rx(float c[3], float angle)
{
	float t[3];
	
	t[Y] = c[Y] * cos(angle) - c[Z] * sin(angle);
	t[Z] = c[Y] * sin(angle) + c[Z] * cos(angle);
	c[Y] = t[Y];
	c[Z] = t[Z];
}

void	ry(float c[3], float angle)
{
	float t[3];
	
	t[X] = c[X] * cos(angle) - c[Z] * sin(angle);
	t[Z] = c[X] * -sin(angle) + c[Z] * cos(angle);
	c[X] = t[X];
	c[Z] = t[Z];
}

void	rz(float c[3], float angle)
{
	float t[3];
	
	t[X] = c[X] * cos(angle) - c[Y] * sin(angle);
	t[Y] = c[X] * sin(angle) + c[Y] * cos(angle);
	c[X] = t[X];
	c[Y] = t[Y];
}
