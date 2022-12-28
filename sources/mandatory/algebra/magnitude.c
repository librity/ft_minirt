/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   magnitude.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 17:42:18 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/12/28 17:42:53 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <algebra.h>

double	length_squared(t_v3d vector)
{
	double	x;
	double	y;
	double	z;
	double	type;

	x = vector.x * vector.x;
	y = vector.y * vector.y;
	z = vector.z * vector.z;
	type = vector.type * vector.type;
	return (x + y + z + type);
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
