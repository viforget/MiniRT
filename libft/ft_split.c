/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viforget <viforget@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 19:46:49 by viforget          #+#    #+#             */
/*   Updated: 2019/11/09 23:39:46 by viforget         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	void	ft_freedom(char **tab, int i)
{
	while (i > 0)
	{
		i--;
		free(tab[i]);
	}
	free(tab);
}

static	int		count_w(const char *s, char c)
{
	int		ct;
	int		page;

	page = 0;
	ct = 0;
	while (*s != '\0')
	{
		if (page == 1 && *s == c)
			page = 0;
		if (page == 0 && *s != c)
		{
			page = 1;
			ct++;
		}
		s++;
	}
	return (ct);
}

static	int		ft_wlen(const char *s, char c)
{
	int	len;

	len = 0;
	while (s[len] != c && s[len] != '\0')
		len++;
	return (len);
}

char			**ft_split(char const *s, char c)
{
	char	**t;
	int		nb_word;
	int		i;

	i = 0;
	if (!s)
		return (NULL);
	nb_word = count_w((const char *)s, c);
	if (!(t = (char **)malloc(sizeof(*t) * (nb_word + 1))))
		return (NULL);
	while (nb_word--)
	{
		while (*s == c && *s != '\0')
			s++;
		t[i] = ft_substr((const char *)s, 0, ft_wlen((const char *)s, c));
		if (t[i] == NULL)
		{
			ft_freedom(t, i);
			return (NULL);
		}
		s = s + ft_wlen(s, c);
		i++;
	}
	t[i] = NULL;
	return (t);
}
