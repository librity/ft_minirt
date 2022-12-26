/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/27 03:39:53 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/12/26 15:14:12 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include <X11/Xlib.h>
# include <defines.h>
# include <errors.h>
# include <fcntl.h>
# include <ft_libbmp.h>
# include <libft.h>
# include <math.h>
# include <stdbool.h>
# include <stdio.h>
# include <structs.h>
# include <warnings.h>
# include <float.h>

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
void			initialize_camera(void);
void			destroy_camera(void);
void			set_camera(t_p3d origin, t_v3d orientation,
					double horz_fov_deg);
void			inspect_camera(void);

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
int				width(void);
int				height(void);
double			aspect_ratio(void);

t_list			**lalloc(void);
void			free_lalloc(void);

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
 * OBJECTS
\******************************************************************************/

void			create_object(t_object *object);

/******************************************************************************\
 * SPHERES
\******************************************************************************/

void			create_sphere(t_p3d origin, double diameter, t_rgb color);

bool			ray_hits_sphere(t_ray ray, t_object sphere);
t_hit_result	ray_hits_sphere_result(t_ray ray, t_object sphere);
void			verify_closest_sphere(t_ray ray);
void			create_demo_spheres(void);

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
 * COLORS
\******************************************************************************/

t_c3d			color_3d(double red, double green, double blue);

t_rgb			c3d_to_rgb(t_c3d color_3d);
t_c3d			rgb_to_c3d(t_rgb color_rgb);
t_c3d			rgb_to_bright_c3d(double brightness, t_rgb color_rgb);

/******************************************************************************\
 * MLX
\******************************************************************************/

/******************************************************************************\
 * FILES
\******************************************************************************/

int				open_or_die(char *path);
void			close_or_die(int fd);

/******************************************************************************\
 * MATH
\******************************************************************************/

double			degrees_to_radians(double degrees);
t_root			quadratic(double a, double b, double c);
void			inspect_root(t_root root);

t_ray			ray_3d(t_p3d origin, t_v3d direction);
t_p3d			ray_at(t_ray r, double translation);

/******************************************************************************\
 * RUNTIME
\******************************************************************************/

void			quit(void);
void			die(char *error_message);

void			cleanup(void);

/******************************************************************************\
 * RUNTIME
\******************************************************************************/

void			mlx_demo_img(void);
void			mlx_hello_world_img(void);

void			quadratic_demo(void);
void			hit_sphere_demo(void);

#endif
