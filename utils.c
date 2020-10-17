/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viforget <viforget@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/16 20:53:31 by viforget          #+#    #+#             */
/*   Updated: 2020/10/17 18:19:35 by viforget         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MiniRT.h"

float	ft_atof(char *str)
{
	float	 nb;
	float 	temp;

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
	int 	color;

	color = ft_atoi(str) * 0x10000;
	while(*str && *str != ',')
		str++;
	color += ft_atoi(++str) * 0x100;
	while(*str && *str != ',')
		str++;
	color += ft_atoi(++str);
	return (color);
}

t_obj	* add_object(t_obj * first, t_obj * obj)
{
	if (!first)
		return(obj);
	first->next = add_object(first->next, obj);
	return (first);
}
