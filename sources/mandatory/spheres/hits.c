/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hits.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 19:08:10 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/12/24 10:43:26 by lpaulo-m         ###   ########.fr       */
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
	a = dot(ray.direction, ray.direction);
	b = 2 * dot(ray.direction, oc);
	c = dot(oc, oc) - (sphere.radius * sphere.radius);
	root = quadratic(a, b, c);
	inspect_root(root);
	return (root.has_root);
}
