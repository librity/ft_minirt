/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algebra.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/27 03:39:53 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/12/30 14:10:17 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ALGEBRA_H
# define ALGEBRA_H

# include <ft_libbmp.h>
# include <math.h>
# include <stdio.h>

# define NEAR_ZERO_TOLERANCE 1E-4

bool			doubles_are_equal(double a, double b);

/******************************************************************************\
 * TUPLES
\******************************************************************************/

# define VECTOR_TYPE 0.0
# define POINT_TYPE 1.0
# define COLOR_TYPE 0.0

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
double			magnitude(t_v3d vector);

t_v3d			unit(t_v3d vector);
t_v3d			normalize(t_v3d vector);
t_v3d			vsqrt(t_v3d vector);

double			dot(t_v3d first, t_v3d second);
t_v3d			cross(t_v3d first, t_v3d second);

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

# define COLOR_MIN 0
# define COLOR_MAX 255

typedef t_t3d	t_c3d;

t_c3d			color(double red, double green, double blue);
t_c3d			color_3d(double red, double green, double blue);

t_rgb			c3d_to_rgb(t_c3d color_3d);
t_c3d			rgb_to_c3d(t_rgb color_rgb);
t_c3d			rgb_to_bright_c3d(double brightness, t_rgb color_rgb);
void			mlx_image_draw_c3d(t_mlx_image *image, t_c3d color,
					int x, int y);

/******************************************************************************\
 * MATRICES
\******************************************************************************/

typedef double	t_matrix[4][4];

void			mx_inspect(t_matrix matrix);

typedef struct s_set_matrix
{
	double		a1;
	double		a2;
	double		a3;
	double		a4;

	double		b1;
	double		b2;
	double		b3;
	double		b4;

	double		c1;
	double		c2;
	double		c3;
	double		c4;

	double		d1;
	double		d2;
	double		d3;
	double		d4;
}				t_mx_set;
typedef union mx_set_union
{
	t_mx_set	set;
	double		values[16];
}				t_mx_set_union;
void			mx_set(t_matrix *matrix, t_mx_set set);
void			mx_set_identity(t_matrix *matrix);
void			mx_copy(t_matrix matrix, t_matrix *result);

void			mx_clear(t_matrix *matrix);
bool			mxs_are_equal(t_matrix matrix_a, t_matrix matrix_b);

t_t3d			mx_get_row(t_matrix mx, int index);
void			mx_set_row(t_matrix *matrix, t_t3d row, int index);
void			mx_switch_row(t_matrix *matrix, int a, int b);
void			mx_swtich_column(t_matrix *matrix, int index);
void			mx_shuffle_row_bottom(t_matrix *matrix, int index);

t_t3d			mx_get_column(t_matrix mx, int index);
void			mx_set_column(t_matrix *matrix, t_t3d column, int index);
void			mx_switch_column(t_matrix *matrix, int a, int b);
void			mx_shuffle_column_right(t_matrix *matrix, int index);

void			mxs_multiply(t_matrix a, t_matrix b, t_matrix *result);
t_t3d			mx_tuple_multiply(t_matrix matrix, t_t3d tuple);

void			mx_transpose(t_matrix matrix, t_matrix *result);

double			mx_2by2_determinant(t_matrix mx_2by2);

void			mx_submatrix(t_matrix matrix, int row, int column,
					t_matrix *result);
double			mx_minor(t_matrix matrix, int row, int column);
double			mx_cofactor(t_matrix matrix, int row, int column);


#endif
