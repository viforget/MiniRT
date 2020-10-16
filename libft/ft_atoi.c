/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viforget <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/09 12:11:43 by viforget          #+#    #+#             */
/*   Updated: 2020/02/28 15:05:30 by viforget         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	check_sp(char c)
{
	if (c == ' ' || c == '\t' || c == '\v' || c == '\n' ||
			c == '\r' || c == '\f')
		return (1);
	return (0);
}

int			ft_atoi(const char *str)
{
	int		a;
	long	nb;
	char	neg;

	a = 0;
	nb = 0;
	neg = 0;
	while (check_sp(str[a]))
		a++;
	if (str[a] == '-')
		neg = 1;
	if (str[a] == '-' || str[a] == '+')
		a++;
	while ((str[a] >= '0') && (str[a] <= '9'))
	{
		if ((unsigned long)nb * 10 + (str[a] - '0')
				> (unsigned long)(LONG_MAX + neg))
			return (neg ? 0 : -1);
		nb *= 10;
		nb += ((int)str[a] - '0');
		a++;
	}
	if (neg == 1)
		return (-nb);
	return (nb);
}
