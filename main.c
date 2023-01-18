/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/26 16:21:36 by lpaulo-m          #+#    #+#             */
/*   Updated: 2023/01/18 19:34:39 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

void	initialize(int argc, char **argv)
{
	if (argc != 2)
		die(ARGC_ERR);
	initialize_control(argc, argv);
	initialize_mlx();
	// validate_scene();
	// parse_scene();
	initialize_window();
	// printf("%s\n", scene_path());
}

void	run(void)
{
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

	// hello_world_ppm_demo();
	// projectile_ppm_demo();

	//clock_hours_ppm_demo();
	//clock_sec_ppm_demo();
	//ray_tracer_v1_demo();
	ray_tracer_v2_demo();
}

int	main(int argc, char **argv)
{
	initialize(argc, argv);
	run();
	cleanup();
	return (EXIT_SUCCESS);
}
