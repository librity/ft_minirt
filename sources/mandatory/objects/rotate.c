/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 18:14:11 by lpaulo-m          #+#    #+#             */
/*   Updated: 2023/02/25 17:09:11 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

void	rotate_object(t_object *object, t_v3d new_normal)
{
	t_rotate_object	p;

	p.old_normal = object->normal;
	p.theta = acos(dot(p.old_normal, new_normal));
	p.cos_theta = cos(p.theta);
	p.rotation_axis = cross(p.old_normal, new_normal);
	mx_set_identity(&p.identity_mx);
	mx_scalar_multiply(&p.identity_mx, p.cos_theta);
	skew_symmetric_matrix(p.rotation_axis, &p.skew_mx);
	mx_scalar_multiply(&p.skew_mx, sin(p.theta));
	mx_clear(&p.axis_mx);
	p.axis_mx[0][0] = p.rotation_axis.x;
	p.axis_mx[1][0] = p.rotation_axis.y;
	p.axis_mx[2][0] = p.rotation_axis.z;
	mx_clear(&p.axis_transposed_mx);
	p.axis_transposed_mx[0][0] = p.rotation_axis.x;
	p.axis_transposed_mx[0][1] = p.rotation_axis.y;
	p.axis_transposed_mx[0][2] = p.rotation_axis.z;
	mxs_multiply(p.axis_mx, p.axis_transposed_mx, &p.axis_scaled_mx);
	mx_scalar_multiply(&p.axis_scaled_mx, (1.0 - p.cos_theta));
	mx_add(p.identity_mx, p.skew_mx, &p.mx_1);
	mx_add(p.mx_1, p.axis_scaled_mx, &p.mx_2);
	multiply_transform(object, p.mx_2);
}
