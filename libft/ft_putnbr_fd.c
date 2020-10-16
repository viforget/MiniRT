/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viforget <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/12 02:50:01 by viforget          #+#    #+#             */
/*   Updated: 2020/01/12 15:44:04 by viforget         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	if (n < 0)
		ft_putchar_fd('-', fd);
	else
		n = -n;
	if (n <= -10)
	{
		ft_putnbr_fd((n / 10) * -1, fd);
	}
	ft_putchar_fd(((n % 10) * -1) + '0', fd);
}

void	ft_putnbr(int n)
{
	if (n < 0)
		ft_putchar('-');
	else
		n = -n;
	if (n <= -10)
	{
		ft_putnbr((n / 10) * -1);
	}
	ft_putchar(((n % 10) * -1) + '0');
}
