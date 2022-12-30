/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mx_rows.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 10:28:42 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/12/30 11:51:16 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

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

void	mx_switch_row(t_matrix *matrix, int a, int b)
{
	t_t3d	row_a;
	t_t3d	row_b;

	row_a = mx_get_row(*matrix, a);
	row_b = mx_get_row(*matrix, b);
	mx_set_row(matrix, row_a, b);
	mx_set_row(matrix, row_b, a);
}

void	mx_shuffle_row_bottom(t_matrix *matrix, int index)
{
	int	switches;

	switches = 3 - index;
	while (switches > 0)
	{
		mx_switch_row(matrix, index, index + 1);
		index++;
		switches--;
	}
}
