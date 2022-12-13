/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/27 03:39:53 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/12/13 19:28:46 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

# include <stdbool.h>

# include <vectors.h>
# include <ft_libbmp.h>

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
 * SCENE
\******************************************************************************/

typedef struct s_light
{
}				t_light;

typedef struct s_object
{
}				t_object;

/******************************************************************************\
 * CONTROL
\******************************************************************************/

typedef struct s_minirt
{
	int			argc;
	char		**argv;

	char		*scene_path;

	t_amb_light	ambient;

	t_list		**lights;
	t_list		**objects;

	t_list		**free_me;
}				t_minirt;

#endif
