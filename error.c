/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viforget <viforget@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/20 14:22:43 by viforget          #+#    #+#             */
/*   Updated: 2020/10/20 14:34:20 by viforget         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	del_obj(t_obj *obj)
{
	if (obj->next)
		del_obj(obj->next);
	free (obj);
}

void	del_cam(t_cam *cam)
{
	if (cam->next)
		del_cam(cam->next);
	free (cam);
}

void	del_lig(t_lig *lig)
{
	if (lig->next)
		del_lig(lig->next);
	free (lig);
}

t_arg	get_error(t_arg arg, int fd, char **split)
{
	if (arg.screen)
		ft_freeutab(arg.screen);
	if (arg.obj)
		del_obj(arg.obj);
	if (arg.cam)
		del_cam(arg.cam);
	if (arg.lig)
		del_lig(arg.lig);
	ft_freeutab(split);
	close(fd);
	ft_putstr("Error; problem with .rt file\n");
	return (NULL);
}

