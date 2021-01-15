/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viforget <viforget@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/06 02:54:03 by viforget          #+#    #+#             */
/*   Updated: 2021/01/15 15:57:46 by viforget         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MiniRT.h"

int		quit()
{
	ft_putstr("BYE BYE\n");
	exit(0);
}

int 	input(int key_in, t_arg *arg)
{
	t_cam	*cam;
	t_cam	*cam2;

	if (key_in == 0x35)
		quit();
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
			ft_memccpy(arg->mlx->disp, arg->cam->disp, -1, arg->res_x * arg->res_y * 4);
			mlx_put_image_to_window(arg->mlx->mlx, arg->mlx->win, arg->mlx->img, 0, 0);
		}
	}	
	else if (key_in == 0x7c)
	{
		cam2 = arg->cam->next;
		if (cam2 != NULL)
		{
			cam = p_last_cam(arg->cam)->next;
			cam->next = arg->cam;
			arg->cam->next = NULL;
			arg->cam = cam2;
			ft_memccpy(arg->mlx->disp, arg->cam->disp, -1, arg->res_x * arg->res_y * 4);
			mlx_put_image_to_window(arg->mlx->mlx, arg->mlx->win, arg->mlx->img, 0, 0);
		}
	}
	return (0);
}

void	mlx_setup(t_mlx *mlx, t_arg arg, char *title)
{
	mlx->mlx = mlx_init();
	mlx->win = mlx_new_window(mlx->mlx, arg.res_x, arg.res_y, title);
	mlx->img = mlx_new_image(mlx->mlx, arg.res_x, arg.res_y);
	mlx->disp = (int *)mlx_get_data_addr(mlx->img, &mlx->bpp,
		&mlx->size_l, &mlx->endian);
	//printf("bpp: %d\n size_l : %d\n endian: %d\n", mlx->bpp, mlx->size_l, mlx->endian);
}

void	calc_screens(t_mlx mlx, t_arg arg)
{
	t_cam *cam;

	cam = arg.cam;
	while (cam)
	{
		display_screen(mlx, arg, cam);
		cam = cam->next;
	}
}

int		main(int ac, char **av)
{
	int		i;
	t_arg	arg;
	t_mlx	mlx;
	int		key;

	if (ac < 2)
	{
		ft_putendl("Error: no file");
		return (0);
	}
	arg = get_arg(av[1]);
	if (arg.cam == NULL)
		return (0);
	mlx_setup(&mlx, arg, av[1]);
	calc_screens(mlx, arg);
	arg.mlx = &mlx;

	ft_memccpy(mlx.disp, arg.cam->disp, -1, arg.res_x * arg.res_y * 4);
	mlx_put_image_to_window(mlx.mlx, mlx.win, mlx.img, 0, 0);

	mlx_key_hook(mlx.win, input, &arg);
	mlx_hook(mlx.win, 17, (1L << 17), &quit, NULL);
	mlx_loop(mlx.mlx);
}
