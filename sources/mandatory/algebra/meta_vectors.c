/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   meta_vectors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/03 16:49:56 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/12/28 17:48:42 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <algebra.h>

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
