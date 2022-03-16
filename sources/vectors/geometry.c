/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   geometry.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/03 16:34:17 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/03/14 22:58:59 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

bool	near_zero(t_v3d vector)
{
	bool	cuts_off_x;
	bool	cuts_off_y;
	bool	cuts_off_z;

	cuts_off_x = ft_abs_d(vector.x) < TOLERANCE;
	cuts_off_y = ft_abs_d(vector.y) < TOLERANCE;
	cuts_off_z = ft_abs_d(vector.z) < TOLERANCE;
	return (cuts_off_x && cuts_off_y && cuts_off_z);
}
