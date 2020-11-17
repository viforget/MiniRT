/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viforget <viforget@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/18 12:26:37 by viforget          #+#    #+#             */
/*   Updated: 2020/11/16 11:16:40 by viforget         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MiniRT.h"

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

	if (!(cam = malloc(sizeof(t_cam))))
		return (0);
	bzero_cam(cam);
	coordinate(split[1], cam->c);
	coordinate(split[2], cam->vec);
	normalize_vect(cam->vec);
	cam->fov = ft_atoi(split[3]);
	arg->cam = add_cam(arg->cam, cam);
	return (1);
}
