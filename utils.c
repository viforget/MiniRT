/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viforget <viforget@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/16 20:53:31 by viforget          #+#    #+#             */
/*   Updated: 2020/10/18 14:03:36 by viforget         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MiniRT.h"

float	ft_atof(char *str)
{
	float	nb;
	float	temp;

	nb = ft_atoi(str);
	while (*str && *str != '.')
		str++;
	temp = ft_atoi(str + 1);
	while (temp >= 1)
		temp /= 10;
	return (nb + temp);
}

void	coordinate(char *str, float c[3])
{
	c[0] = ft_atof(str);
	while (*str && *str != ',')
		str++;
	c[1] = ft_atof(++str);
	while (*str && *str != ',')
		str++;
	c[2] = ft_atof(++str);
}

int		get_color(char *str)
{
	char	**split;
	int		color;

	color = ft_atoi(str) * 0x10000;
	while (*str && *str != ',')
		str++;
	color += ft_atoi(++str) * 0x100;
	while (*str && *str != ',')
		str++;
	color += ft_atoi(++str);
	return (color);
}

t_obj	*add_object(t_obj *first, t_obj *obj)
{
	if (!first)
		return (obj);
	first->next = add_object(first->next, obj);
	return (first);
}

void	bzero_obj(t_obj *obj)
{
	obj->c0[0] = 0;
	obj->c0[1] = 0;
	obj->c0[2] = 0;
	obj->c1[0] = 0;
	obj->c1[1] = 0;
	obj->c1[2] = 0;
	obj->c2[0] = 0;
	obj->c2[1] = 0;
	obj->c2[2] = 0;
	obj->vec[0] = 0;
	obj->vec[1] = 0;
	obj->vec[2] = 0;
	obj->type = 0;
	obj->dia = 0;
	obj->hight = 0;
	obj->next = NULL;
}
