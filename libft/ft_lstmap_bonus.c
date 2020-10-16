/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viforget <viforget@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 08:34:14 by viforget          #+#    #+#             */
/*   Updated: 2019/11/10 16:54:53 by viforget         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
**{
**	t_list	*maillon_un;
**	t_list	*liste;
**
**	if (!lst || !f)
**		return (NULL);
**	maillon_un = f(lst);
**	liste = maillon_un;
**	while (lst->next)
**	{
**		lst = lst->next;
**		if (!(liste->next = f(lst)))
**		{
**			return (NULL);
**		}
**		liste = liste->next;
**	}
**	return (maillon_un);
**}
*/

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list *alst;

	if (!lst || !del)
		return (NULL);
	if (!f)
		return (lst);
	if (!(alst = ft_lstnew(f(lst->content))))
		return (NULL);
	if (lst->next)
	{
		if (!(alst->next = ft_lstmap(lst->next, f, del)))
		{
			ft_lstdelone(lst, del);
			return (NULL);
		}
	}
	else
		alst->next = NULL;
	return (alst);
}
