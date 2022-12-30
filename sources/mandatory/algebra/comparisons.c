/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   comparisons.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/03 16:34:17 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/12/30 09:43:22 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <algebra.h>

bool	doubles_are_equal(double a, double b)
{
	if (fabs(a - b) < NEAR_ZERO_TOLERANCE)
		return (true);
	return (false);
}

bool	near_zero(t_v3d vector)
{
	bool	cuts_off_x;
	bool	cuts_off_y;
	bool	cuts_off_z;

	cuts_off_x = fabs(vector.x) < NEAR_ZERO_TOLERANCE;
	cuts_off_y = fabs(vector.y) < NEAR_ZERO_TOLERANCE;
	cuts_off_z = fabs(vector.z) < NEAR_ZERO_TOLERANCE;
	return (cuts_off_x && cuts_off_y && cuts_off_z);
}

bool	mxs_are_equal(t_matrix matrix_a, t_matrix matrix_b)
{
	int	i;
	int	j;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			if (doubles_are_equal(matrix_a[i][j], matrix_b[i][j]) == false)
				return (false);
			j++;
		}
		i++;
	}
	return (true);
}
