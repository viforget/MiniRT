/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viforget <viforget@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/06 02:54:03 by viforget          #+#    #+#             */
/*   Updated: 2021/02/23 12:10:45 by viforget         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MiniRT.h"

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
		get_error(arg, NULL, 0);
	if (arg.save == 0)
		mlx_setup(&mlx, &arg, av[1]);
	calc_screen(mlx, &arg);
	arg.mlx = &mlx;
	if (arg.save == 0)
		mlx_loop_aff(arg, mlx);
	else
		bmp_save(arg);
}
