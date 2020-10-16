/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viforget <viforget@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/03 07:08:42 by viforget          #+#    #+#             */
/*   Updated: 2020/02/04 06:54:07 by viforget         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size, char c)
{
	char	*s;

	s = malloc(size + 1 * sizeof(char));
	ft_memset(s, c, size);
	s[size] = 0;
	return (s);
}
