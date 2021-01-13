/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viforget <viforget@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/06 02:54:03 by viforget          #+#    #+#             */
/*   Updated: 2021/01/13 17:35:52 by viforget         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MiniRT.h"

int		quit()
{
	printf("BYE BYE\n");
	exit(0);
}

int 	input(int key_in, int *ret)
{
	if (key_in == 0x35)
		quit();
	else if (key_in == 0x7b)
		*ret = PREV;	
	else if (key_in == 0x7c)
		*ret = NEXT;	
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
	display_screen(mlx, arg, arg.cam);
	mlx_key_hook(mlx.win, input, &mlx);
	mlx_hook(mlx.win, 17, (1L << 17), &quit, NULL);
	mlx_loop(mlx.mlx);
}
