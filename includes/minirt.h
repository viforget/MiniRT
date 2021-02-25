/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viforget <viforget@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/06 03:00:27 by viforget          #+#    #+#             */
/*   Updated: 2021/02/24 10:13:42 by viforget         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

/*
** INCLUDES
*/

# include "get_next_line.h"
# include "libft.h"
# include "../mlx/mlx.h"

# include <math.h>
# include <pthread.h>

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
# define ZE 0.008
# define NEXT 1
# define PREV 2
# define NB_THREAD 1

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
	float			height;
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
	struct s_lig	*next;
}					t_lig;

/*
** CAMERA
*/

typedef struct		s_cam
{
	float			c[3];
	float			vec[3];
	int				fov;
	int				*disp;
	struct s_cam	*next;
}					t_cam;

/*
**  MLX
*/

typedef struct		s_mlx
{
	void			*mlx;
	void			*win;
	void			*img;
	int				size_l;
	int				bpp;
	int				endian;
	int				*disp;
}					t_mlx;

/*
** ARGUMENTS
*/

typedef struct		s_arg
{
	int				th;
	int				res_y;
	int				res_x;
	char			save;
	char			*name;
	float			a_rat;
	int				a_color;
	char			a_check;
	t_mlx			*mlx;
	t_cam			*cam;
	t_obj			*obj;
	t_lig			*lig;
}					t_arg;

/*
** FUNCTIONS
*/

# include "function.h"

#endif
