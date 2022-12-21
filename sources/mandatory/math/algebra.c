/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algebra.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 21:58:26 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/12/21 18:20:30 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

double	degrees_to_radians(double degrees)
{
	double	pi;

	pi = M_PI;
	return ((degrees * pi) / 180.0);
}

t_root	quadratic(double a, double b, double c)
{
	t_root	roots;

	roots.delta = b * b - 4 * a * c;
	if (roots.delta < 0)
	{
		roots.has_root = false;
		return (roots);
	}
	roots.root_a = (-b + sqrt(roots.delta)) / (2 * a);
	roots.root_b = (-b - sqrt(roots.delta)) / (2 * a);
	return (roots);
}
