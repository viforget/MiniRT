/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   function.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viforget <viforget@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/23 12:15:09 by viforget          #+#    #+#             */
/*   Updated: 2021/02/24 10:12:45 by viforget         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FUNCTION_H
# define FUNCTION_H

# include "minirt.h"

/*
** FUNCTIONS
*/

/*
** ARGUMENTS.C
*/

t_arg	get_arg(char **str);
t_arg	bzero_arg(t_arg arg);

/*
** BMP.C
*/

void	bmp_save(t_arg arg);

/*
**	CALC_COORD.C
*/

void	calc_coord(float c[3], float v[3], float dist, float ret[3]);
void	vect_to(float ori[3], float des[3], float v[3], double *d);

/*
** CAMERA.C
*/

t_cam	*p_last_cam(t_cam *cam);
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

double	dist_cy(t_obj *cy, float v[3], float p[3]);

/*
** CY_COLOR.C
*/

void	half_vector(float v[3], float u[3]);
float	cy_color(float p[3], float v[3], t_obj *cy);

/*
** DISPLAY.C
*/

void	display_screen(t_mlx *mlx, t_arg *arg, t_cam *cam);
void	calc_screen(t_mlx mlx, t_arg *arg);

/*
** DISTANCE.C
*/

double	dist_obj(t_obj *obj, float v[3], float p[3]);

/*
** ERROR.C
*/

void	del_arg(t_arg arg);
int		get_error(t_arg arg, char **split, int err);

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
** MLX_FUNCTION.C
*/

void	mlx_setup(t_mlx *mlx, t_arg *arg, char *title);
void	mlx_loop_aff(t_arg arg, t_mlx mlx);

/*
** ROTATION.C
*/

void	set_cy(t_obj *cy, float v[3], float p[3], float c[2][3]);
void	rot_fov(t_arg *arg, float v[3], int x, int y);
void	rotation(float v[3], float u[3], float a, float ret[3]);
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
t_obj	*add_object(t_obj *first, t_obj *obj);
void	bzero_obj(t_obj *obj);

/*
** UTILS2.c
*/

t_cam	*add_cam(t_cam *first, t_cam *cam);
int		sizeof_tab(char **tab);
t_lig	*add_lig(t_lig *first, t_lig *lig);
float	radian(float angle);
int		light_color(int color, float intensity, int light);
float	diff_angle(float u[3], float v[3]);

/*
**	UTILS3.C
*/

void	bzero_vect(float v[3]);
void	bzero_d2(double d[2]);
float	calc_angle_x(float fov, int res, int x);
float	calc_angle_y(float fov, int res, int y);
double	normalize_vect(float v[3]);

/*
** VECTOR.C
*/

float	scal_vector(float v1[3], float v2[3]);
void	vector_sub(float v1[3], float v2[3], float ret[3]);
void	invert_vector(float v[3], float ret[3]);
void	ortho_vector(float v[3], float u[3], float ret[3]);
void	ortho_triangle(t_obj *triangle);

#endif
