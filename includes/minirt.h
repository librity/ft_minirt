/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/27 03:39:53 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/12/18 22:44:39 by lpaulo-m         ###   ########.fr       */
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

/******************************************************************************\
 * CONTROL
\******************************************************************************/

t_minirt	*c(void);
void		initialize_control(int argc, char **argv);

bool		debug(void);
void		enable_debug(void);

int			argc(void);
void		set_argc(int path);
char		**argv(void);
void		set_argv(char **path);

char		*scene_path(void);
void		set_scene_path(char *path);

t_amb_light	ambient_light(void);
void		set_ambient_light(double brightness, t_rgb color);
void		inspect_ambient_light(void);

t_camera	camera(void);
void		set_camera(t_p3d origin, t_v3d orientation, double horz_fov_deg);
void		inspect_camera(void);

t_light		light(void);
void		set_light(t_p3d origin, double brightness);
void		inspect_light(void);

t_dlist		**objects(void);
void		inspect_objects(void);

t_list		**lalloc(void);
void		free_lalloc(void);

/******************************************************************************\
 * VALIDATOR
\******************************************************************************/

void		validate_scene(void);

char		*jump_spaces(char *line);
int			ft_isfloat(char **nptr);
char		*jump_info(char *line);
int			validate_camera(char *line);
int			check_coordinate(char *line);
int			check_norm_coordinate(char *line);
int			validate_fov(char *line);
void		free_array(void **array);
int			validate_ambient(char *line);
int			check_color(char *line);
int			is_rgb(char *line);
int			check_amb_light(char *line);
char		*get_next_info(char *line);
int			validate_light(char *line);
int			validate_sphere(char *line);
int			validate_plane(char *line);
int			validate_cylinder(char *line);
t_val_scene	*val_scene();
void		val_scene_init(void);
int			check_scene(void);

/******************************************************************************\
 * PARSER
\******************************************************************************/

void		parse_scene(void);

void		parse_ambient_light(char *line);
void		parse_camera(char *line);
void		parse_light(char *line);

void		parse_sphere(char *line);
void		parse_plane(char *line);
void		parse_cylinder(char *line);

t_rgb		parse_color(char *line);
t_v3d		parse_vector(char *line);
t_p3d		parse_point(char *line);
char		*skip_field(char *line);

/******************************************************************************\
 * SPHERES
\******************************************************************************/

void		create_sphere(t_p3d origin, double diameter, t_rgb color);

/******************************************************************************\
 * PLANES
\******************************************************************************/

void		create_plane(t_p3d origin, t_p3d normal, t_rgb color);

/******************************************************************************\
 * CYLINDERS
\******************************************************************************/

typedef struct s_create_cylinder
{
	t_p3d	origin;
	t_p3d	normal;
	double	diameter;
	double	height;
	t_rgb	color;
}			t_create_cylinder;
void		create_cylinder(t_create_cylinder p);

/******************************************************************************\
 * FILES
\******************************************************************************/

int			open_or_die(char *path);
void		close_or_die(int fd);

/******************************************************************************\
 * MATH
\******************************************************************************/

double		degrees_to_radians(double degrees);

/******************************************************************************\
 * RUNTIME
\******************************************************************************/

void		quit(void);
void		die(char *error_message);

void		cleanup(void);

#endif
