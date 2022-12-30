/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mx_columns.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 10:28:42 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/12/30 11:51:21 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

void	mx_set_column(t_matrix *matrix, t_t3d column, int index)
{
	(*matrix)[0][index] = column.x;
	(*matrix)[1][index] = column.y;
	(*matrix)[2][index] = column.z;
	(*matrix)[3][index] = column.type;
}

t_t3d	mx_get_column(t_matrix mx, int index)
{
	t_t3d	column;

	column.x = mx[0][index];
	column.y = mx[1][index];
	column.z = mx[2][index];
	column.type = mx[3][index];
	return (column);
}

void	mx_switch_column(t_matrix *matrix, int a, int b)
{
	t_t3d	column_a;
	t_t3d	column_b;

	column_a = mx_get_column(*matrix, a);
	column_b = mx_get_row(*matrix, b);
	mx_set_column(matrix, column_a, b);
	mx_set_column(matrix, column_b, a);
}

void	mx_shuffle_column_right(t_matrix *matrix, int index)
{
	int	switches;

	switches = 3 - index;
	while (switches > 0)
	{
		mx_switch_column(matrix, index + 1, index);
		index++;
		switches--;
	}
}
