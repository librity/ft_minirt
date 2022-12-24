/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hits.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 19:08:10 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/12/24 11:11:21 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

bool	ray_hits_sphere(t_ray ray, t_object sphere)
{
	t_root	root;
	t_v3d	oc;
	double	a;
	double	b;
	double	c;

	oc = sub(ray.origin, sphere.origin);
	a = length_squared(ray.direction);
	b = 2.0 * dot(oc, ray.direction);
	c = length_squared(oc) - (sphere.radius * sphere.radius);
	root = quadratic(a, b, c);
	inspect_root(root);
	if (!root.has_root)
		return (false);
	if (root.root_a < 0 && root.root_b < 0)
		return (false);
	return (true);
}
