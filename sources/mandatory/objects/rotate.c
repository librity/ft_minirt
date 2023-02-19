/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 18:14:11 by lpaulo-m          #+#    #+#             */
/*   Updated: 2023/02/19 18:17:17 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

void	rotate_object_by_normal(t_object *object, t_v3d new_normal)
{
	t_matrix	identity_mx;
	t_matrix	skew_mx;
	t_matrix	axis_mx;
	t_matrix	axis_transposed_mx;
	t_matrix	axis_scaled_mx;
	t_matrix	mx_1;
	t_matrix	mx_2;
	t_v3d		old_normal;
	t_v3d		rotation_axis;
	double		theta;
	double		cos_theta;

	old_normal = object->normal;
	theta = acos(dot(old_normal, new_normal));
	cos_theta = cos(theta);
	rotation_axis = cross(old_normal, new_normal);

	mx_set_identity(&identity_mx);
	mx_scalar_multiply(&identity_mx, cos_theta);

	skew_symmetric_matrix(rotation_axis, &skew_mx);
	mx_scalar_multiply(&skew_mx, sin(theta));

	mx_clear(&axis_mx);
	axis_mx[0][0] = rotation_axis.x;
	axis_mx[1][0] = rotation_axis.y;
	axis_mx[2][0] = rotation_axis.z;

	mx_clear(&axis_transposed_mx);
	axis_transposed_mx[0][0] = rotation_axis.x;
	axis_transposed_mx[0][1] = rotation_axis.y;
	axis_transposed_mx[0][2] = rotation_axis.z;

	mxs_multiply(axis_mx, axis_transposed_mx, &axis_scaled_mx);
	mx_scalar_multiply(&axis_scaled_mx, (1.0 - cos_theta));

	mx_add(identity_mx, skew_mx, &mx_1);
	mx_add(mx_1, axis_scaled_mx, &mx_2);
	multiply_transform(object, mx_2);
}
