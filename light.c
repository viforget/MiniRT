/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viforget <viforget@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/18 13:22:55 by viforget          #+#    #+#             */
/*   Updated: 2020/11/24 12:30:23 by viforget         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MiniRT.h"

int		verif(float dist_obj, float dist_light)
{
	if (dist_obj == -1 || dist_obj - ZE > dist_light)
		return (0);
	return (1);
}

int		calc_light(float c[3], int color, t_arg arg, float ct[3])
{
	t_lig	*light;
	t_obj	*obj;
	char	check;
	float	v[3];
	float	r_col[3];
	double	dist;

	bzero_vect(r_col);
	intens_add(r_col, arg.a_color, arg.a_rat, color);
	light = arg.lig;
	while(light)
	{
		vect_to(c, light->c, v, &dist);
		obj = arg.obj;
		check = 1;
		while(obj && check == 1)
		{
			afv("v", v);
			if (verif(dist_obj(obj, v, c), dist))
				check = 0;
			obj = obj->next;
		}
		if (check == 1)
		{
			//printf("%f\n", rat_ang(c, ct, v) * light->rat);
			intens_add(r_col, light->color, rat_ang(c, ct, v) * light->rat, color);
		}
		light = light->next;
	}
	return (v_to_color(r_col));
}

void	bzero_lig(t_lig *lig)
{
	lig->c[0] = 0;
	lig->c[1] = 0;
	lig->c[2] = 0;
	lig->rat = 0;
	lig->color = 0;
	lig->next = NULL;
}

int		get_lig(char **split, t_arg *arg)
{
	t_lig *lig;

	if (!(lig = malloc(sizeof(t_lig))))
		return (0);
	bzero_lig(lig);
	coordinate(split[1], lig->c);
	lig->rat = ft_atof(split[2]);
	lig->color = get_color(split[3]);
	arg->lig = add_lig(arg->lig, lig);
	return (1);
}
