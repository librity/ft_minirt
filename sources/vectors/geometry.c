/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   geometry.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/03 16:34:17 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/03/14 20:48:34 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

bool	near_zero(t_v3d vector)
{
	const float	cuttoff = 1e-8;
	const bool	cuts_off_x = ft_abs_d(vector.x) < cuttoff;
	const bool	cuts_off_y = ft_abs_d(vector.y) < cuttoff;
	const bool	cuts_off_z = ft_abs_d(vector.z) < cuttoff;

	return (cuts_off_x && cuts_off_y && cuts_off_z);
}

t_v3d	reflect(t_v3d incident, t_v3d normal)
{
	const double		factor = 2.0 * dot(incident, normal);
	const t_v3d	complement = scalar_times(factor, normal);

	return (sub(incident, complement));
}

t_v3d	refract(t_v3d incident,
					t_v3d normal,
					double refration_ration)
{
	t_v3d	refracted_perpendicular;
	t_v3d	refracted_parallel;
	t_v3d	refracted;
	double		cos_theta;
	double		parallel_magnitude;

	cos_theta = dot(negative(incident), normal);
	cos_theta = ft_min_d(cos_theta, 1.0);
	refracted_perpendicular = add(incident, scalar_times(cos_theta, normal));
	refracted_perpendicular = scalar_times(
			refration_ration, refracted_perpendicular);
	parallel_magnitude = 1.0 - length_squared(refracted_perpendicular);
	parallel_magnitude = ft_abs_d(parallel_magnitude);
	parallel_magnitude = -sqrt(parallel_magnitude);
	refracted_parallel = scalar_times(parallel_magnitude, normal);
	refracted = add(refracted_perpendicular, refracted_parallel);
	return (refracted);
}
