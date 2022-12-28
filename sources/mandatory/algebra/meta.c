/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   meta.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/03 16:49:56 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/12/28 16:16:56 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

t_t3d	neg(t_t3d tuple)
{
	tuple.x *= -1;
	tuple.y *= -1;
	tuple.z *= -1;
	tuple.type *= -1;
	return (tuple);
}

double	length_squared(t_v3d vector)
{
	double	x;
	double	y;
	double	z;

	x = vector.x * vector.x;
	y = vector.y * vector.y;
	z = vector.z * vector.z;
	return (x + y + z);
}

double	length(t_v3d vector)
{
	double	length_sqrd;

	length_sqrd = length_squared(vector);
	return (sqrt(length_sqrd));
}

double	magnitude(t_v3d vector)
{
	return (length(vector));
}

t_v3d	unit(t_v3d vector)
{
	double	magnitude;

	magnitude = length(vector);
	return (scalar_div(magnitude, vector));
}

t_v3d	normalize(t_v3d vector)
{
	return (unit(vector));
}

t_v3d	vsqrt(t_v3d vector)
{
	vector.x = sqrt(vector.x);
	vector.y = sqrt(vector.y);
	vector.z = sqrt(vector.z);
	return (vector);
}
