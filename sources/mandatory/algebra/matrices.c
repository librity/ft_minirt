/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrices.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 20:54:40 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/12/30 10:30:53 by lpaulo-m         ###   ########.fr       */
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

void	mx_transpose(t_matrix matrix, t_matrix *result)
{
	mx_set_row(result, mx_get_column(matrix, 0), 0);
	mx_set_row(result, mx_get_column(matrix, 1), 1);
	mx_set_row(result, mx_get_column(matrix, 2), 2);
	mx_set_row(result, mx_get_column(matrix, 3), 3);
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