/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/27 03:39:53 by lpaulo-m          #+#    #+#             */
/*   Updated: 2023/02/25 17:10:15 by lpaulo-m         ###   ########.fr       */
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
	double				brightness;
	t_rgb				color_rgb;

	t_c3d				intensity;
}						t_amb_light;

/******************************************************************************\
 * CAMERA
\******************************************************************************/

typedef struct s_camera
{
	bool				initialized;

	t_p3d				origin;
	t_v3d				orientation;

	double				fov_deg;
	double				fov_rad;

	int					width;
	int					height;
	double				aspect;

	double				half_view;
	double				half_width;
	double				half_height;
	double				pixel_size;

	t_matrix			transform;

	t_mlx_image			buffer;
}						t_camera;

/******************************************************************************\
 * LIGHT
\******************************************************************************/

typedef struct s_light
{
	t_p3d				origin;

	double				brightness;

	t_rgb				color_rgb;
	t_c3d				color_3d;

	t_c3d				intensity;
}						t_light;

/******************************************************************************\
 * MATERIAL
\******************************************************************************/

typedef struct s_material
{
	t_c3d				color;
	double				ambient;
	double				diffuse;
	double				specular;
	double				shininess;
}						t_material;

/******************************************************************************\
 * OBJECTS
\******************************************************************************/

typedef enum e_shape
{
	NULL_SHAPE = 0,
	SPHERE_SHAPE,
	PLANE_SHAPE,
	CYLINDER_SHAPE,
}						t_shape;

typedef struct s_intxs
{
	int					count;
	t_dlist				*list;
}						t_intxs;

typedef struct s_object	t_object;

typedef t_intxs			(*t_intersect)(t_object *, t_ray);
typedef t_v3d			(*t_normal_at)(t_object *, t_p3d);

typedef struct s_intx
{
	double				t;
	t_object			*object;
}						t_intx;

struct					s_object
{
	int					id;
	t_shape				shape;

	t_p3d				origin;
	t_v3d				normal;

	double				diameter;
	double				radius;

	double				height;
	double				minimum;
	double				maximum;
	bool				closed;

	t_matrix			transform;
	t_material			material;

	t_intersect			intersect;
	t_normal_at			normal_at;
};

typedef struct s_intx_aux
{
	t_v3d				sphere_to_ray;

	double				a;
	double				b;
	double				c;
	double				delta;

	double				root_1;
	double				root_2;

	double				y0;
	double				y1;
}						t_intx_aux;

typedef struct s_ray_comp
{
	double				t;
	t_object			*object;

	t_p3d				point;
	t_v3d				eyev;
	t_v3d				normalv;

	t_p3d				over_point;

	bool				inside;
}						t_ray_comp;

/******************************************************************************\
 * CONTROL
\******************************************************************************/

typedef struct s_minirt
{
	bool				debug;

	int					argc;
	char				**argv;

	char				*scene_path;

	t_amb_light			ambient_light;
	t_camera			camera;
	t_light				light;
	t_dlist				*objects;

	void				*mlx;
	void				*window;

	t_list				*world_lalloc;
	t_list				*ray_lalloc;
}						t_minirt;

/******************************************************************************\
 * VALIDATE_SCENE
\******************************************************************************/

typedef struct s_val_scene
{
	int					camera;
	int					ambient_light;
	int					light;
}						t_val_scene;

#endif
