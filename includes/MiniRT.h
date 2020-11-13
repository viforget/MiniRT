/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MiniRT.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viforget <viforget@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/06 03:00:27 by viforget          #+#    #+#             */
/*   Updated: 2020/11/11 18:14:46 by viforget         ###   ########.fr       */
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

#include <stdio.h>

/*
** DEFINE 
*/

# define SP 1
# define PL 2
# define SQ 3
# define CY 4
# define TR 5
# define X 0
# define Y 1
# define Z 2
# define RED 0
# define GREEN 1
# define BLUE 2
# define ZE 0.002

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

typedef	struct		s_lig
{
	float			c[3];
	float			rat;
	int				color;
	struct s_lig *next;;
}					t_lig;

/*
** CAMERA
*/

typedef struct		s_cam
{
	float			c[3];
	float			vec[3];
	int				fov;
	struct	s_cam	*next;
}					t_cam;

/*
** ARGUMENTS
*/

typedef struct 	s_arg
{
	int			res_y;
	int			res_x;
	char		save;
	char		**screen;
	float		a_rat;
	int			a_color;
	t_cam		*cam;
	t_obj		*obj;
	t_lig		*lig;
}				t_arg;

/*
**  MLX
*/

typedef struct 	s_mlx
{
	void		*mlx;
	void		*win;
	void		*img;
	int			size_l;
	int			bpp;
	int			endian;
}				t_mlx;

/*
** FUNCTIONS
*/ 

/*
** ARGUMENTS.C
*/

t_arg	get_arg(char * str);

/*
**	CALC_COORD.C
*/

void	calc_coord(float c[3], float v[3], float dist, float ret[3]);
void	vect_to(float ori[3], float des[3], float v[3], float *d);

/*
** CAMERA.C 
*/

int		get_cam(char **split, t_arg *arg);

/*
** DISPLAY.C
*/

float	dist_obj(t_obj *obj, float v[3], float p[3]);
void	display_screen(t_mlx mlx, t_arg arg, t_cam *cam);

/*
** ERROR.C
*/

int	get_error(t_arg arg, char **split);

/*
** GET_OBJECT.C
*/

int		get_sp(char **split, t_arg *arg);
int		get_pl(char **split, t_arg *arg);
int		get_sq(char **split, t_arg *arg);
int		get_cy(char **split, t_arg *arg);
int		get_tr(char **split, t_arg *arg);

/*
** LIGHT.C 
*/

int		calc_light(float c[3], int color, t_arg arg);
int		get_lig(char **split, t_arg *arg);

/*
**  UTILS.C
*/

void	afv(char *s, float v[3]);
float	ft_atof(char *str);
void	coordinate(char *str, float c[3]);
int		get_color(char *str);
t_obj	* add_object(t_obj * first, t_obj * obj);
void	bzero_obj(t_obj *obj);

/*
** UTILS2.c 
*/

t_cam	* add_cam(t_cam * first, t_cam * cam);
int		sizeof_tab(char **tab);
t_lig	* add_lig(t_lig * first, t_lig * lig);
float	radian(float angle);
int		light_color(int color, float intensity, int light);

/*
** VECTOR.C
*/

float	scal_vector(float v1[3], float v2[3]);
void	vector_sub(float v1[3], float v2[3], float ret[3]);

#endif
