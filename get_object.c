/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_object.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viforget <viforget@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/17 18:38:03 by viforget          #+#    #+#             */
/*   Updated: 2020/10/17 19:53:18 by viforget         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MiniRT.h"

void	get_sp(char **split, t_arg arg)
{
	t_obj *sp;

	sp = malloc(sizeof(t_obj));
	bzero_obj(sp);
	sp->type = SP;
	coordinate(split[1], sp->c0);
	sp->dia = atof(split[2]);
	sp->color = get_color(split[3]);
	arg.obj = add_object(arg.obj, sp);
	printf("-----\ntype : %i\nc0:  %f %f %f\nc1:  %f %f %f\nc2:  %f %f %f\nvec: %f %f %f\ndia: %f\nhight: %f\ncolor: %X\n----\n-", sp->type, sp->c0[0], sp->c0[1], sp->c0[2], sp->c1[0], sp->c1[1], sp->c1[2], sp->c2[0], sp->c2[1], sp->c2[2], sp->vec[0], sp->vec[1], sp->vec[2], sp->dia, sp->hight, sp->color);
}

void	get_pl(char **pllit, t_arg arg)
{
	t_obj *pl;

	pl = malloc(sizeof(t_obj));
	bzero_obj(pl);
	pl->type = PL;
	coordinate(pllit[1], pl->c0);
	coordinate(pllit[2], pl->vec);
	pl->color = get_color(pllit[3]);
	arg.obj = add_object(arg.obj, pl);
	printf("-----\ntype : %i\nc0:  %f %f %f\nc1:  %f %f %f\nc2:  %f %f %f\nvec: %f %f %f\ndia: %f\nhight: %f\ncolor: %X\n----\n-", pl->type, pl->c0[0], pl->c0[1], pl->c0[2], pl->c1[0], pl->c1[1], pl->c1[2], pl->c2[0], pl->c2[1], pl->c2[2], pl->vec[0], pl->vec[1], pl->vec[2], pl->dia, pl->hight, pl->color);
}

void	get_sq(char **split, t_arg arg)
{
	t_obj *sq;

	sq = malloc(sizeof(t_obj));
	bzero_obj(sq);
	sq->type = SQ;
	coordinate(split[1], sq->c0);
	coordinate(split[2], sq->vec);
	sq->hight = atof(split[3]);
	sq->color = get_color(split[4]);
	arg.obj = add_object(arg.obj, sq);
	printf("-----\ntype : %i\nc0:  %f %f %f\nc1:  %f %f %f\nc2:  %f %f %f\nvec: %f %f %f\ndia: %f\nhight: %f\ncolor: %X\n-----\n", sq->type, sq->c0[0], sq->c0[1], sq->c0[2], sq->c1[0], sq->c1[1], sq->c1[2], sq->c2[0], sq->c2[1], sq->c2[2], sq->vec[0], sq->vec[1], sq->vec[2], sq->dia, sq->hight, sq->color);
}

void	get_cy(char **split, t_arg arg)
{
	t_obj *cy;

	cy = malloc(sizeof(t_obj));
	bzero_obj(cy);
	cy->type = CY;
	coordinate(split[1], cy->c0);
	coordinate(split[2], cy->vec);
	cy->dia = atof(split[3]);
	cy->hight = atof(split[4]);
	cy->color = get_color(split[5]);
	arg.obj = add_object(arg.obj, cy);
	printf("-----\ntype : %i\nc0:  %f %f %f\nc1:  %f %f %f\nc2:  %f %f %f\nvec: %f %f %f\ndia: %f\nhight: %f\ncolor: %X\n-----\n", cy->type, cy->c0[0], cy->c0[1], cy->c0[2], cy->c1[0], cy->c1[1], cy->c1[2], cy->c2[0], cy->c2[1], cy->c2[2], cy->vec[0], cy->vec[1], cy->vec[2], cy->dia, cy->hight, cy->color);
}

void	get_tr(char **split, t_arg arg)
{
	t_obj *tr;

	tr = malloc(sizeof(t_obj));
	bzero_obj(tr);
	tr->type = TR;
	coordinate(split[1], tr->c0);
	coordinate(split[2], tr->c1);
	coordinate(split[3], tr->c2);
	tr->color = get_color(split[4]);
	arg.obj = add_object(arg.obj, tr);
	printf("-----\ntype : %i\nc0:  %f %f %f\nc1:  %f %f %f\nc2:  %f %f %f\nvec: %f %f %f\ndia: %f\nhight: %f\ncolor: %X\n-----\n", tr->type, tr->c0[0], tr->c0[1], tr->c0[2], tr->c1[0], tr->c1[1], tr->c1[2], tr->c2[0], tr->c2[1], tr->c2[2], tr->vec[0], tr->vec[1], tr->vec[2], tr->dia, tr->hight, tr->color);
}
