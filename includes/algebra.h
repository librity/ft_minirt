/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algebra.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/27 03:39:53 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/12/26 15:30:06 by lpaulo-m         ###   ########.fr       */
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

typedef enum e_t3d_type
{
	VECTOR_TYPE,
	POINT_TYPE,
	COLOR_TYPE,
	NULL_TYPE,
}				t_t3d_type;

typedef struct s_t3d
{
	double		x;
	double		y;
	double		z;
	t_t3d_type	type;
}				t_t3d;

t_t3d			tuple(double x, double y, double z, t_t3d_type type);
void			inspect_t3d(t_t3d tuple);

/******************************************************************************\
 * VECTORS
\******************************************************************************/

typedef t_t3d	t_v3d;

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

t_t3d			add(t_t3d first, t_t3d second);
t_t3d			sub(t_t3d first, t_t3d second);
t_t3d			cross(t_t3d first, t_t3d second);
t_t3d			product(t_t3d first, t_t3d second);
t_t3d			division(t_t3d first, t_t3d second);

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

#endif
