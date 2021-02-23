/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_function.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viforget <viforget@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/17 13:36:12 by viforget          #+#    #+#             */
/*   Updated: 2021/02/18 12:18:59 by viforget         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MiniRT.h"

int		quit(void *tmp)
{
	t_arg *arg;

	arg = (t_arg *)tmp;
	ft_putstr("BYE BYE\n");
	del_arg(*arg);
	exit(0);
}

void	next_cam(t_arg *arg)
{
	t_cam	*cam;
	t_cam	*cam2;

	cam2 = arg->cam->next;
	if (cam2 != NULL)
	{
		cam = p_last_cam(arg->cam)->next;
		cam->next = arg->cam;
		arg->cam->next = NULL;
		arg->cam = cam2;
		display_screen(arg->mlx, arg, arg->cam);
	}
}

int		input(int key_in, t_arg *arg)
{
	t_cam	*cam;
	t_cam	*cam2;

	if (key_in == 0x35)
		quit(arg);
	else if (key_in == 0x7b)
	{
		cam = arg->cam;
		cam2 = p_last_cam(arg->cam);
		if (cam2->next)
		{
			cam = arg->cam;
			arg->cam = cam2->next;
			arg->cam->next = cam;
			cam2->next = NULL;
			display_screen(arg->mlx, arg, arg->cam);
		}
	}
	else if (key_in == 0x7c)
		next_cam(arg);
	return (0);
}

void	mlx_setup(t_mlx *mlx, t_arg *arg, char *title)
{
	int x;
	int y;

	mlx->mlx = mlx_init();
	mlx_get_screen_size(mlx->mlx, &x, &y);
	if (arg->res_x > x)
		arg->res_x = x;
	if (arg->res_y > y)
		arg->res_y = y;
	mlx->win = mlx_new_window(mlx->mlx, arg->res_x, arg->res_y, title);
	mlx->img = mlx_new_image(mlx->mlx, arg->res_x, arg->res_y);
	mlx->disp = (int *)mlx_get_data_addr(mlx->img, &mlx->bpp,
		&mlx->size_l, &mlx->endian);
}

void	mlx_loop_aff(t_arg arg, t_mlx mlx)
{
	display_screen(&mlx, &arg, arg.cam);
	mlx_key_hook(mlx.win, input, &arg);
	mlx_hook(mlx.win, 17, (1L << 17), &quit, (void *)&arg);
	mlx_loop(mlx.mlx);
}
