/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/26 16:21:36 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/12/29 17:49:45 by lpaulo-m         ###   ########.fr       */
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
	// hello_world_ppm_demo();
	projectile_ppm_demo();
	// validate_scene();
	// parse_scene();
	// inspect_ambient_light();
	// inspect_camera();
	// inspect_light();
	// inspect_objects();

	// quadratic_demo();
	//red_window_demo();
	// hit_sphere_demo();
	// create_demo_spheres();
	// inspect_objects();
	// verify_closest_sphere(ray_3d(point(0, 0, 0), vector(1, 0, 0)));
	// hello_world_window_demo();
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
