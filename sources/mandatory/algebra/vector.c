/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/27 04:24:15 by lpaulo-m          #+#    #+#             */
/*   Updated: 2023/02/12 19:26:22 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <algebra.h>

t_v3d	vector(double x, double y, double z)
{
	return (vector_3d(x, y, z));
}

t_v3d	vector_3d(double x, double y, double z)
{
	return (tuple(x, y, z, VECTOR_TYPE));
}

void	inspect_v3d(t_v3d vector)
{
	printf("VECTOR: %f %f %f\n", vector.x, vector.y, vector.z);
}

double	dot(t_v3d first, t_v3d second)
{
	double	x;
	double	y;
	double	z;
	double	type;

	x = first.x * second.x;
	y = first.y * second.y;
	z = first.z * second.z;
	type = first.type * second.type;
	return (x + y + z + type);
}

t_v3d	cross(t_v3d first, t_v3d second)
{
	t_v3d	result;

	result.x = first.y * second.z - first.z * second.y;
	result.y = first.z * second.x - first.x * second.z;
	result.z = first.x * second.y - first.y * second.x;
	result.type = 0.0;
	return (result);
}
