/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MiniRT.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viforget <viforget@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/06 03:00:27 by viforget          #+#    #+#             */
/*   Updated: 2020/10/17 20:31:25 by viforget         ###   ########.fr       */
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
** LIGHT
*/

typedef struct	s_light
{
	float		c[3];
	float		vec[3];
	int			fov;
}				*t_light;

/*
** ARGUMENTS
*/

typedef struct 	s_arg
{
	int			res_y;
	int			res_x;
	char		save;
	char		**screen;
	t_cam		*cam
	t_obj		*obj;
	t_light		*lig;
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
** FUNCTIONS
*/ 

/*
** ARGUMENTS.C
*/

t_arg			get_arg(char * str);

/*
** GET_OBJECT.C
*/

void	get_sp(char **split, t_arg arg);
void	get_pl(char **split, t_arg arg);
void	get_sq(char **split, t_arg arg);
void	get_cy(char **split, t_arg arg);
void	get_tr(char **split, t_arg arg);

/*
**  UTILS.C
*/

float	ft_atof(char *str);
void	coordinate(char *str, float c[3]);
int		get_color(char *str);
t_obj	* add_object(t_obj * first, t_obj * obj);
void	bzero_obj(t_obj *obj);

#endif
