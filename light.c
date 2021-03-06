/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viforget <viforget@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/18 13:22:55 by viforget          #+#    #+#             */
/*   Updated: 2021/02/24 13:43:59 by viforget         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int		verif(float dist_obj, float dist_light)
{
	if (dist_obj <= ZE || dist_obj - ZE > dist_light)
		return (0);
	if (dist_obj != dist_obj)
		return (0);
	return (1);
}

int		calc_light(float c[3], t_arg arg, t_obj *obj, char check)
{
	t_lig	*light;
	t_obj	*cobj;
	float	v[3];
	float	r_c[3];
	double	dist;

	bzero_vect(r_c);
	intens_add(r_c, arg.a_color, arg.a_rat, obj->color);
	light = arg.lig;
	while (light)
	{
		vect_to(c, light->c, v, &dist);
		cobj = arg.obj;
		check = 1;
		while (cobj && check == 1)
			if (verif(dist_obj(cobj, v, c), dist))
				check = 0;
			else
				cobj = cobj->next;
		if (check == 1)
			intens_add(r_c, light->color, rat_ang(c, v, obj)
					* light->rat, obj->color);
		light = light->next;
	}
	return (v_to_color(r_c));
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
