/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/27 03:39:53 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/03/22 23:14:03 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include <X11/Xlib.h>
# include <algebra.h>
# include <defines.h>
# include <float.h>
# include <libft.h>
# include <math.h>
# include <structs.h>

/******************************************************************************\
 * RAY TRACER
\******************************************************************************/

void			initialize_ctl(t_minirt *ctl);
void			cleanup_ctl(t_minirt *ctl);

/******************************************************************************\
 * LIGHTS
\******************************************************************************/

void			set_ambient_light(t_minirt *ctl, double brightness,
					t_rgb color_rgb);

typedef struct s_new_light
{
	t_p3d		origin;
	double		brightness;
	t_rgb		color_rgb;
}				t_new_light;
t_light			*new_light(t_new_light p);
typedef t_new_light	t_add_light;
void			add_light(t_minirt *ctl, t_add_light p);
void			free_lights(t_minirt *ctl);

/******************************************************************************\
 * CAMERAS
\******************************************************************************/

typedef struct s_new_camera
{
	int			number;

	t_p3d		look_from;
	t_v3d		look_at;

	double		horz_fov_deg;
	double		horz_fov_rad;

	double		view_width;
	double		view_height;

	t_v3d		base_u;
	t_v3d		base_v;
	t_v3d		base_w;

	void		*mlx;
	int			width;
	int			height;
	double		aspect_ratio;
}				t_new_camera;
t_camera		*new_camera(t_new_camera p);

typedef struct s_add_camera
{
	t_p3d		look_from;

	t_v3d		look_at;

	double		horz_fov_deg;
}				t_add_camera;
void			add_camera(t_minirt *ctl, t_add_camera p);

void			generate_image(t_minirt *ctl, t_camera *camera);

void			free_cameras(t_minirt *ctl);

void			save_camera_buffer(t_camera *camera);

/******************************************************************************\
 * RAYS
\******************************************************************************/

t_ray			ray(t_p3d origin, t_v3d direction);

t_ray			get_ray(t_minirt *ctl, t_camera *camera, int x, int y);

t_p3d			ray_at_t(double translation, t_ray ray);

t_c3d			cast_ray(t_minirt *ctl, t_ray ray);

/******************************************************************************\
 * HIT RECORD
\******************************************************************************/

void			set_record(t_hit_rec *target, t_hit_rec record);
void			set_face_normal(t_ray ray, t_v3d outward_normal,
					t_hit_rec *record);

/******************************************************************************\
 * SPHERES
\******************************************************************************/

typedef struct s_new_sphere
{
	t_p3d		center;
	double		diameter;
	t_rgb		color_rgb;
}				t_new_sphere;
t_sphere		*new_sphere(t_new_sphere p);
void			add_sphere(t_minirt *ctl, t_new_sphere p);

void			free_spheres(t_minirt *ctl);

typedef struct s_vectorial_quadratic
{
	t_ray		ray;
	t_sphere	*sphere;

	double		min_translation;
	double		max_translation;

	double		*root;
}				t_vectorial_quadratic;
typedef struct s_ray_hits_sphere
{
	t_ray		ray;
	t_sphere	*sphere;
	t_hit_rec	*record;

	double		t_min;
	double		t_max;
}				t_ray_hits_sphere;
bool			ray_hits_sphere(t_ray_hits_sphere p);

t_c3d			render_sphere(t_minirt *ctl, t_ray ray, t_hit_rec *record);

/******************************************************************************\
 * PLANES
\******************************************************************************/

/******************************************************************************\
 * CYLINDERS
\******************************************************************************/

/******************************************************************************\
 * SCENE
\******************************************************************************/

void			handle_arguments(int argument_count);

/******************************************************************************\
 * SCENE VALIDATOR
\******************************************************************************/

void			validate_scene(char *scene_path);

void			validate_ambient_light(char *line, char *free_me);

bool			invalid_brightness(char *line);
bool			invalid_color(char *line);
bool			invalid_rgb(char *line);

/******************************************************************************\
 * SCENE PARSER
\******************************************************************************/

/******************************************************************************\
 * MLX
\******************************************************************************/

void			initialize_mlx(t_minirt *ctl);

int				handle_destroy(t_minirt *ctl);
int				handle_keypress(int keycode, t_minirt *ctl);

void			handle_close(int keycode, t_minirt *ctl);
void			handle_navigation(int keycode, t_minirt *ctl);
void			handle_save_to_bitmap(int keycode, t_minirt *ctl);

/******************************************************************************\
 * LOGGERS
\******************************************************************************/

void			log_msg(char *message);
void			log_endl(char *message);

void			log_keycode(int keycode);
void			log_camera(int keycode);

void			log_scene(t_minirt *ctl);

/******************************************************************************\
 * EXIT
\******************************************************************************/

void			clean(t_minirt *ctl);
void			clean_and_exit(t_minirt *ctl);

/******************************************************************************\
 * ERRORS
\******************************************************************************/

void			print_error(int code);

void			die(t_errors code);
void			help_and_die(void);
void			die_if_null(void *ptr, t_errors code);
void			freestr_and_die(char *free_me, t_errors code);

int				open_scene_or_die(char *scene_path);

#endif
