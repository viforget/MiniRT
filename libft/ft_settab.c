/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_settab.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viforget <viforget@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/15 23:17:32 by viforget          #+#    #+#             */
/*   Updated: 2021/02/23 12:38:13 by viforget         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_settab(int x, int y)
{
	int		i;
	char	**tab;

	i = 0;
	if (!(tab = calloc(sizeof(char *), x + 1)))
		return (NULL);
	while (i < x)
	{
		if (!(tab[i] = calloc(sizeof(char), y + 1)))
			return (NULL);
		i++;
	}
	tab[x] = NULL;
	return (tab);
}
