/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/27 03:39:53 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/12/09 14:02:11 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

// # include <X11/Xlib.h>
// # include <math.h>
# include <stdio.h>

# include <libft.h>
// # include <ft_libbmp.h>

# include <structs.h>
# include <defines.h>
# include <errors.h>
# include <warnings.h>

/******************************************************************************\
 * CONTROL
\******************************************************************************/

t_minirt	*c(void);
void	initialize_control(int argc, char **argv);

int		argc();
void	set_argc(int path);
char	**argv();
void	set_argv(char **path);

char		*scene_path();
void	set_scene_path(char *path);

/******************************************************************************\
 * PARSER
\******************************************************************************/

void	parse_scene(void);

/******************************************************************************\
 * RUNTIME
\******************************************************************************/

void print_error(char *error_message);
void die(char *error_message);

#endif
