/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_fast.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 18:14:11 by lpaulo-m          #+#    #+#             */
/*   Updated: 2023/02/25 17:03:07 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

void	fast_rotate_object(t_object *object, t_v3d new_normal)
{
	t_matrix	rotation_mx;
	t_matrix	rot_z;
	t_matrix	rot_y;
	double		alpha;
	double		beta;

	alpha = atan2(
			sqrt(new_normal.x * new_normal.x + new_normal.z * new_normal.z),
			new_normal.y);
	beta = atan2(new_normal.z, new_normal.x);
	rotation_z(-alpha, &rot_z);
	rotation_y(-beta, &rot_y);
	mxs_multiply(rot_y, rot_z, &rotation_mx);
	multiply_transform(object, rotation_mx);
}
