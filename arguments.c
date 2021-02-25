/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arguments.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viforget <viforget@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/06 03:20:45 by viforget          #+#    #+#             */
/*   Updated: 2021/02/25 11:24:47 by viforget         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_arg	get_res(char **split, t_arg arg, int *a)
{
	if (arg.res_x != 0 || arg.res_y != 0)
	{
		*a = 0;
		return (arg);
	}
	arg.res_x = abs(ft_atoi(split[1]));
	arg.res_y = abs(ft_atoi(split[2]));
	if (arg.res_x < 1 || arg.res_y < 1)
		*a = 0;
	else
		*a = 1;
	return (arg);
}

t_arg	get_amb(char **split, t_arg arg, int *a)
{
	if (arg.a_check == 1)
		*a = 0;
	else
		*a = 1;
	arg.a_rat = ft_atof(split[1]);
	arg.a_color = get_color(split[2]);
	arg.a_check = 1;
	return (arg);
}

int		do_line(char **split, t_arg *arg, int a)
{
	if (sizeof_tab(split) == 0)
		a = 1;
	else if (ft_strcmp(split[0], "R") == 0 && sizeof_tab(split) == 3)
		*arg = get_res(split, *arg, &a);
	else if (ft_strcmp(split[0], "sp") == 0 && sizeof_tab(split) == 4)
		a = get_sp(split, arg);
	else if (ft_strcmp(split[0], "pl") == 0 && sizeof_tab(split) == 4)
		a = get_pl(split, arg);
	else if (ft_strcmp(split[0], "sq") == 0 && sizeof_tab(split) == 5)
		a = get_sq(split, arg);
	else if (ft_strcmp(split[0], "cy") == 0 && sizeof_tab(split) == 6)
		a = get_cy(split, arg);
	else if (ft_strcmp(split[0], "tr") == 0 && sizeof_tab(split) == 5)
		a = get_tr(split, arg);
	else if (ft_strcmp(split[0], "c") == 0 && sizeof_tab(split) == 4)
		a = get_cam(split, arg);
	else if (ft_strcmp(split[0], "l") == 0 && sizeof_tab(split) == 4)
		a = get_lig(split, arg);
	else if (ft_strcmp(split[0], "A") == 0 && sizeof_tab(split) == 3)
		*arg = get_amb(split, *arg, &a);
	if (a == 0)
		return (get_error(*arg, split, 0));
	ft_freeutab(split);
	return (1);
}

void	boucle_arg(t_arg *arg, int fd)
{
	char	*str;
	int		i;

	while (get_next_line(fd, &str) && str)
	{
		i = -1;
		while (str[++i])
			if (str[i] == '\t')
				str[i] = ' ';
		if (do_line(ft_split(str, ' '), arg, 0) == 0)
		{
			close(fd);
			return ;
		}
		free(str);
	}
}

t_arg	get_arg(char **file)
{
	t_arg	arg;
	int		fd;

	arg = bzero_arg(arg);
	if (file[2] && ft_strcmp(file[2], "-save") == 0)
		arg.save = 1;
	if (file[3])
		arg.name = file[3];
	else
		arg.name = file[1];
	fd = open(file[1], O_RDONLY);
	if (fd < 0)
	{
		get_error(arg, NULL, 1);
		return (arg);
	}
	boucle_arg(&arg, fd);
	close(fd);
	return (arg);
}
