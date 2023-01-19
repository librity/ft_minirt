/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/27 03:39:53 by lpaulo-m          #+#    #+#             */
/*   Updated: 2023/01/19 20:07:52 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include <X11/Xlib.h>
# include <defines.h>
# include <errors.h>
# include <fcntl.h>
# include <float.h>
# include <ft_libbmp.h>
# include <libft.h>
# include <math.h>
# include <stdbool.h>
# include <stdio.h>
# include <structs.h>
# include <warnings.h>

/******************************************************************************\
 * CONTROL
\******************************************************************************/

t_minirt		*c(void);
void			initialize_control(int argc, char **argv);

bool			debug(void);
void			enable_debug(void);

int				argc(void);
void			set_argc(int path);
char			**argv(void);
void			set_argv(char **path);

char			*scene_path(void);
void			set_scene_path(char *path);

t_amb_light		ambient_light(void);
void			set_ambient_light(double brightness, t_rgb color);
void			inspect_ambient_light(void);

t_camera		camera(void);
t_mlx_image		*camera_buffer(void);
void			destroy_camera(void);
void			set_camera(t_p3d origin, t_v3d orientation,
					double horz_fov_deg);
void			set_challenge_camera(int width, int height, double horz_fov_rad);
void			inspect_camera(void);
int				width(void);
int				height(void);
double			aspect_ratio(void);
void			set_camera_transform(t_matrix transform);

t_light			light(void);
void			set_light(t_p3d origin, double brightness);
void			inspect_light(void);

t_dlist			**objects(void);
void			inspect_object(t_object *object);
void			inspect_objects(void);

void			*mlx(void);
void			initialize_mlx(void);
void			destroy_mlx(void);

void			*window(void);
void			initialize_window(void);
void			destroy_window(void);

t_list			**world_lalloc(void);
void			free_world_lalloc(void);
t_list			**ray_lalloc(void);
void			free_ray_lalloc(void);

/******************************************************************************\
 * VALIDATOR
\******************************************************************************/

void			validate_scene(void);

char			*jump_spaces(char *line);
int				ft_isfloat(char **nptr);
char			*jump_info(char *line);
int				validate_camera(char *line);
int				check_coordinate(char *line);
int				check_norm_coordinate(char *line);
int				validate_fov(char *line);
void			free_array(void **array);
int				validate_ambient(char *line);
int				check_color(char *line);
int				is_rgb(char *line);
int				check_amb_light(char *line);
char			*get_next_info(char *line);
int				validate_light(char *line);
int				validate_sphere(char *line);
int				validate_plane(char *line);
int				validate_cylinder(char *line);
t_val_scene		*val_scene();
void			val_scene_init(void);
int				check_scene(void);

/******************************************************************************\
 * PARSER
\******************************************************************************/

void			parse_scene(void);

void			parse_ambient_light(char *line);
void			parse_camera(char *line);
void			parse_light(char *line);

void			parse_sphere(char *line);
void			parse_plane(char *line);
void			parse_cylinder(char *line);

t_rgb			parse_color(char *line);
t_v3d			parse_vector(char *line);
t_p3d			parse_point(char *line);
char			*skip_field(char *line);

/******************************************************************************\
 * TRANSFORMATIONS
\******************************************************************************/

void			translation(t_v3d trans_vector, t_matrix *result);
void			scaling(t_v3d vector, t_matrix *result);

void			rotation_x(double radians, t_matrix *result);
void			rotation_y(double radians, t_matrix *result);
void			rotation_z(double radians, t_matrix *result);

typedef struct s_shearing
{
	double		xy;
	double		xz;
	double		yx;
	double		yz;
	double		zx;
	double		zy;
}				t_shearing;
void			shearing(t_shearing shear, t_matrix *result);

void			view_transformation(t_p3d from, t_p3d to, t_v3d up,
					t_matrix *result);

/******************************************************************************\
 * SCENE
\******************************************************************************/

t_light			point_light(t_p3d point, double brightness, t_rgb color_rgb);

/******************************************************************************\
 * MATERIAL
\******************************************************************************/

t_material		material(void);

t_c3d			lighting(t_material material, t_light light, t_p3d point, t_v3d eye, t_v3d normal);

/******************************************************************************\
 * OBJECTS
\******************************************************************************/

void			create_object(t_object *object);

void			set_transform(t_object *object, t_matrix mx);

t_v3d			normal_at(t_object *object, t_p3d point);
t_v3d			reflect(t_v3d incident, t_v3d normal);

/******************************************************************************\
 * WORLD
\******************************************************************************/

void			render(void);

t_c3d			color_at(t_ray _ray);
void			set_default_world(void);

t_intxs			intersect_world(t_ray	ray);
t_ray_comp		prepare_computations(t_intx intersect, t_ray _ray);
t_c3d			shade_hit(t_ray_comp comp);

t_ray			ray_for_pixel(int x, int y);

/******************************************************************************\
 * SPHERES
\******************************************************************************/

t_object		*new_sphere(t_p3d origin, double diameter, t_rgb color);
t_object		*sphere(void);
t_object		*create_sphere(t_p3d origin, double diameter, t_rgb color);

bool			ray_hits_sphere(t_ray ray, t_object sphere);
t_hit_result	ray_hits_sphere_result(t_ray ray, t_object sphere);

t_intxs		intersect(t_object *sphere, t_ray ray);
t_intx	*new_intersection(double t, t_object *object);
void			create_intersection(t_dlist **intersections, double t, t_object *object);

t_intx	*hit(t_intxs intersect);

/******************************************************************************\
 * PLANES
\******************************************************************************/

void			create_plane(t_p3d origin, t_p3d normal, t_rgb color);

/******************************************************************************\
 * CYLINDERS
\******************************************************************************/

typedef struct s_create_cylinder
{
	t_p3d		origin;
	t_p3d		normal;
	double		diameter;
	double		height;
	t_rgb		color;
}				t_create_cylinder;
void			create_cylinder(t_create_cylinder p);

/******************************************************************************\
 * MLX
\******************************************************************************/

void			mlx_image_save_ppm(t_mlx_image *image, char *filename);

/******************************************************************************\
 * SORTERS
\******************************************************************************/

void			sort_intersections(t_dlist **intersections);

/******************************************************************************\
 * FILES
\******************************************************************************/

int				open_or_die(char *path);
void			close_or_die(int fd);

/******************************************************************************\
 * RUNTIME
\******************************************************************************/

void			quit(void);
void			die(char *error_message);

void			cleanup(void);

/******************************************************************************\
 * DEMOS
\******************************************************************************/

void			red_window_demo(void);
void			hello_world_window_demo(void);

void			quadratic_demo(void);
void			hit_sphere_demo(void);

void			verify_closest_sphere(t_ray ray);
void			create_demo_spheres(void);

typedef struct s_projectile
{
	t_p3d		position;
	t_v3d		velocity;
}				t_projectile;
typedef struct s_environment
{
	t_v3d		gravity;
	t_v3d		wind;
}				t_environment;
t_projectile	tick(t_environment env, t_projectile projectile);
void			projectile_demo(void);
void			projectile_ppm_demo();
void			hello_world_ppm_demo(void);

void			clock_hours_ppm_demo(void);
void			clock_sec_ppm_demo(void);

void			ray_tracer_v1_demo();
void			ray_tracer_v2_demo();
void			ray_tracer_v3_demo();

#endif
