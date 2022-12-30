/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mx_multiply.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 10:02:23 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/12/30 10:05:38 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

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

void	mxs_multiply(t_matrix a, t_matrix b, t_matrix *result)
{
	int	i;
	int	j;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			(*result)[i][j] = dot(mx_get_row(a, i), mx_get_column(b, j));
			j++;
		}
		i++;
	}
}
