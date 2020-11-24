/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viforget <viforget@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/06 02:54:03 by viforget          #+#    #+#             */
/*   Updated: 2020/11/24 09:45:06 by viforget         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MiniRT.h"

int		 main(int ac, char **av)
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
	mlx_loop(mlx.mlx);
}
