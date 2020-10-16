/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arguments.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viforget <viforget@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/06 03:20:45 by viforget          #+#    #+#             */
/*   Updated: 2020/10/16 16:04:17 by viforget         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MiniRT.h"

t_arg	get_res(char **split, t_arg arg)
{
	arg.res_x = ft_atoi(split[1]);
	arg.res_y = ft_atoi(split[2]);
	arg.screen = ft_settab(arg.res_y, arg.res_x);
	return (arg);
}

/*
** TEMPORAIRE
*/ 

t_arg	get_cercle(char **split, t_arg arg)
{
	t_cercle	*cer;
	char		*str;
	int			color[3];

	str = split[4];
	cer = malloc(sizeof(t_cercle));
	cer->c[0] = ft_atoi(split[1]);
	cer->c[1] = ft_atoi(split[2]);
	cer->rad = ft_atoi(split[3]);
	color[0] = ft_atoi(split[4]);
	while (*str != ',')
		str++;
	str++;
	color[1] = ft_atoi(str);
	while (*str != ',')
		str++;
	str++;
	color[2] = ft_atoi(str);
	cer->color = color[0] * 0x10000 + color[1] * 0x100 + color [2];
	arg.list = cer;
	return (arg);
}

t_arg	get_arg(char *file)
{
	t_arg	arg;
	int 	fd;
	char 	*str;
	char	**split;

	fd = open(file, O_RDONLY);
	arg.list = NULL;
	while (get_next_line(fd, &str) && str)
	{
		split = ft_split(str, ' ');
		if (ft_strcmp(split[0], "R") == 0)
			arg = get_res(split, arg);
		else if (ft_strcmp(split[0], "cercle") == 0)
			arg = get_cercle(split, arg);
		ft_freeutab(split); 
	}
	return (arg);
}
