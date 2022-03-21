/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/27 03:39:53 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/03/20 22:37:52 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

# include <stdbool.h>
# include <vectors.h>

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
 * LIGHTS
\******************************************************************************/

typedef struct s_light
{
	t_p3d		origin;

	double		brightness;

	t_rgb		color_rgb;
	t_c3d		color_3d;
}				t_light;

/******************************************************************************\
 * CAMERAS
\******************************************************************************/

typedef struct s_camera
{
	int			number;

	t_p3d		origin;

	t_v3d		orientation;

	t_v3d		horizontal;
	t_v3d		vertical;
	t_p3d		ll_corner;

	t_mlx_image	buffer;
}				t_camera;

/******************************************************************************\
 * RAYS
\******************************************************************************/

typedef struct s_ray
{
	t_p3d		origin;
	t_v3d		direction;
}				t_ray;

/******************************************************************************\
 * HIT RECORD
\******************************************************************************/

typedef struct s_hit_rec
{
	t_p3d		intersection;
	t_v3d		normal;
	t_c3d		color_3d;
	double		translation;
	bool		front_face;
}				t_hit_rec;

/******************************************************************************\
 * SPHERES
\******************************************************************************/

typedef struct s_sphere
{
	t_p3d		center;

	double		diameter;
	double		radius;

	t_rgb		color_rgb;
	t_c3d		color_3d;
}				t_sphere;

/******************************************************************************\
 * PLANES
\******************************************************************************/

typedef struct s_plane
{
	t_p3d		center;

	t_v3d		orientation;

	t_rgb		color_rgb;
	t_c3d		color_3d;
}				t_plane;

/******************************************************************************\
 * CYLINDERS
\******************************************************************************/

typedef struct s_cylinder
{
	t_p3d		center;

	t_v3d		orientation;

	double		diameter;
	double		radius;

	double		height;

	t_rgb		color_rgb;
	t_c3d		color_3d;
}				t_cylinder;

/******************************************************************************\
 * RAY TRACER
\******************************************************************************/

typedef struct s_minirt
{
	char		*file_name;

	int			width;
	int			height;
	double		aspect_ratio;

	void		*mlx;
	void		*window;

	t_amb_light	ambient;

	t_camera	*current_cam;
	t_list		*cameras;

	t_list		*lights;

	t_list		*spheres;
	t_list		*planes;
	t_list		*cylinders;
}				t_minirt;

#endif
