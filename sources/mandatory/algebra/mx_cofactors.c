/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mx_cofactors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 20:54:40 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/12/30 14:58:32 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

static double	cofactor(double minor, int row, int column)
{
	if ((row + column) % 2 != 0)
		return (-minor);
	return (minor);
}

double	mx_2by2_minor(t_matrix matrix, int row, int column)
{
	t_matrix	mx_sub;

	mx_submatrix(matrix, row, column, &mx_sub);
	return (mx_2by2_determinant(mx_sub));
}

double	mx_2by2_cofactor(t_matrix matrix, int row, int column)
{
	double	minor;

	minor = mx_2by2_minor(matrix, row, column);
	return (cofactor(minor, row, column));
}

double	mx_cofactor(t_matrix matrix, int size, int row, int column)
{
	t_matrix	sub;
	double		determinant;

	mx_submatrix(matrix, row, column, &sub);
	determinant = mx_determinant(sub, size - 1);
	return (cofactor(determinant, row, column));
}
