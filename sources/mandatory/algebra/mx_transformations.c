/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mx_transformations.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 20:54:40 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/12/30 14:43:09 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

void	mx_transpose(t_matrix matrix, t_matrix *result)
{
	mx_set_row(result, mx_get_column(matrix, 0), 0);
	mx_set_row(result, mx_get_column(matrix, 1), 1);
	mx_set_row(result, mx_get_column(matrix, 2), 2);
	mx_set_row(result, mx_get_column(matrix, 3), 3);
}

void	mx_submatrix(t_matrix matrix, int row, int column, t_matrix *result)
{
	mx_copy(matrix, result);
	mx_shuffle_row_bottom(result, row);
	mx_shuffle_column_right(result, column);
	mx_set_column(result, null_tuple(), 3);
	mx_set_row(result, null_tuple(), 3);
}
