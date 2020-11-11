/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_coord.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viforget <viforget@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/11 08:42:22 by viforget          #+#    #+#             */
/*   Updated: 2020/11/11 09:16:53 by viforget         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MiniRT.h"

int		is_pos(float nb)
{
	if (nb > 0)
		return (1);
	else if (nb < 0)
		return (-1);
	else
		return (0);
}

void	calc_coord(float c[3], float v[3], float dist, float ret[3])
{
	float f;

	f = (dist * dist) / ((v[X] * v[X]) + (v[Y] * v[Y]) + (v[Z] * v[Z]));
	f = sqrtf(f);
	//ret[X] = sqrtf((dist * dist) / ((v[Y] * v[Y] * f) + ((v[Z] * v[Z] * f))));
	//ret[Y] = sqrtf((dist * dist) / ((v[X] * v[X] * f) + ((v[Z] * v[Z] * f))));
	//ret[Z] = sqrtf((dist * dist) / ((v[X] * v[X] * f) + ((v[Y] * v[Y] * f))));
	ret[X] = v[X] * f;
	ret[Y] = v[Y] * f;
	ret[Z] = v[Z] * f;
	ret[X] *= is_pos(v[X]); 
	ret[Y] *= is_pos(v[Y]); 
	ret[Z] *= is_pos(v[Z]);
	ret[X] += c[X];
	ret[Y] += c[Y];
	ret[Z] += c[Z];
}
