/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mx_inverse.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 15:04:53 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/12/30 15:31:54 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

bool	mx_is_invertible(t_matrix matrix, int size)
{
	if (mx_determinant(matrix, size))
		return (true);
	return (false);
}

static void	set_inverse_values(t_matrix matrix, int size, t_matrix *result,
		double det)
{
	int	i;
	int	j;

	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			(*result)[j][i] = mx_cofactor(matrix, size, i, j) / det;
			j++;
		}
		i++;
	}
}

void	mx_inverse(t_matrix matrix, int size, t_matrix *result)
{
	double	det;

	det = mx_determinant(matrix, size);
	if (det == 0.0)
	{
		mx_clear(result);
		return ;
	}
	set_inverse_values(matrix, size, result, det);
}
