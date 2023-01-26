/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 18:55:20 by lpaulo-m          #+#    #+#             */
/*   Updated: 2023/01/26 19:30:18 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

t_v3d	object_normal_at(t_object *object, t_p3d point)
{
	t_v3d		result;
	t_matrix	inverse_matrix;
	t_matrix	transposed_matrix;

	mx_inverse(object->transform, 4, &inverse_matrix);
	point = mx_tuple_multiply(inverse_matrix, point);
	result = object->normal_at(object, point);
	mx_transpose(inverse_matrix, &transposed_matrix);
	result = mx_tuple_multiply(transposed_matrix, result);
	result.type = 0.0;
	result = normalize(result);
	return (result);
}
