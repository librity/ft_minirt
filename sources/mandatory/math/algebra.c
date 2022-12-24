/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algebra.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 21:58:26 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/12/24 10:45:10 by lpaulo-m         ###   ########.fr       */
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
	roots.has_root = false;
	if (roots.delta < 0)
		return (roots);
	roots.has_root = true;
	roots.root_a = (-b + sqrt(roots.delta)) / (2 * a);
	roots.root_b = (-b - sqrt(roots.delta)) / (2 * a);
	return (roots);
}

void	inspect_root(t_root root)
{
	printf("=== root ===\n");
	printf("\troot_a: %f\n", root.root_a);
	printf("\troot_b: %f\n", root.root_b);
	printf("\tdelta: %f\n", root.delta);
	printf("\thas_root: %d\n", root.has_root);
}
