/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/26 16:21:36 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/12/29 14:55:51 by lpaulo-m         ###   ########.fr       */
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
	// printf("%s\n", scene_path());
}

void	run(void)
{
	ppm_hello_world_img();
	// validate_scene();
	// parse_scene();
	// inspect_ambient_light();
	// inspect_camera();
	// inspect_light();
	// inspect_objects();

	// quadratic_demo();
	//mlx_demo_img();
	// hit_sphere_demo();
	// create_demo_spheres();
	// inspect_objects();
	// verify_closest_sphere(ray_3d(point(0, 0, 0), vector(1, 0, 0)));
	// mlx_hello_world_img();
	// while (true);

	//projectile_demo();
}

int	main(int argc, char **argv)
{
	initialize(argc, argv);
	run();
	cleanup();
	return (EXIT_SUCCESS);
}
