/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arguments.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viforget <viforget@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/06 03:20:45 by viforget          #+#    #+#             */
/*   Updated: 2020/10/20 16:03:13 by viforget         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MiniRT.h"

t_arg	get_res(char **split, t_arg arg, int *a)
{
	arg.res_x = ft_atoi(split[1]);
	arg.res_y = ft_atoi(split[2]);
	if (!(arg.screen = ft_settab(arg.res_y, arg.res_x)))
		*a = 0;
	return (arg);
}

t_arg	get_amb(char **split, t_arg arg)
{
	arg.a_rat = ft_atof(split[1]);
	arg.a_color = get_color(split[2]);
	return (arg);
}

t_arg	bzero_arg(t_arg arg)
{
	arg.cam = NULL;
	arg.obj = NULL;
	arg.lig = NULL;
	arg.screen = NULL;
	return (arg);
}

t_arg	get_arg(char *file)
{
	t_arg	arg;
	int		a;
	int		fd;
	char	*str;
	char	**split;

	fd = open(file, O_RDONLY);
	arg = bzero_arg(arg);
	a = 0;
	while (get_next_line(fd, &str) && str)
	{
		split = ft_split(str, ' ');
		free (str);
		if (ft_strcmp(split[0], "R") == 0 && sizeof_tab(split) == 3)
			arg = get_res(split, arg, &a);
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
			arg = get_amb(split, arg);
		else
			return (get_error(arg, fd, split));
		if (a == 1)
			return (get_error(arg, fd, split));
		ft_freeutab(split);
	}
	return (arg);
}
