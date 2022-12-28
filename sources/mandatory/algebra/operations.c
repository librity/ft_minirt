/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/03 16:43:25 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/12/28 17:49:23 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <algebra.h>

t_t3d	add(t_t3d first, t_t3d second)
{
	t_t3d	result;

	if (first.type == POINT_TYPE && second.type == POINT_TYPE)
		return (null_tuple());
	result.x = first.x + second.x;
	result.y = first.y + second.y;
	result.z = first.z + second.z;
	result.type = first.type + second.type;
	return (result);
}

t_t3d	sub(t_t3d first, t_t3d second)
{
	t_t3d	result;

	if (first.type == VECTOR_TYPE && second.type == POINT_TYPE)
		return (null_tuple());
	result.x = first.x - second.x;
	result.y = first.y - second.y;
	result.z = first.z - second.z;
	result.type = first.type - second.type;
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
