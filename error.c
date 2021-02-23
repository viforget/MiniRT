/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viforget <viforget@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/20 14:22:43 by viforget          #+#    #+#             */
/*   Updated: 2021/02/23 12:10:26 by viforget         ###   ########.fr       */
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
	cam->disp = NULL;
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

void	del_arg(t_arg arg)
{
	if (arg.obj)
		del_obj(arg.obj);
	if (arg.cam)
		del_cam(arg.cam);
	if (arg.lig)
		del_lig(arg.lig);
	if (arg.mlx)
	{
		if (arg.mlx->img)
			mlx_destroy_image(arg.mlx->mlx, arg.mlx->img);
		if (arg.mlx->win)
			mlx_destroy_window(arg.mlx->mlx, arg.mlx->win);
	}
}

int		get_error(t_arg arg, char **split, int err)
{
	del_arg(arg);
	if (split)
		ft_freeutab(split);
	if (err == 0)
		ft_putstr("Error; problem with .rt file\n");
	else if (err == 1)
		ft_putstr("Error; file does not exit\n");
	else if (err == 2)
		ft_putstr("Error; unknown problem with thread\n");
	exit(0);
}
