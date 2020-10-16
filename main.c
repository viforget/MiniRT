/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viforget <viforget@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/16 15:40:26 by viforget          #+#    #+#             */
/*   Updated: 2020/10/16 15:42:47 by viforget         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viforget <viforget@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/06 02:54:03 by viforget          #+#    #+#             */
/*   Updated: 2020/10/16 15:37:58 by viforget         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/MiniRT.h"
#include <math.h>

void	aff(t_mlx mlx, t_arg arg)
{
	int 		x;
	int 		y;
	t_cercle	*cer;

	cer = arg.list;
	printf("%d\n", arg.res_y);
	y = 0;
	printf("%x\n", cer->color);
	while (y < arg.res_y)
	{
		x = 0;
		while (x < arg.res_x)
		{
			if (pow(x - cer->x, 2) + pow(y - cer->y, 2) <= pow(cer->rad, 2))
				mlx_pixel_put(mlx.mlx, mlx.win, x, y, cer->color);
			x++;
		}
		y++;
	}
}

int		 main(int ac, char **av)
{
	int		i;
	t_arg	arg;
	t_mlx	mlx;

	if (ac < 2)
		return (0);
	arg = get_arg(av[1]);
	mlx.mlx = mlx_init();
	mlx.win = mlx_new_window(mlx.mlx, arg.res_x, arg.res_y, av[1]);
	aff(mlx, arg);
	mlx_loop(mlx.mlx);
}
