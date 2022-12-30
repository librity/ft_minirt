/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mx_tuple.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 10:03:02 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/12/30 10:05:33 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

t_t3d	mx_tuple_multiply(t_matrix matrix, t_t3d tuple)
{
	t_t3d	result;

	result.x = dot(mx_get_row(matrix, 0), tuple);
	result.y = dot(mx_get_row(matrix, 1), tuple);
	result.z = dot(mx_get_row(matrix, 2), tuple);
	result.type = dot(mx_get_row(matrix, 3), tuple);
	return (result);
}
