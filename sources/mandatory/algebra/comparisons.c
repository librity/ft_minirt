/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   geometry.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/03 16:34:17 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/12/29 21:11:48 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <algebra.h>

static double	abs_d(double number)
{
	if (number < 0)
		return (number * -1);
	return (number);
}

bool	near_zero(t_v3d vector)
{
	bool	cuts_off_x;
	bool	cuts_off_y;
	bool	cuts_off_z;

	cuts_off_x = abs_d(vector.x) < NEAR_ZERO_TOLERANCE;
	cuts_off_y = abs_d(vector.y) < NEAR_ZERO_TOLERANCE;
	cuts_off_z = abs_d(vector.z) < NEAR_ZERO_TOLERANCE;
	return (cuts_off_x && cuts_off_y && cuts_off_z);
}
