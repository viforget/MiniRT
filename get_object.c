/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_object.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viforget <viforget@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/17 18:38:03 by viforget          #+#    #+#             */
/*   Updated: 2020/12/15 15:59:03 by viforget         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MiniRT.h"

int		get_sp(char **split, t_arg *arg)
{
	t_obj *sp;

	if (!(sp = malloc(sizeof(t_obj))))
		return (0);
	bzero_obj(sp);
	sp->type = SP;
	coordinate(split[1], sp->c0);
	sp->dia = atof(split[2]);
	sp->color = get_color(split[3]);
	arg->obj = add_object(arg->obj, sp);
	return (1);
}

int		get_pl(char **split, t_arg *arg)
{
	t_obj *pl;

	if (!(pl = malloc(sizeof(t_obj))))
		return (0);
	bzero_obj(pl);
	pl->type = PL;
	coordinate(split[1], pl->c0);
	coordinate(split[2], pl->vec);
	normalize_vect(pl->vec);
	pl->color = get_color(split[3]);
	arg->obj = add_object(arg->obj, pl);
	return (1);
}

int		get_sq(char **split, t_arg *arg)
{
	t_obj *sq;

	if (!(sq = malloc(sizeof(t_obj))))
		return (0);
	bzero_obj(sq);
	sq->type = SQ;
	coordinate(split[1], sq->c0);
	coordinate(split[2], sq->vec);
	normalize_vect(sq->vec);
	sq->hight = atof(split[3]);
	sq->color = get_color(split[4]);
	arg->obj = add_object(arg->obj, sq);
	return (1);
}

int		get_cy(char **split, t_arg *arg)
{
	t_obj *cy;

	if (!(cy = malloc(sizeof(t_obj))))
		return (0);
	bzero_obj(cy);
	cy->type = CY;
	coordinate(split[1], cy->c0);
	coordinate(split[2], cy->vec);
	normalize_vect(cy->vec);
	cy->dia = atof(split[3]);
	cy->hight = atof(split[4]);
	cy->color = get_color(split[5]);
	arg->obj = add_object(arg->obj, cy);
	return (1);
}

int		get_tr(char **split, t_arg *arg)
{
	t_obj *tr;

	if (!(tr = malloc(sizeof(t_obj))))
		return (0);
	bzero_obj(tr);
	tr->type = TR;
	coordinate(split[1], tr->c0);
	coordinate(split[2], tr->c1);
	coordinate(split[3], tr->c2);
	ortho_triangle(tr);
	tr->vec[0] *= -1;
	tr->color = get_color(split[4]);
	arg->obj = add_object(arg->obj, tr);
	return (1);
}
