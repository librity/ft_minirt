/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/24 10:28:03 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/12/24 12:12:12 by lpaulo-m         ###   ########.fr       */
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
	ray = ray_3d(point(0.0, 0.0, 0.0), vector(0.0, 0.0, 1.0));
	inspect_object(&sphere);
	hits_sphere = ray_hits_sphere(ray, sphere);
	printf("SHAPE? %d\n", sphere.shape);
	printf("RAY HITS SPHERE? %d\n", hits_sphere);
}

void	create_demo_spheres(void)
{
	create_sphere(point(10, 0, 0), 5, color_rgb(255, 0, 0));
	create_sphere(point(0, 10, 0), 5, color_rgb(255, 0, 0));
	create_sphere(point(0, 0, 10), 5, color_rgb(255, 0, 0));
	create_sphere(point(-10, 0, 0), 5, color_rgb(255, 0, 0));
	create_sphere(point(0, -10, 0), 5, color_rgb(255, 0, 0));
	create_sphere(point(0, 0, -10), 5, color_rgb(255, 0, 0));
	create_sphere(point(7, 0, 0), 5, color_rgb(255, 0, 0));
	create_sphere(point(15, 0, 0), 5, color_rgb(255, 0, 0));
}

/**
 * - [X] Criar mais esferas na list de objects
 * - [x] Percorrer essa lista e verificar se um raio arbitrário bate em todas as esferas
 * - [x] Pegar a esfera mais próxima e printar o traslado no terminal
 */
void	verify_closest_sphere(t_ray ray)
{
	t_dlist			*node;
	t_object		object;
	t_hit_result	result;
	double			closest;

	node = *objects();
	closest = DBL_MAX;
	while (node != NULL)
	{
		object = *(t_object *)node->content;
		if (object.shape != SPHERE_SHAPE)
		{
			node = node->next;
			continue ;
		}
		result = ray_hits_sphere_result(ray, object);
		printf("sphere: %d (%d)\thit_result: %d\t translation: %f\n",
				object.id,
				object.shape,
				result.hits,
				result.translation);

		if (result.hits && result.translation < closest)
			closest = result.translation;
		node = node->next;
	}
	printf("closest translation: %f\n", closest);
}
