/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bmp.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viforget <viforget@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/17 14:07:59 by viforget          #+#    #+#             */
/*   Updated: 2021/01/18 11:35:58 by viforget         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MiniRT.h"

void	fill_map(t_arg arg, int *img, int fd)
{
	int	x;
	int y;
	int	i;
	int	*body;

	body = malloc(arg.res_y * arg.res_x * 4);
	y = arg.res_y - 1;
	i = 0;
	while (y >= 0)
	{
		x = 0;
		while (x < arg.res_x)
		{
			body[i++] = img[y * arg.res_x + x];
			x++;
		}
		y--;
	}
	write(fd, body, arg.res_y * arg.res_x * 4);
}

void	bmp_save(t_arg arg)
{
	int				size;
	unsigned char	*head;
	char			*name;
	int				fd;

	head = ft_calloc(54, 1);
	name = ft_strjoin(arg.name, ".bmp");
	fd = open(name, O_CREAT | O_WRONLY, S_IWUSR | S_IRUSR | S_IRGRP | S_IROTH);
	size = 54 + arg.res_y * arg.res_x * 4;
	ft_memcpy(head, "BM", 2);
	ft_memcpy(head + 2, &size, 4);
	ft_memcpy(head + 10, "6\0\0\0", 4);
	ft_memcpy(head + 14, "(\0\0\0", 4);
	ft_memcpy(head + 18, &arg.res_x, 4);
	ft_memcpy(head + 22, &arg.res_y, 4);
	ft_memcpy(head + 26, "\1\0\0\0", 2);
	ft_memcpy(head + 28, " \0", 2);
	size = arg.res_y * arg.res_x;
	ft_memcpy(head + 34, &size, 4);
	write(fd, head, 54);
	fill_map(arg, arg.cam->disp, fd);
	free(head);
	close(fd);
}
