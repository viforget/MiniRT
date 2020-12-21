/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   square.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viforget <viforget@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/21 13:40:11 by viforget          #+#    #+#             */
/*   Updated: 2020/12/21 14:49:47 by viforget         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MiniRT.h"

void	border(t_obj *sq)
{
	float  b[3];

	sq->c2[X] = sq->c0[X] + (fabs(sq->vec[Y]) + fabs(sq->vec[Z])) * sq->hight;
	sq->c1[X] = sq->c0[X] - (fabs(sq->vec[Y]) + fabs(sq->vec[Z])) * sq->hight;
	sq->c2[Y] = sq->c0[Y] + (fabs(sq->vec[Z]) + fabs(sq->vec[X])) * sq->hight;
	sq->c1[Y] = sq->c0[Y] - (fabs(sq->vec[Z]) + fabs(sq->vec[X])) * sq->hight;
	sq->c2[Z] = sq->c0[Z] + (fabs(sq->vec[X]) + fabs(sq->vec[Y])) * sq->hight;
	sq->c1[Z] = sq->c0[Z] - (fabs(sq->vec[X]) + fabs(sq->vec[Y])) * sq->hight;
}	
