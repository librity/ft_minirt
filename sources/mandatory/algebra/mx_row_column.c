/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mx_row_column.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 10:28:42 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/12/30 10:29:12 by lpaulo-m         ###   ########.fr       */
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

void	mx_set_row(t_matrix *matrix, t_t3d row, int index)
{
	(*matrix)[index][0] = row.x;
	(*matrix)[index][1] = row.y;
	(*matrix)[index][2] = row.z;
	(*matrix)[index][3] = row.type;
}

t_t3d	mx_get_row(t_matrix mx, int index)
{
	t_t3d	row;

	row.x = mx[index][0];
	row.y = mx[index][1];
	row.z = mx[index][2];
	row.type = mx[index][3];
	return (row);
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
