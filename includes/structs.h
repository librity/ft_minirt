/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/27 03:39:53 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/12/24 10:31:05 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

# include <libft.h>
# include <ft_libbmp.h>
# include <stdbool.h>
# include <vectors.h>

/******************************************************************************\
 * COLORS
\******************************************************************************/

typedef t_v3d	t_c3d;

/******************************************************************************\
 * AMBIENT LIGHT
\******************************************************************************/

typedef struct s_amb_light
{
	double		brightness;

	t_rgb		color_rgb;
	t_c3d		color_3d;
}				t_amb_light;

/******************************************************************************\
 * CAMERA
\******************************************************************************/

typedef struct s_camera
{
	t_p3d		origin;
	t_v3d		orientation;

	double		horz_fov_deg;
	double		horz_fov_rad;

	t_v3d		horizontal;
	t_v3d		vertical;
	t_p3d		ll_corner;

	t_mlx_image	buffer;
}				t_camera;

/******************************************************************************\
 * LIGHT
\******************************************************************************/

typedef struct s_light
{
	t_p3d		origin;

	double		brightness;

	t_rgb		color_rgb;
	t_c3d		color_3d;
}				t_light;

/******************************************************************************\
 * OBJECTS
\******************************************************************************/

typedef enum e_shape
{
	NULL_SHAPE = 0,
	SPHERE_SHAPE,
	PLANE_SHAPE,
	CYLINDER_SHAPE,
}				t_shape;

typedef struct s_object
{
	t_shape		shape;

	t_p3d		origin;
	t_v3d		normal;

	double		diameter;
	double		radius;

	double		height;

	t_rgb		color_rgb;
	t_c3d		color_3d;
}				t_object;

/******************************************************************************\
 * CONTROL
\******************************************************************************/

typedef struct s_minirt
{
	bool		debug;

	int			argc;
	char		**argv;

	char		*scene_path;

	t_amb_light	ambient_light;
	t_camera	camera;
	t_light		light;
	t_dlist		*objects;

	void		*mlx;
	void		*window;
	int			width;
	int			height;

	t_list		*lalloc;
}				t_minirt;

/******************************************************************************\
 * VALIDATE_SCENE
\******************************************************************************/

typedef struct s_val_scene
{
	int	camera;
	int	ambient_light;
	int	light;
}			t_val_scene;

/******************************************************************************\
 * MATH
\******************************************************************************/

typedef struct s_ray
{
	t_p3d		origin;
	t_v3d		direction;
}				t_ray;

typedef struct s_root
{
	double	root_a;
	double	root_b;

	bool	has_root;
	double	delta;
}			t_root;

#endif
