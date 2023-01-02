/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mx_multiply.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 10:02:23 by lpaulo-m          #+#    #+#             */
/*   Updated: 2023/01/02 18:39:39 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

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

t_mx	matrix_multiply(t_mx a, t_mx b)
{
	t_mx	result;
	int		i;
	int		j;

	mx_clear(&result);
	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			result.arr[i][j] = dot(
					mx_get_row(a.arr, i),
					mx_get_column(b.arr, j));
			j++;
		}
		i++;
	}
	return (result);
}
