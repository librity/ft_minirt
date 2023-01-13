/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/27 03:39:53 by lpaulo-m          #+#    #+#             */
/*   Updated: 2023/01/13 19:16:35 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

# include <algebra.h>
# include <ft_libbmp.h>
# include <libft.h>
# include <stdbool.h>

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

	// double		view_width;
	// double		view_height;

	// t_v3d		horizontal;
	// t_v3d		vertical;
	// t_p3d		ll_corner;

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

	t_c3d		intensity;
}				t_light;

/******************************************************************************\
 * MATERIAL
\******************************************************************************/

typedef struct s_material
{
	t_c3d		color;
	double		ambient;
	double		diffuse;
	double		specular;
	double		shininess;
}				t_material;

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
	int			id;
	t_shape		shape;

	t_p3d		origin;
	t_v3d		normal;

	double		diameter;
	double		radius;

	double		height;

	t_rgb		color_rgb;
	t_c3d		color_3d;

	t_matrix	transform;
	t_material	material;
}				t_object;

typedef struct s_intxs
{
	int			count;
	t_dlist		*list;
}				t_intxs;

typedef struct s_intx
{
	double		t;
	t_object	*object;
}				t_intx;

typedef struct s_intersect_factors
{
	t_v3d		sphere_to_ray;

	double		a;
	double		b;
	double		c;
	double		delta;

	double		root_1;
	double		root_2;
}				t_intersect_factors;

typedef struct s_ray_comp
{
	double		t;
	t_object	*object;

	t_p3d		point;
	t_v3d		eyev;
	t_v3d		normalv;
}				t_ray_comps;

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
	double		aspect_ratio;

	t_list		*lalloc;
}				t_minirt;

/******************************************************************************\
 * VALIDATE_SCENE
\******************************************************************************/

typedef struct s_val_scene
{
	int			camera;
	int			ambient_light;
	int			light;
}				t_val_scene;

#endif
