/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viforget <viforget@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 13:37:14 by viforget          #+#    #+#             */
/*   Updated: 2021/02/18 13:25:49 by viforget         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MiniRT.h"

void	setup_call_pixel(t_obj *obj, float *d, int *c)
{
	obj = NULL;
	*d = -1;
	*c = 0;
}

int		call_pixel(t_arg arg, float v[3], float p[3], int *color)
{
	t_obj	*cobj;
	float	temp[3];
	float	dist;
	float	buf;
	t_obj	*obj;

	cobj = arg.obj;
	setup_call_pixel(obj, &dist, color);
	while (cobj)
	{
		buf = dist_obj(cobj, v, p);
		if (buf >= 0 && (buf < dist || dist == -1))
		{
			dist = buf;
			obj = cobj;
		}
		cobj = cobj->next;
	}
	if (dist > ZE)
	{
		calc_coord(p, v, dist, temp);
		*color = calc_light(temp, arg, obj, 1);
	}
	return (*color);
}

void	display_screen(t_mlx *mlx, t_arg *arg, t_cam *cam)
{
	ft_memcpy(mlx->disp, cam->disp, arg->res_x * arg->res_y * sizeof(int));
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img, 0, 0);
}

void	*thread_start(void *tmp)
{
	t_arg	*arg;
	long	c[2];
	float	v[3];
	int		color;

	arg = (t_arg *)tmp;
	while (arg->cam)
	{
		c[0] = (arg->res_x / NB_THREAD) * arg->th;
		while (c[0] < (arg->th + 1) * arg->res_x / NB_THREAD)
		{
			c[1] = 0;
			while (c[1] < arg->res_y)
			{
				rot_fov(arg, v, c[0], c[1]);
				call_pixel(*arg, v, arg->cam->c, &color);
				arg->cam->disp[c[1] * arg->res_x + c[0]] = color;
				c[1]++;
			}
			c[0]++;
		}
		arg->cam = arg->cam->next;
	}
	free(tmp);
	pthread_exit(NULL);
}

void	calc_screen(t_mlx mlx, t_arg *arg)
{
	pthread_t	th[NB_THREAD];
	t_arg		*tmp[NB_THREAD];
	int			i;

	i = 0;
	while (i < NB_THREAD)
	{
		tmp[i] = malloc(sizeof(t_arg));
		ft_memcpy((void*)tmp[i], (void*)arg, sizeof(t_arg));
		tmp[i]->th = i;
		if (pthread_create(&th[i], NULL, thread_start, (void *)tmp[i]))
			get_error(*arg, NULL, 2);
		i++;
	}
	while (i--)
		if (pthread_join(th[i], NULL))
			get_error(*arg, NULL, 2);
}
