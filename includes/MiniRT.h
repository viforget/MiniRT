/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MiniRT.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viforget <viforget@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/06 03:00:27 by viforget          #+#    #+#             */
/*   Updated: 2021/01/13 18:16:00 by viforget         ###   ########.fr       */
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
# define A 0
# define B 1
# define C 2
# define RED 0
# define GREEN 1
# define BLUE 2
# define ZE 0.02
# define NEXT 1
# define PREV 2
# define NB_THREAD 10

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
	int			*disp;
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
void	vect_to(float ori[3], float des[3], float v[3], double *d);

/*
** CAMERA.C 
*/

int		get_cam(char **split, t_arg *arg);

/*
** COLOR.C
*/

int		v_to_color(float v[3]);
void	intens_add(float col[3], int l_color, float intensity, int color);
float	rat_ang(float p[3], float v[3], t_obj *obj);

/*
** CYLINDRE.C
*/ 

double	dist_cy(t_obj cy, float v[3], float p[3]);

/*
** DISPLAY.C
*/

void	display_screen(t_mlx mlx, t_arg arg, t_cam *cam);

/*
** DISTANCE.C
*/

double	dist_obj(t_obj *obj, float v[3], float p[3]);

/*
** ERROR.C
*/

int	get_error(t_arg arg, char **split, int err);

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

int		calc_light(float c[3], t_arg arg, t_obj *obj, char check);
int		get_lig(char **split, t_arg *arg);

/*
** ROTATION.C
*/

void	rhor(float v[3], float ang, float ret[3]);
void	rver(float v[3], float ang, float ret[3]);

/*
** SQUARE.C
*/ 

void	border(t_obj *sq);

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
float	diff_angle(float u[3], float v[3]);

/*
**	UTILS3.C
*/

void	bzero_vect(float v[3]);
float	calc_angle_x(float fov, int res, int x);
float	calc_angle_y(float fov, int res, int y);
double	normalize_vect(float v[3]);
void	link_point(float p1[3], float p2[3], float ret[3]);

/*
** VECTOR.C
*/

float	scal_vector(float v1[3], float v2[3]);
void	vector_sub(float v1[3], float v2[3], float ret[3]);
void	invert_vector(float v[3], float ret[3]);
void	ortho_vector(float v[3], float u[3], float ret[3]);
void	ortho_triangle(t_obj *triangle);

#endif
