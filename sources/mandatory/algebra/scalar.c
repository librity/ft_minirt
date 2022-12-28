/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scalar.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/03 16:34:17 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/12/28 16:37:03 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

t_t3d	scalar_add(double number, t_t3d tuple)
{
	tuple.x += number;
	tuple.y += number;
	tuple.z += number;
	tuple.type += number;
	return (tuple);
}

t_t3d	scalar_sub(double number, t_t3d tuple)
{
	tuple.x -= number;
	tuple.y -= number;
	tuple.z -= number;
	tuple.type -= number;
	return (tuple);
}

t_t3d	scalar_times(double number, t_t3d tuple)
{
	tuple.x *= number;
	tuple.y *= number;
	tuple.z *= number;
	tuple.type *= number;
	return (tuple);
}

t_t3d	scalar_div(double number, t_t3d tuple)
{
	tuple.x /= number;
	tuple.y /= number;
	tuple.z /= number;
	tuple.type /= number;
	return (tuple);
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
