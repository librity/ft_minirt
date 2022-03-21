/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/27 03:39:53 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/03/20 21:28:07 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include <X11/Xlib.h>
# include <defines.h>
# include <float.h>
# include <ft_libbmp.h>
# include <libft.h>
# include <math.h>
# include <stdbool.h>
# include <stdio.h>

/******************************************************************************\
 * ALGEBRA
\******************************************************************************/

double				infinity(void);

double				degrees_to_radians(double degrees);

typedef struct s_quadratic
{
	double			a;
	double			half_b;
	double			c;
	double			discriminant;
	double			d_sqrt;
	double			root;
}					t_quadratic;
bool				quadratic(t_quadratic r, double min_translation,
					double max_translation, double *root);

/******************************************************************************\
 * VECTORS
\******************************************************************************/

typedef struct s_v3d
{
	double			x;
	double			y;
	double			z;
}					t_v3d;

t_v3d				vector(double x, double y, double z);
t_v3d				vector_3d(double x, double y, double z);

void				inspect(t_v3d vector);

double				length_squared(t_v3d vector);
double				length(t_v3d vector);

t_v3d				negative(t_v3d vector);
t_v3d				unit(t_v3d vector);
t_v3d				vsqrt(t_v3d vector);

t_v3d				scalar_add(double number, t_v3d vector);
t_v3d				scalar_sub(double number, t_v3d vector);
t_v3d				scalar_times(double number, t_v3d vector);
t_v3d				scalar_div(double number, t_v3d vector);

double				dot(t_v3d first, t_v3d second);

t_v3d				add(t_v3d first, t_v3d second);
t_v3d				sub(t_v3d first, t_v3d second);
t_v3d				cross(t_v3d first, t_v3d second);
t_v3d				product(t_v3d first, t_v3d second);
t_v3d				division(t_v3d first, t_v3d second);

bool				near_zero(t_v3d vector);

/******************************************************************************\
 * POINTS
\******************************************************************************/

typedef t_v3d		t_p3d;

t_p3d				point(double x, double y, double z);
t_p3d				point_3d(double x, double y, double z);

/******************************************************************************\
 * COLORS
\******************************************************************************/

typedef t_v3d		t_c3d;

t_c3d				color(double red, double green, double blue);
t_c3d				color_3d(double red, double green, double blue);
t_rgb				color_rgb(unsigned char red, unsigned char green,
					unsigned char blue);

t_rgb				c3d_to_rgb(t_c3d color_3d);
t_c3d				rgb_to_c3d(t_rgb color_rgb);

t_rgb				get_gamma2_pixel(t_c3d color_3d);

/******************************************************************************\
 * RANDOM
\******************************************************************************/

double				random_double(void);
double				random_from(double min, double max);
double				canonical_random(void);

t_v3d				random_vector(void);
t_v3d				random_vector_in(double min, double max);

double				rp(void);
double				rr(void);
t_c3d				rc(void);
t_c3d				rcr(double min, double max);

t_v3d				random_unit_vector(void);

t_p3d				random_in_unit_sphere(void);
t_p3d				random_in_unit_disk(void);
t_v3d				random_in_hemisphere(t_v3d normal);

/******************************************************************************\
 * RAY TRACER
\******************************************************************************/

typedef struct s_amb_light
{
	double			brightness;

	t_rgb			color_rgb;
	t_c3d			color_3d;
}					t_amb_light;

typedef struct s_minirt
{
	char			*file_name;

	int				width;
	int				height;
	double			aspect_ratio;

	void			*mlx;
	void			*window;

	t_amb_light		ambient;

	t_list			*cameras;

	t_list			*lights;

	t_list			*spheres;
	t_list			*planes;
	t_list			*cylinders;
}					t_minirt;

void				initialize_ctl(t_minirt *ctl);
void				cleanup_ctl(t_minirt *ctl);

/******************************************************************************\
 * LIGHTS
\******************************************************************************/

typedef struct s_light
{
	t_p3d			origin;

	double			brightness;

	t_rgb			color_rgb;
	t_c3d			color_3d;
}					t_light;

void				set_ambient_light(t_minirt *ctl, double brightness,
						t_rgb color_rgb);

/******************************************************************************\
 * CAMERAS
\******************************************************************************/

typedef struct s_camera
{
	t_p3d			origin;

	t_v3d			orientation;

	t_v3d			horizontal;
	t_v3d			vertical;
	t_p3d			ll_corner;

	t_mlx_image		buffer;
}					t_camera;

typedef struct s_new_camera
{
	t_p3d			origin;
	t_v3d			orientation;

	double			horz_fov_deg;
	double			horz_fov_rad;

	double			view_width;
	double			view_height;

	t_v3d			base_u;
	t_v3d			base_v;
	t_v3d			base_w;

	void			*mlx;
	int				width;
	int				height;
	double			aspect_ratio;
}					t_new_camera;
t_camera			*new_camera(t_new_camera p);

typedef struct s_add_camera
{
	t_p3d			origin;

	t_v3d			orientation;

	double			horz_fov_deg;
}					t_add_camera;
void				add_camera(t_minirt *ctl, t_add_camera p);

void				generate_image(t_minirt *ctl, t_camera *camera);

void				free_cameras(t_minirt *ctl);

/******************************************************************************\
 * RAYS
\******************************************************************************/

typedef struct s_ray
{
	t_p3d			origin;
	t_v3d			direction;
}					t_ray;

t_ray				ray(t_p3d origin, t_v3d direction);

t_ray				get_ray(t_minirt *ctl, t_camera *camera, int x, int y);

t_p3d				ray_at_t(double translation, t_ray ray);

t_c3d				cast_ray(t_minirt *ctl, t_ray ray);

/******************************************************************************\
 * HIT RECORD
\******************************************************************************/

typedef struct s_hit_record
{
	t_p3d			intersection;
	t_v3d			normal;
	t_c3d			color_3d;
	double			translation;
	bool			front_face;
}					t_hit_record;

void				set_record(t_hit_record *target, t_hit_record record);
void				set_face_normal(t_ray ray, t_v3d outward_normal,
						t_hit_record *record);

/******************************************************************************\
 * SPHERES
\******************************************************************************/

typedef struct s_sphere
{
	t_p3d			center;

	double			diameter;
	double			radius;

	t_rgb			color_rgb;
	t_c3d			color_3d;
}					t_sphere;

typedef struct s_new_sphere
{
	t_p3d			center;
	double			diameter;
	t_rgb			color_rgb;
}					t_new_sphere;
t_sphere			*new_sphere(t_new_sphere p);
void				add_sphere(t_minirt *ctl, t_new_sphere p);

void				free_spheres(t_minirt *ctl);

typedef struct s_vectorial_quadratic
{
	t_ray			ray;
	t_sphere		*sphere;

	double			min_translation;
	double			max_translation;

	double			*root;
}					t_vectorial_quadratic;
typedef struct s_ray_hits_sphere
{
	t_ray			ray;
	t_sphere		*sphere;
	t_hit_record	*record;

	double			t_min;
	double			t_max;
}					t_ray_hits_sphere;
bool				ray_hits_sphere(t_ray_hits_sphere p);

t_c3d				render_sphere(t_minirt *ctl, t_ray ray,
						t_hit_record *record);

/******************************************************************************\
 * PLANES
\******************************************************************************/

typedef struct s_plane
{
	t_p3d			center;

	t_v3d			orientation;

	t_rgb			color_rgb;
	t_c3d			color_3d;
}					t_plane;

/******************************************************************************\
 * CYLINDERS
\******************************************************************************/

typedef struct s_cylinder
{
	t_p3d			center;

	t_v3d			orientation;

	double			diameter;
	double			radius;

	double			height;

	t_rgb			color_rgb;
	t_c3d			color_3d;
}					t_cylinder;

/******************************************************************************\
 * SCENE
\******************************************************************************/

void				handle_arguments(int argument_count);

/******************************************************************************\
 * MLX
\******************************************************************************/

void				initialize_mlx(t_minirt *ctl);

int					handle_destroy(t_minirt *ctl);
int					handle_keypress(int keycode, t_minirt *ctl);

void				handle_close(int keycode, t_minirt *ctl);
void				handle_navigation(int keycode, t_minirt *ctl);
void				handle_save_to_bitmap(int keycode, t_minirt *ctl);

/******************************************************************************\
 * LOGGERS
\******************************************************************************/

void				log_msg(char *message);
void				log_endl(char *message);

void				log_keycode(int keycode);
void				log_camera(int keycode);

void				log_scene(t_minirt *ctl);

/******************************************************************************\
 * EXIT
\******************************************************************************/

void				clean(t_minirt *ctl);
void				clean_and_exit(t_minirt *ctl);

/******************************************************************************\
 * ERRORS
\******************************************************************************/

typedef enum e_errors
{
	BAD_ARGUMENTS = 1,
	GENERIC_RAY_TRACER_ERROR
}					t_errors;

void				kill_ray_tracer(t_errors code);

void				help_and_die(void);
void				die(void);
void				die_if_null(void *ptr);

#endif
