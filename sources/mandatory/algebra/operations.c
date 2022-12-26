/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/03 16:43:25 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/12/26 15:30:42 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

static t_t3d_type	resolve_type(t_t3d_type first, t_t3d_type second)
{
	if (first && second)
		return (VECTOR_TYPE);
	return (POINT_TYPE);
}

t_t3d	add(t_t3d first, t_t3d second)
{
	t_t3d	result;

	result.x = first.x + second.x;
	result.y = first.y + second.y;
	result.z = first.z + second.z;
	result.type = resolve_type(first.type, second.type);
	return (result);
}

t_t3d	sub(t_t3d first, t_t3d second)
{
	t_t3d	result;

	result.x = first.x - second.x;
	result.y = first.y - second.y;
	result.z = first.z - second.z;
	return (result);
}

t_t3d	cross(t_t3d first, t_t3d second)
{
	t_t3d	result;

	result.x = first.y * second.z - first.z * second.y;
	result.y = first.z * second.x - first.x * second.z;
	result.z = first.x * second.y - first.y * second.x;
	return (result);
}

t_t3d	product(t_t3d first, t_t3d second)
{
	t_t3d	result;

	result.x = first.x * second.x;
	result.y = first.y * second.y;
	result.z = first.z * second.z;
	return (result);
}

t_t3d	division(t_t3d first, t_t3d second)
{
	t_t3d	result;

	result.x = first.x / second.x;
	result.y = first.y / second.y;
	result.z = first.z / second.z;
	return (result);
}
