/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viforget <viforget@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/06 02:54:03 by viforget          #+#    #+#             */
/*   Updated: 2021/01/11 15:19:45 by viforget         ###   ########.fr       */
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

int		main(int ac, char **av)
{
	int		i;
	t_arg	arg;
	t_mlx	mlx;

	if (ac < 2)
	{
		ft_putendl("Error: no file");
		return (0);
	}
	arg = get_arg(av[1]);
	if (arg.cam == NULL)
		return (0);
	mlx.mlx = mlx_init();
	mlx.win = mlx_new_window(mlx.mlx, arg.res_x, arg.res_y, av[1]);
	display_screen(mlx, arg, arg.cam);
	mlx_key_hook(mlx.win, input, &mlx);
	mlx_hook(mlx.win, 17, (1L << 17), &quit, NULL);
	mlx_loop(mlx.mlx);
}
