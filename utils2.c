/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viforget <viforget@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/18 12:33:04 by viforget          #+#    #+#             */
/*   Updated: 2021/01/16 17:03:02 by viforget         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MiniRT.h"

t_cam	*add_cam(t_cam *first, t_cam *cam)
{
	if (!first)
		return (cam);
	first->next = add_cam(first->next, cam);
	return (first);
}

t_lig	*add_lig(t_lig *first, t_lig *lig)
{
	if (!first)
		return (lig);
	first->next = add_lig(first->next, lig);
	return (first);
}

int		sizeof_tab(char **tab)
{
	int i;

	i = 0;
	if (!tab)
		return (0);
	while (tab[i])
		i++;
	return (i);
}

float	radian(float angle)
{
	return (angle * ((float)M_PI / 180));
}

int		light_color(int color, float intensity, int light)
{
	int		col[3];
	float	lig[3];

	lig[RED] = (light / 0x10000 * intensity) / 255;
	lig[GREEN] = (((light / 0x100) % 0x100) * intensity) / 255;
	lig[BLUE] = (light % 0x100 * intensity) / 255;
	col[RED] = (color / 0x10000) * lig[RED];
	col[GREEN] = ((color / 0x100) % 0x100) * lig[GREEN];
	col[BLUE] = (color % 0x100) * lig[BLUE];
	return (col[RED] * 0x10000 + col[GREEN] * 0x100 + col[BLUE]);
}
