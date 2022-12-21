/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/26 16:21:36 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/12/21 19:17:33 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

void	initialize(int argc, char **argv)
{
	if (argc != 2)
		die(ARGC_ERR);
	initialize_control(argc, argv);
	initialize_mlx();
	initialize_window();
	initialize_camera();
}

void	quadratic_demo(void)
{
	t_root	roots;

	roots = quadratic(1, -1, -2);
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
	ray = (t_ray){
		(t_p3d){0, 0, 0},
		(t_v3d){0, 0, 9},
	};

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
	printf("\nRAY HITS SPHERE? %d\n", hits_sphere);
}

void	run(void)
{
	printf("%s\n", scene_path());

	validate_scene();
	parse_scene();
	inspect_ambient_light();
	inspect_camera();
	inspect_light();
	inspect_objects();

	// quadratic_demo();
	//mlx_demo_img();
	hit_sphere_demo();

	mlx_hello_world_img();
	while (true);
}

int	main(int argc, char **argv)
{
	initialize(argc, argv);
	run();
	cleanup();
	return (EXIT_SUCCESS);
}
