/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algebra.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/27 03:39:53 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/12/28 15:48:20 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ALGEBRA_H
# define ALGEBRA_H

# include <ft_libbmp.h>
# include <math.h>

# define NEAR_ZERO_TOLERANCE 1E-4

/******************************************************************************\
 * TUPLES
\******************************************************************************/

# define VECTOR_TYPE 0
# define POINT_TYPE 1
# define COLOR_TYPE 2
# define NULL_TYPE 3

typedef struct s_t3d
{
	double		x;
	double		y;
	double		z;
	double		type;
}				t_t3d;

t_t3d			tuple(double x, double y, double z, double type);
t_t3d			tuple_3d(double x, double y, double z, double type);
t_t3d			null_tuple(void);
void			inspect_tuple(t_t3d tuple);

t_t3d			add(t_t3d first, t_t3d second);
t_t3d			sub(t_t3d first, t_t3d second);
t_t3d			cross(t_t3d first, t_t3d second);
t_t3d			product(t_t3d first, t_t3d second);
t_t3d			division(t_t3d first, t_t3d second);

t_t3d			neg(t_t3d tuple);

t_t3d			scalar_add(double number, t_t3d tuple);
t_t3d			scalar_sub(double number, t_t3d tuple);
t_t3d			scalar_times(double number, t_t3d tuple);
t_t3d			scalar_div(double number, t_t3d tuple);

/******************************************************************************\
 * VECTORS
\******************************************************************************/

typedef t_t3d	t_v3d;

t_v3d			vector(double x, double y, double z);
t_v3d			vector_3d(double x, double y, double z);

void			inspect_v3d(t_v3d vector);

double			length_squared(t_v3d vector);
double			length(t_v3d vector);

t_v3d			unit(t_v3d vector);
t_v3d			vsqrt(t_v3d vector);

double			dot(t_v3d first, t_v3d second);

bool			near_zero(t_v3d vector);

/******************************************************************************\
 * POINTS
\******************************************************************************/

typedef t_t3d	t_p3d;

t_p3d			point(double x, double y, double z);
t_p3d			point_3d(double x, double y, double z);
void			inspect_p3d(t_v3d point);

/******************************************************************************\
 * COLORS
\******************************************************************************/

typedef t_v3d	t_c3d;

t_c3d			color_3d(double red, double green, double blue);

t_rgb			c3d_to_rgb(t_c3d color_3d);
t_c3d			rgb_to_c3d(t_rgb color_rgb);
t_c3d			rgb_to_bright_c3d(double brightness, t_rgb color_rgb);

#endif
