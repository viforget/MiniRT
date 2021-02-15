/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viforget <viforget@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/06 02:54:03 by viforget          #+#    #+#             */
/*   Updated: 2021/02/15 13:56:33 by viforget         ###   ########.fr       */
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
			display_screen(arg->mlx, arg, arg->cam);
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
			display_screen(arg->mlx, arg, arg->cam);
		}
	}
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
//	printf("bpp: %d\n size_l : %d\n endian: %d\n", mlx->bpp, mlx->size_l, mlx->endian);
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
	arg = get_arg(av);
	if (arg.cam == NULL)
		return (0); //CAS ERREUR ICI
	if (arg.save == 0)
		mlx_setup(&mlx, &arg, av[1]);
	calc_screen(mlx, &arg);
	arg.mlx = &mlx;
	if (arg.save == 0)
	{
		display_screen(&mlx, &arg, arg.cam);
		mlx_key_hook(mlx.win, input, &arg);
		mlx_hook(mlx.win, 17, (1L << 17), &quit, NULL);
		mlx_loop(mlx.mlx);
	}
	else
		bmp_save(arg);
	printf("B\n");
}
