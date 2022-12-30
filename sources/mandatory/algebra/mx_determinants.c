/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mx_determinants.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 20:54:40 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/12/30 14:56:34 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

double	mx_2by2_determinant(t_matrix matrix)
{
	double	ad;
	double	bc;

	ad = matrix[0][0] * matrix[1][1];
	bc = matrix[0][1] * matrix[1][0];
	return (ad - bc);
}

double	mx_determinant(t_matrix matrix, int size)
{
	int		i;
	double	determinant;

	if (size == 2)
		return (mx_2by2_determinant(matrix));
	i = 0;
	determinant = 0;
	while (i < size)
	{
		determinant += mx_cofactor(matrix, size, 0, i) * matrix[0][i];
		i++;
	}
	return (determinant);
}
