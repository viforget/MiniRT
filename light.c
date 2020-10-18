/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viforget <viforget@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/18 13:22:55 by viforget          #+#    #+#             */
/*   Updated: 2020/10/18 13:50:33 by viforget         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MiniRT.h"

void	bzero_lig(t_lig *lig)
{
	lig->c[0] = 0;
	lig->c[1] = 0;
	lig->c[2] = 0;
	lig->rat = 0;
	lig->color = 0;
	lig->next = NULL;
}

void	get_lig(char **split, t_arg arg)
{
	t_lig *lig;

	lig = malloc(sizeof(t_lig));
	bzero_lig(lig);
	coordinate(split[1], lig->c);
	lig->rat = ft_atof(split[2]);
	lig->color = get_color(split[3]);
	arg.lig = add_lig(arg.lig, lig);
	printf("-----\nc:  %f %f %f\nrat: %f\ncolor: %X\n-----\n", lig->c[0], lig->c[1], lig->c[2], lig->rat, lig->color);
}
