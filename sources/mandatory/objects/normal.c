/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/24 11:56:07 by lpaulo-m          #+#    #+#             */
/*   Updated: 2023/01/05 19:59:36 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

t_v3d	normal_at(t_object *object, t_p3d point)
{
	t_v3d		result;
	t_matrix	inverse_matrix;
	t_matrix	transposed_matrix;

	mx_inverse(object->transform, 4, &inverse_matrix);
	point = mx_tuple_multiply(inverse_matrix, point);
	result = sub(point, object->origin);
	mx_transpose(inverse_matrix, &transposed_matrix);
	result = mx_tuple_multiply(transposed_matrix, result);
	result.type = 0.0;
	result = normalize(result);
	return (result);
}

t_v3d	reflect(t_v3d incident, t_v3d normal)
{
	t_v3d	result;

	result = scalar_times(2.0 * dot(incident, normal), normal);
	result = sub(incident, result);
	return (result);
}
