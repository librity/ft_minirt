/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrices.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 20:54:40 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/12/30 14:39:11 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

void	mx_set(t_matrix *matrix, t_mx_set set)
{
	t_mx_set_union	set_union;
	int				i;
	int				j;

	set_union.set = set;
	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			(*matrix)[i][j] = set_union.values[i * 4 + j];
			j++;
		}
		i++;
	}
}

void	mx_set_identity(t_matrix *matrix)
{
	mx_set(matrix, (t_mx_set){
		1, 0, 0, 0,
		0, 1, 0, 0,
		0, 0, 1, 0,
		0, 0, 0, 1});
}

void	mx_clear(t_matrix *matrix)
{
	int	i;
	int	j;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			(*matrix)[i][j] = 0.0;
			j++;
		}
		i++;
	}
}

void	mx_inspect(t_matrix matrix)
{
	inspect_tuple(mx_get_row(matrix, 0));
	inspect_tuple(mx_get_row(matrix, 1));
	inspect_tuple(mx_get_row(matrix, 2));
	inspect_tuple(mx_get_row(matrix, 3));
}

void	mx_transpose(t_matrix matrix, t_matrix *result)
{
	mx_set_row(result, mx_get_column(matrix, 0), 0);
	mx_set_row(result, mx_get_column(matrix, 1), 1);
	mx_set_row(result, mx_get_column(matrix, 2), 2);
	mx_set_row(result, mx_get_column(matrix, 3), 3);
}

double	mx_2by2_determinant(t_matrix mx_2by2)
{
	double	ad;
	double	bc;

	ad = mx_2by2[0][0] * mx_2by2[1][1];
	bc = mx_2by2[0][1] * mx_2by2[1][0];
	return (ad - bc);
}

void	mx_copy(t_matrix matrix, t_matrix *result)
{
	int	i;
	int	j;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			(*result)[i][j] = matrix[i][j];
			j++;
		}
		i++;
	}
}

void	mx_submatrix(t_matrix matrix, int row, int column, t_matrix *result)
{
	mx_copy(matrix, result);
	mx_shuffle_row_bottom(result, row);
	mx_shuffle_column_right(result, column);
	mx_set_column(result, null_tuple(), 3);
	mx_set_row(result, null_tuple(), 3);
}

double	mx_minor(t_matrix matrix, int row, int column)
{
	t_matrix	mx_sub;

	mx_submatrix(matrix, row, column, &mx_sub);
	return (mx_2by2_determinant(mx_sub));
}

double	cofactor(double	minor, int row, int column)
{
	if ((row + column) % 2 != 0)
		return (-minor);
	return (minor);
}

double	mx_2by2_cofactor(t_matrix matrix, int row, int column)
{
	double	minor;

	minor = mx_minor(matrix, row, column);
	return (cofactor(minor, row, column));
}

double	mx_3by3_determinant(t_matrix matrix)
{
	int 	i;
	double	determinant;

	i = 0;
	determinant = 0;
	while (i < 3)
	{
		determinant += mx_2by2_cofactor(matrix, 0, i) * matrix[0][i];
		i++;
	}
	return (determinant);
}

double	mx_3by3_cofactor(t_matrix matrix, int row, int column)
{
	t_matrix	sub;
	double		determinant;

	mx_submatrix(matrix, row, column, &sub);
	determinant = mx_3by3_determinant(sub);
	return (cofactor(determinant, row, column));
}

double	mx_4by4_determinant(t_matrix matrix)
{
	int		i;
	double	determinant;

	i = 0;
	determinant = 0;
	while (i < 4)
	{
		determinant += mx_3by3_cofactor(matrix, 0, i) * matrix[0][i];
		i++;
	}
	return (determinant);
}
