/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MiniRT.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viforget <viforget@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/06 03:00:27 by viforget          #+#    #+#             */
/*   Updated: 2020/10/17 17:59:30 by viforget         ###   ########.fr       */
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
** DEFINE 
*/

# define SP 1
# define PL 2
# define SQ 3
# define CY 4
# define TR 5


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

typedef struct		s_obj
{
	char			type;
	float			c0[3];
	float			c1[3];
	float			c2[3];
	float			vec[3];
	float			dia;
	float			hight;
	int				color;
	struct s_obj	*next;
}					t_obj;

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
