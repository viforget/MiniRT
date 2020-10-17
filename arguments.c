/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arguments.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viforget <viforget@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/06 03:20:45 by viforget          #+#    #+#             */
/*   Updated: 2020/10/17 19:27:08 by viforget         ###   ########.fr       */
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


t_arg	get_arg(char *file)
{
	t_arg	arg;
	int 	fd;
	char 	*str;
	char	**split;

	fd = open(file, O_RDONLY);
	arg.obj = NULL;
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
		ft_freeutab(split); 
	}
	return (arg);
}
