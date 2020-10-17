/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MiniRT.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viforget <viforget@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/06 03:00:27 by viforget          #+#    #+#             */
/*   Updated: 2020/10/16 22:04:08 by viforget         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

/*
** INCLUDES
*/
#include "get_next_line.h"
#include "libft.h"

#include <math.h>
#include <mlx.h>

/*
** STRUCTURES
*/


/*
** ARGUMENTS
*/

typedef struct 	s_arg
{
	int			res_y;
	int			res_x;
	char		save;
	char		**screen;
	void		*obj;
}				t_arg;

/*
**  MLX
*/

typedef struct 	s_mlx
{
	void		*mlx;
	void		*win;
}				t_mlx;

/*
**	OBJ
*/

typedef struct	s_cercle
{
	float		c[3];
	float		rad;
	int			color;
	void		*next;
}				t_cercle;

typedef struct	s_sp
{
	float		c[3];
	float		dia;
	int			color;
	void		*next;
}				t_sp;

typedef struct	s_pl
{
	float		c[3];
	float		vec[3];
	int			color;
	void		*next;
}				t_pl;

typedef struct	s_sq
{
	float		c[3];
	float		vec[3];
	float		hight;
	int			color;
	void		*next;
}				t_sq;

typedef struct	s_cy
{
	float		c[3];
	float		vec[3];
	float		dia;
	float		hight;
	int			color;
	void		*next;
}				t_cy;

typedef struct	s_tr
{
	float		c1[3];
	float		c2[3];
	float		c3[3];
	int			color;
	void		*next;
}				t_tr;


/*
** LIGHT
*/

typedef	struct		s_light
{
	char			*id;
	float			c[3];
	float			dia;
	struct s_light *next;;
}					t_light;

/*
** FUNCTIONS
*/ 

/*
** ARGUMENTS.C
*/

t_arg			get_arg(char * str);


/*
**  UTILS.C
*/

void	coordinate(char *str, float c[3]);

#endif
