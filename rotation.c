/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viforget <viforget@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 18:06:31 by viforget          #+#    #+#             */
/*   Updated: 2020/12/07 14:35:13 by viforget         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MiniRT.h"

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
