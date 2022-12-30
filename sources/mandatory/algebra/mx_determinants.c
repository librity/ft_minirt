/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mx_determinants.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 20:54:40 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/12/30 14:46:35 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

double	mx_2by2_determinant(t_matrix mx_2by2)
{
	double	ad;
	double	bc;

	ad = mx_2by2[0][0] * mx_2by2[1][1];
	bc = mx_2by2[0][1] * mx_2by2[1][0];
	return (ad - bc);
}

double	mx_3by3_determinant(t_matrix matrix)
{
	int		i;
	double	determinant;

	i = 0;
	determinant = 0;
	while (i < 3)
	{
		determinant += mx_2by2_cofactor(matrix, 0, i) * matrix[0][i];
		i++;
	}
	return (determinant);
}

double	mx_4by4_determinant(t_matrix matrix)
{
	int		i;
	double	determinant;

	i = 0;
	determinant = 0;
	while (i < 4)
	{
		determinant += mx_3by3_cofactor(matrix, 0, i) * matrix[0][i];
		i++;
	}
	return (determinant);
}
