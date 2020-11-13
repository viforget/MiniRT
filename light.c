/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viforget <viforget@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/18 13:22:55 by viforget          #+#    #+#             */
/*   Updated: 2020/11/11 18:17:39 by viforget         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MiniRT.h"

int		verif(float dist_obj, float dist_light)
{
	if (dist_obj == -1 || dist_obj - ZE > dist_light)
		return (0);
	return (1);
}

int		calc_light(float c[3], int color, t_arg arg)
{
	t_lig	*light;
	t_obj	*obj;
	char	check;
	float	v[3];
	int 	ret;
	float	dist;
	
	ret = light_color(color, arg.a_rat, arg.a_color);
	light = arg.lig;
	while(light)
	{
		vect_to(c, light->c, v, &dist);
		obj = arg.obj;
		check = 1;
		while(obj && check == 1)
		{
			/*if (obj->type == SP)
			{
				printf("%f %f\n", dist_obj(obj, v, c), dist);
				printf("%f %f %f\n", v[X], v[Y], v[Z]);
			}*/
			if (verif(dist_obj(obj, v, c), dist))
			{
				printf("%f %f\n", dist_obj(obj, v, c), dist);
				check = 0;
			}
			obj = obj->next;
		}
		if (check == 1)
			ret = light_color(color, light->rat, light->color);
		light = light->next;
	}
	return (ret);
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
