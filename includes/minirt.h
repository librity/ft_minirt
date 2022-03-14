/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/27 03:39:53 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/03/14 16:06:38 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include <float.h>
# include <ft_libbmp.h>
# include <libft.h>
# include <math.h>
# include <stdbool.h>
# include <stdio.h>
# include <time.h>

/******************************************************************************\
 * ALGEBRA
\******************************************************************************/

typedef struct s_quadratic_result
{
	double				a;
	double				half_b;
	double				c;
	double				discriminant;
	double				d_sqrt;
	double				root;
}						t_quadratic_result;

double					infinity(void);
double					pi(void);

double					degrees_to_radians(double degrees);
bool					quadratic(t_quadratic_result r,
							double min_translation,
							double max_translation,
							double *root);
double					schlicks_approximation(double cosine,
							double refraction_ratio);

/******************************************************************************\
 * VECTORS
\******************************************************************************/

typedef struct s_vector_3d
{
	double				x;
	double				y;
	double				z;
}						t_vector_3d;

typedef t_vector_3d		t_point_3d;

t_vector_3d				vector(double x, double y, double z);
t_vector_3d				vector_3d(double x, double y, double z);

void					inspect(t_vector_3d vector);

double					length_squared(t_vector_3d vector);
double					length(t_vector_3d vector);

t_vector_3d				negative(t_vector_3d vector);
t_vector_3d				unit(t_vector_3d vector);
t_vector_3d				vsqrt(t_vector_3d vector);

t_vector_3d				scalar_add(double number, t_vector_3d vector);
t_vector_3d				scalar_sub(double number, t_vector_3d vector);
t_vector_3d				scalar_times(double number, t_vector_3d vector);
t_vector_3d				scalar_div(double number, t_vector_3d vector);

double					dot(t_vector_3d first, t_vector_3d second);

t_vector_3d				add(t_vector_3d first, t_vector_3d second);
t_vector_3d				sub(t_vector_3d first, t_vector_3d second);
t_vector_3d				cross(t_vector_3d first, t_vector_3d second);
t_vector_3d				product(t_vector_3d first, t_vector_3d second);
t_vector_3d				division(t_vector_3d first, t_vector_3d second);

bool					near_zero(t_vector_3d vector);

t_vector_3d				reflect(t_vector_3d incident, t_vector_3d normal);
t_vector_3d				refract(t_vector_3d incident,
							t_vector_3d normal,
							double refration_ration);

typedef t_vector_3d		t_point_3d;

t_point_3d				point(double x, double y, double z);
t_point_3d				point_3d(double x, double y, double z);

/******************************************************************************\
 * COLORS
\******************************************************************************/

typedef t_vector_3d		t_color_3d;

typedef struct s_color_3i
{
	int					red;
	int					green;
	int					blue;
}						t_color_3i;

t_color_3d				color(double red, double green, double blue);
t_color_3d				color_3d(double red, double green, double blue);
t_color_3i				color_3i(int red, int green, int blue);

t_color_3i				color_3d_to_i3(t_color_3d color_3d);

t_color_3d				scale_and_gamma2_correct(t_color_3d sampled_color,
							const double scale);
t_color_3i				sample_pixel_color(t_color_3d sampled_color,
							int samples_per_pixel);
void					set_image_pixel(t_bitmap_image *image,
							t_color_3i color,
							int row,
							int column);

/******************************************************************************\
 * RANDOM
\******************************************************************************/

double					random_double(void);
double					random_from(double min, double max);
double					canonical_random(void);

t_vector_3d				random_vector(void);
t_vector_3d				random_vector_in(double min, double max);

double					rp(void);
double					rr(void);
t_color_3d				rc(void);
t_color_3d				rcr(double min, double max);

t_vector_3d				random_unit_vector(void);

t_point_3d				random_in_unit_sphere(void);
t_point_3d				random_in_unit_disk(void);
t_vector_3d				random_in_hemisphere(const t_vector_3d normal);

/******************************************************************************\
 * ERRORS
\******************************************************************************/

typedef enum e_rt_error
{
	BAD_ARGUMENTS = 1,
	GENERIC_RAY_TRACER_ERROR
}						t_rt_error;

void					kill_ray_tracer(t_rt_error code);
void					handle_arguments(int argument_count);

/******************************************************************************\
 * CAMERAS
\******************************************************************************/

typedef struct s_camera_params
{
	t_point_3d			look_from;
	t_point_3d			look_at;
	t_vector_3d			view_up;

	double				vertical_fov_degrees;
	double				aperture;
	double				focus_distance;
}						t_camera_params;

typedef struct s_camera
{
	t_vector_3d			basis_u;
	t_vector_3d			basis_v;
	t_vector_3d			basis_w;

	t_point_3d			origin;
	t_vector_3d			horizontal;
	t_vector_3d			vertical;
	t_point_3d			lower_left_corner;

	double				lens_radius;
}						t_camera;

void					initialize_camera(t_camera *camera,
							double aspect_ratio,
							t_camera_params p);

/******************************************************************************\
 * RAY TRACER
\******************************************************************************/

typedef struct s_ray_tracer
{
	char				*file_name;

	double				aspect_ratio;
	int					width;
	int					height;
	int					samples_per_pixel;
	int					max_depth;

	t_camera			camera;

	t_list				*materials;
	t_list				*spheres;
}						t_ray_tracer;

clock_t					log_start(t_ray_tracer rt);
clock_t					log_end(clock_t timer);

t_color_3i				trace_sample_rays(const t_ray_tracer rt,
							const t_camera camera,
							int row,
							int column);
void					generate_image(t_bitmap_image *image,
							const t_ray_tracer rt,
							const t_camera camera);
void					cleanup_ray_tracer(t_ray_tracer *rt);

/******************************************************************************\
 * RAYS
\******************************************************************************/

typedef struct s_ray
{
	t_point_3d			origin;
	t_vector_3d			direction;
}						t_ray;

t_ray					ray(t_point_3d origin, t_vector_3d direction);
t_point_3d				ray_at_t(double translation, t_ray ray);
t_ray					get_ray(const t_ray_tracer rt,
							const t_camera camera,
							int row,
							int column);
t_ray					get_sample_ray(const t_ray_tracer rt,
							const t_camera camera,
							int row,
							int column);

t_color_3d				hit_gradient_background(const t_ray ray,
							t_color_3d background_tone);
t_color_3d				hit_gradient_background(const t_ray ray,
							t_color_3d background_tone);
t_color_3d				cast_ray(const t_ray ray, t_list *spheres, int depth);

t_vector_3d				point_ray(t_camera camera,
							double horizontal,
							double vertical);
t_ray					set_ray(t_camera camera,
							double horizontal,
							double vertical);

t_vector_3d				point_ray_dof(t_camera camera,
							t_vector_3d offset,
							double horizontal,
							double vertical);
t_ray					set_ray_dof(t_camera camera,
							double horizontal,
							double vertical);

/******************************************************************************\
 * MATERIALS
\******************************************************************************/

typedef bool			(*t_scatter_callback)(t_ray incident_ray,
							void *void_record,
							t_color_3d *attenuation,
							t_ray *scattered_ray);

typedef struct s_material
{
	t_color_3d			albedo;
	double				fuzziness;
	double				refraction_index;
	t_scatter_callback	scattered;
}						t_material;

t_material				*prototype_material(t_scatter_callback scattered);
void					free_materials(t_list **materials);

t_material				*make_dielectric(double refraction_index);
bool					scatter_dielectric(t_ray incident_ray,
							void *void_record,
							t_color_3d *attenuation,
							t_ray *scattered_ray);

t_material				*make_matte(t_color_3d albedo);
bool					scatter_matte(t_ray incident_ray,
							void *void_record,
							t_color_3d *attenuation,
							t_ray *scattered_ray);

t_material				*make_metallic(t_color_3d albedo, double fuzziness);
bool					scatter_metallic(t_ray incident_ray,
							void *void_record,
							t_color_3d *attenuation,
							t_ray *scattered_ray);

/******************************************************************************\
 * HITTABLES
\******************************************************************************/

typedef struct s_hit_record
{
	t_point_3d			intersection;
	t_vector_3d			normal;
	t_material			*material;
	double				translation;
	bool				front_face;
}						t_hit_record;

void					set_record(t_hit_record *target, t_hit_record record);
void					set_face_normal(const t_ray ray,
							const t_vector_3d outward_normal,
							t_hit_record *record);

/******************************************************************************\
 * SPHERE
\******************************************************************************/

typedef struct s_sphere
{
	t_point_3d			center;
	double				radius;
	t_material			*material;
}						t_sphere;

t_sphere				*new_sphere(t_point_3d center,
							double radius,
							t_material *material);
void					free_spheres(t_list **spheres);
t_color_3d				render_sphere(t_ray ray,
							t_hit_record *record,
							t_list *spheres,
							int depth);

/******************************************************************************\
 * HITTABLE SPHERES
\******************************************************************************/

typedef struct s_vectorial_quadratic_params
{
	t_ray				ray;
	t_sphere			*sphere;

	double				min_translation;
	double				max_translation;

	double				*root;
}						t_vectorial_quadratic_params;

typedef struct s_ray_hits_sphere_params
{
	t_ray				ray;
	t_sphere			*sphere;
	t_hit_record		*record;

	double				t_min;
	double				t_max;
}						t_ray_hits_sphere_params;

bool					ray_hits_sphere(t_ray_hits_sphere_params p);

/******************************************************************************\
 * WORLD
\******************************************************************************/

typedef struct s_sphere_params
{
	t_list				**materials;
	t_list				**spheres;

	t_point_3d			center;
	double				radius;

	t_color_3d			albedo;
	double				fuzziness;
	double				refraction_index;
}						t_sphere_params;

void					create_matte_sphere(t_sphere_params p);
void					add_sphere(t_sphere_params p, t_material *material);
void					add_matte_sphere(t_sphere_params p);
void					add_metallic_sphere(t_sphere_params p);
void					add_dielectric_sphere(t_sphere_params p);

#endif
