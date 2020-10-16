/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viforget <viforget@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 21:51:09 by viforget          #+#    #+#             */
/*   Updated: 2019/10/24 19:11:09 by viforget         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **alst, t_list *new)
{
	t_list *lst;

	if (alst != NULL)
	{
		lst = *alst;
		if (lst != NULL)
		{
			while (lst->next)
				lst = lst->next;
			lst->next = new;
		}
		else
			*alst = new;
	}
}
