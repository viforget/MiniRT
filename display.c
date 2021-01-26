/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viforget <viforget@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 13:37:14 by viforget          #+#    #+#             */
/*   Updated: 2021/01/26 17:15:55 by viforget         ###   ########.fr       */
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
	ft_memccpy(mlx->disp, cam->disp, -1, arg->res_x * arg->res_y * sizeof(int));
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img, 0, 0);
}

void	*thread_start(void *tmp)
{
	t_arg	*arg;
	int		x;
	int		y;
	float	v[3];
	float	t[3];
	int 	color;

	arg = (t_arg*)tmp;
	while (arg->cam)
	{
		x = arg->th * arg->res_x / NB_THREAD;
		while (x  < (arg->th + 1) * arg->res_x / NB_THREAD)
		{
			y = 0;
			while (y   < arg->res_y)
			{
				rhor(arg->cam->vec, calc_angle_x(arg->cam->fov, arg->res_x, x), t);
				rver(t, calc_angle_y(arg->cam->fov, arg->res_x, y - (arg->res_y / 2)), v);
				call_pixel(*arg, v, arg->cam->c, &color);
				//call_pixel(*arg, arg->cam->vec, arg->cam->c, &color);
				arg->cam->disp[y * arg->res_x + x] = color;
				y++;
			}
			x++;
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
		//tmp[i] = arg;
		tmp[i]->th = i;
		if (pthread_create(&th[i], NULL, thread_start, (void *)tmp[i]))
		{
			ft_putendl("error with pthread_create");
			exit(0);
		}
		i++;
	}
	while (i--)
		if (pthread_join(th[i], NULL))
		{
			ft_putendl("error joining thread");
			exit(0);
		}
}

/*void	display_screen(t_mlx mlx, t_arg arg, t_cam *cam)
{
	int		c[2];
	float	v[3];
	float	t[3];
	int		color;
	int		*display;

	c[Y] = 0;
	while (c[Y] < arg.res_y)
	{
		c[X] = 0;
		while (c[X] < arg.res_x)
		{
			rhor(cam->vec, calc_angle_x(cam->fov, arg.res_x, c[X]), t);
			rver(t, calc_angle_y(cam->fov, arg.res_x, c[Y] - (arg.res_y / 2)),
					v);
			call_pixel(arg, v, cam->c, &color);
			cam->disp[c[Y] * arg.res_x + c[X]] = color;
			c[X]++;
		}
		c[Y]++;
	}
}*/
