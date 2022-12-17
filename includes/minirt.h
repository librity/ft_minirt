/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/27 03:39:53 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/12/17 14:30:50 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include <X11/Xlib.h>
# include <math.h>
# include <fcntl.h>
# include <stdbool.h>
# include <stdio.h>

# include <libft.h>
# include <ft_libbmp.h>

# include <defines.h>
# include <errors.h>
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

void		print_error(char *error_message);
void		die(char *error_message);

#endif
