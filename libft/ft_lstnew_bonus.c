/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viforget <viforget@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 18:30:23 by viforget          #+#    #+#             */
/*   Updated: 2019/10/24 19:17:23 by viforget         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content)
{
	t_list *lst;

	if (!(lst = (t_list *)malloc(sizeof(t_list))))
		return (NULL);
	lst->content = (void *)content;
	lst->next = NULL;
	return (lst);
}
