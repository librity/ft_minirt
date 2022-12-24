/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/24 10:28:03 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/12/24 10:48:28 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

void	quadratic_demo(void)
{
	t_root	roots;

	roots = quadratic(1, -1, -2);
	inspect_root(roots);
	printf("quadratic: root_a: %f\troot_b%f\n", roots.root_a, roots.root_b);
}

void	hit_sphere_demo(void)
{
	t_object	sphere;
	t_ray		ray;
	bool		hits_sphere;

	sphere = *((t_object *)(*objects())->next->next->content);
	// ray = (t_ray){
	// 	(t_p3d){0, 0, 0},
	// 	(t_v3d){0, 0, 0},
	// };
	ray = ray_3d(point(0.0, 0.0, -1.0), vector(0.1, 0.1, -0.9));
	inspect_object(&sphere);

// === object ===
//         shape: 1 (SPHERE)
//         origin: 0.000000 0.000000 20.000000
//         normal: 0.000000 0.000000 0.000000
//         diameter: 20.000000
//         radius: 10.000000
//         height: 0.000000
//         color_rgb: 255 0 0
//         color_3d: 1.000000 0.000000 0.000000


	hits_sphere = ray_hits_sphere(ray, sphere);
	printf("SHAPE? %d\n", sphere.shape);
	printf("RAY HITS SPHERE? %d\n", hits_sphere);
}
