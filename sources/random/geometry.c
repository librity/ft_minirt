/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   geometry.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/03 16:10:04 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/03/14 22:33:45 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

t_v3d	random_unit_vector(void)
{
	t_v3d	normalized_in_sphere;

	normalized_in_sphere = unit(random_in_unit_sphere());
	return (normalized_in_sphere);
}

t_p3d	random_in_unit_sphere(void)
{
	t_p3d	random;

	while (true)
	{
		random = random_vector_in(-1.0, 1.0);
		if (length_squared(random) >= 1)
			continue ;
		return (random);
	}
}

t_p3d	random_in_unit_disk(void)
{
	t_p3d	random;

	while (true)
	{
		random = vector(random_from(-1.0, 1.0), random_from(-1.0, 1.0), 0);
		if (length_squared(random) >= 1)
			continue ;
		return (random);
	}
}

t_v3d	random_in_hemisphere(t_v3d normal)
{
	t_v3d	in_unit_sphere;

	in_unit_sphere = random_in_unit_sphere();
	if (dot(in_unit_sphere, normal) > 0.0)
		return (in_unit_sphere);
	return (negative(in_unit_sphere));
}
