/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vectors.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/27 03:39:53 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/12/13 20:46:09 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTORS_H
# define VECTORS_H

# include <ft_libbmp.h>
# include <math.h>

# define NEAR_ZERO_TOLERANCE 1e-8

/******************************************************************************\
 * VECTORS
\******************************************************************************/

typedef struct s_v3d
{
	double		x;
	double		y;
	double		z;
}				t_v3d;

t_v3d			vector(double x, double y, double z);
t_v3d			vector_3d(double x, double y, double z);

void			inspect_v3d(t_v3d vector);

double			length_squared(t_v3d vector);
double			length(t_v3d vector);

t_v3d			negative(t_v3d vector);
t_v3d			unit(t_v3d vector);
t_v3d			vsqrt(t_v3d vector);

t_v3d			scalar_add(double number, t_v3d vector);
t_v3d			scalar_sub(double number, t_v3d vector);
t_v3d			scalar_times(double number, t_v3d vector);
t_v3d			scalar_div(double number, t_v3d vector);

double			dot(t_v3d first, t_v3d second);

t_v3d			add(t_v3d first, t_v3d second);
t_v3d			sub(t_v3d first, t_v3d second);
t_v3d			cross(t_v3d first, t_v3d second);
t_v3d			product(t_v3d first, t_v3d second);
t_v3d			division(t_v3d first, t_v3d second);

bool			near_zero(t_v3d vector);

/******************************************************************************\
 * POINTS
\******************************************************************************/

typedef t_v3d	t_p3d;

t_p3d			point(double x, double y, double z);
t_p3d			point_3d(double x, double y, double z);

/******************************************************************************\
 * COLORS
\******************************************************************************/

typedef t_v3d	t_c3d;

t_c3d			color_3d(double red, double green, double blue);

t_rgb			c3d_to_rgb(t_c3d color_3d);
t_c3d			rgb_to_c3d(t_rgb color_rgb);
t_c3d			rgb_to_bright_c3d(double brightness, t_rgb color_rgb);

t_rgb			gamma2_correct_pixel(t_c3d color_3d);

#endif
