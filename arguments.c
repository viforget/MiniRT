/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arguments.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viforget <viforget@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/06 03:20:45 by viforget          #+#    #+#             */
/*   Updated: 2020/10/18 13:56:36 by viforget         ###   ########.fr       */
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

t_arg	get_amb(char **split, t_arg arg)
{
	arg.a_rat = ft_atof(split[1]);
	arg.a_color = get_color(split[2]);
	return (arg);
}

t_arg	get_arg(char *file)
{
	t_arg	arg;
	int 	fd;
	char 	*str;
	char	**split;

	fd = open(file, O_RDONLY);
	arg.cam = NULL;
	arg.obj = NULL;
	arg.lig = NULL;
	while (get_next_line(fd, &str) && str)
	{
		split = ft_split(str, ' ');
		if (ft_strcmp(split[0], "R") == 0)
			arg = get_res(split, arg);
		else if (ft_strcmp(split[0], "sp") == 0)
			get_sp(split, arg);
		else if (ft_strcmp(split[0], "pl") == 0)
			get_pl(split, arg);
		else if (ft_strcmp(split[0], "sq") == 0)
			get_sq(split, arg);
		else if (ft_strcmp(split[0], "cy") == 0)
			get_cy(split, arg);
		else if (ft_strcmp(split[0], "tr") == 0)
			get_tr(split, arg);
		else if (ft_strcmp(split[0], "c") == 0)
			get_cam(split, arg);
		else if (ft_strcmp(split[0], "l") == 0)
			get_lig(split, arg);
		else if (ft_strcmp(split[0], "A") == 0)
			arg = get_amb(split, arg);
		ft_freeutab(split); 
	}
	return (arg);
}
