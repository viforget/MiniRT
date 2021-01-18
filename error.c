/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viforget <viforget@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/20 14:22:43 by viforget          #+#    #+#             */
/*   Updated: 2021/01/17 14:17:25 by viforget         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MiniRT.h"

void	del_obj(t_obj *obj)
{
	if (obj->next)
		del_obj(obj->next);
	free(obj);
}

void	del_cam(t_cam *cam)
{
	free(cam->disp);
	if (cam->next)
		del_cam(cam->next);
	free(cam);
}

void	del_lig(t_lig *lig)
{
	if (lig->next)
		del_lig(lig->next);
	free(lig);
}

int		get_error(t_arg arg, char **split, int err)
{
	if (arg.obj)
		del_obj(arg.obj);
	arg.obj = NULL;
	if (arg.cam)
		del_cam(arg.cam);
	arg.cam = NULL;
	if (arg.lig)
		del_lig(arg.lig);
	arg.lig = NULL;
	if (split)
		ft_freeutab(split);
	if (err == 0)
		ft_putstr("Error; problem with .rt file\n");
	else if (err == 1)
		ft_putstr("Error; file does not exit\n");
	return (0);
}
