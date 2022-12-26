/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/03 16:43:25 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/12/26 13:48:08 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

t_v3d	add(t_v3d first, t_v3d second)
{
	t_v3d	result;

	result.x = first.x + second.x;
	result.y = first.y + second.y;
	result.z = first.z + second.z;
	return (result);
}

t_v3d	sub(t_v3d first, t_v3d second)
{
	t_v3d	result;

	result.x = first.x - second.x;
	result.y = first.y - second.y;
	result.z = first.z - second.z;
	return (result);
}

t_v3d	cross(t_v3d first, t_v3d second)
{
	t_v3d	result;

	result.x = first.y * second.z - first.z * second.y;
	result.y = first.z * second.x - first.x * second.z;
	result.z = first.x * second.y - first.y * second.x;
	return (result);
}

t_v3d	product(t_v3d first, t_v3d second)
{
	t_v3d	result;

	result.x = first.x * second.x;
	result.y = first.y * second.y;
	result.z = first.z * second.z;
	return (result);
}

t_v3d	division(t_v3d first, t_v3d second)
{
	t_v3d	result;

	result.x = first.x / second.x;
	result.y = first.y / second.y;
	result.z = first.z / second.z;
	return (result);
}
