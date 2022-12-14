/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/27 03:39:53 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/12/14 19:41:14 by lpaulo-m         ###   ########.fr       */
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

int			argc(void);
void		set_argc(int path);
char		**argv(void);
void		set_argv(char **path);

t_amb_light	ambient_light(void);
void		set_ambient_light(double brightness, t_rgb color);
void		inspect_ambient_light(void);

t_camera	camera(void);
void		set_camera(t_p3d origin, t_v3d orientation, double horz_fov_deg);
void		inspect_camera(void);

t_light		light(void);
void		set_light(t_p3d origin, double brightness);
void		inspect_light(void);

char		*scene_path(void);
void		set_scene_path(char *path);

/******************************************************************************\
 * PARSER
\******************************************************************************/

void		parse_scene(void);

void		parse_ambient_light(char *line);
void		parse_camera(char *line);
void		parse_light(char *line);

t_rgb		parse_color(char *line);
t_v3d		parse_vector(char *line);
t_p3d		parse_point(char *line);

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
