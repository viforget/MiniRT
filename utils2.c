/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viforget <viforget@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/18 12:33:04 by viforget          #+#    #+#             */
/*   Updated: 2020/11/10 13:27:44 by viforget         ###   ########.fr       */
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

	while (tab[i])
		i++;
	return (i);
}

float	radian(float angle)
{
	return (angle * (M_PI / 180));
}
