/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viforget <viforget@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/18 12:26:37 by viforget          #+#    #+#             */
/*   Updated: 2021/02/18 13:12:09 by viforget         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MiniRT.h"

t_cam	*p_last_cam(t_cam *cam)
{
	if (!cam)
		return (NULL);
	if (!cam->next || !cam->next->next)
	{
		return (cam);
	}
	return (p_last_cam(cam->next));
}

t_arg	bzero_arg(t_arg arg)
{
	arg.th = -1;
	arg.cam = NULL;
	arg.obj = NULL;
	arg.lig = NULL;
	arg.name = NULL;
	arg.a_check = 0;
	arg.res_x = 0;
	arg.res_y = 0;
	return (arg);
}

void	bzero_cam(t_cam *cam)
{
	cam->c[0] = 0;
	cam->c[1] = 0;
	cam->c[2] = 0;
	cam->vec[0] = 0;
	cam->vec[1] = 0;
	cam->vec[2] = 0;
	cam->fov = 0;
	cam->next = NULL;
}

int		get_cam(char **split, t_arg *arg)
{
	t_cam *cam;

	if (arg->save == 0 || arg->cam == NULL)
	{
		if (!(cam = malloc(sizeof(t_cam))))
			return (0);
		bzero_cam(cam);
		coordinate(split[1], cam->c);
		cam->disp = ft_calloc(arg->res_x * arg->res_y, sizeof(int));
		coordinate(split[2], cam->vec);
		normalize_vect(cam->vec);
		cam->fov = ft_atoi(split[3]);
		arg->cam = add_cam(arg->cam, cam);
	}
	return (1);
}
