/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algebra.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/28 03:23:51 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/03/14 21:37:21 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

double	infinity(void)
{
	double	inf;

	inf = DBL_MAX;
	return (inf);
}

double	pi(void)
{
	double	yum;

	yum = M_PI;
	return (yum);
}

double	degrees_to_radians(double degrees)
{
	double	pi;

	pi = M_PI;
	return ((degrees * pi) / 180.0);
}

bool	quadratic(t_quadratic r,
				double min_translation,
				double max_translation,
				double *root)
{
	r.discriminant = r.half_b * r.half_b - r.a * r.c;
	if (r.discriminant < 0)
		return (false);
	r.d_sqrt = sqrt(r.discriminant);
	r.root = (-r.half_b - r.d_sqrt) / r.a;
	if (r.root < min_translation || max_translation < r.root)
	{
		r.root = (-r.half_b + r.d_sqrt) / r.a;
		if (r.root < min_translation || max_translation < r.root)
			return (false);
	}
	*root = r.root;
	return (true);
}
