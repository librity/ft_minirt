/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   comparisons.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/03 16:34:17 by lpaulo-m          #+#    #+#             */
/*   Updated: 2023/01/26 19:43:05 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <algebra.h>

bool	near_zero(t_v3d vector)
{
	bool	cuts_off_x;
	bool	cuts_off_y;
	bool	cuts_off_z;

	cuts_off_x = double_near_zero(vector.x);
	cuts_off_y = double_near_zero(vector.y);
	cuts_off_z = double_near_zero(vector.z);
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
