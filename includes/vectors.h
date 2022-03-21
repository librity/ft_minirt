/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vectors.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/27 03:39:53 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/03/20 22:02:59 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTORS_H
# define VECTORS_H

# include <ft_libbmp.h>

/******************************************************************************\
 * ALGEBRA
\******************************************************************************/

double			infinity(void);

double			degrees_to_radians(double degrees);

typedef struct s_quadratic
{
	double		a;
	double		half_b;
	double		c;
	double		discriminant;
	double		d_sqrt;
	double		root;
}				t_quadratic;
bool			quadratic(t_quadratic r, double min_translation,
				double max_translation, double *root);

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

void			inspect(t_v3d vector);

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

t_c3d			color(double red, double green, double blue);
t_c3d			color_3d(double red, double green, double blue);
t_rgb			color_rgb(unsigned char red, unsigned char green,
				unsigned char blue);

t_rgb			c3d_to_rgb(t_c3d color_3d);
t_c3d			rgb_to_c3d(t_rgb color_rgb);

t_rgb			get_gamma2_pixel(t_c3d color_3d);

/******************************************************************************\
 * RANDOM
\******************************************************************************/

double			random_double(void);
double			random_from(double min, double max);
double			canonical_random(void);

t_v3d			random_vector(void);
t_v3d			random_vector_in(double min, double max);

double			rp(void);
double			rr(void);
t_c3d			rc(void);
t_c3d			rcr(double min, double max);

t_v3d			random_unit_vector(void);

t_p3d			random_in_unit_sphere(void);
t_p3d			random_in_unit_disk(void);
t_v3d			random_in_hemisphere(t_v3d normal);

#endif
