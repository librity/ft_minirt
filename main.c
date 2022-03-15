/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/26 16:21:36 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/03/14 22:35:38 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

static void initialize_world(t_list **materials, t_list **spheres)
{
	create_matte_sphere(
		(t_sphere_params){
			materials, spheres,
			point(0.0, -100.5, -1.0),
			100.0,
			color(0.8, 0.8, 0.0)});

	add_matte_sphere(
		(t_sphere_params){
			materials, spheres,
			point(-1.0, 0.0, -1.0),
			0.5,
			color(0.5, 0.1, 0.3)});

	add_matte_sphere(
		(t_sphere_params){
			materials, spheres,
			point(0.0, 0.0, -1.0),
			0.5,
			color(0.1, 0.2, 0.5)});

	add_matte_sphere(
		(t_sphere_params){
			materials, spheres,
			point(1.0, 0.0, -1.0),
			0.5,
			color(0.8, 0.6, 0.2)});
}

static void configure_camera(t_minirt *ctl)
{
	t_initialize_camera camera_params;

	camera_params.look_from = (t_p3d){-2, 2, 1};
	camera_params.look_at = (t_p3d){0, 0, -1};
	camera_params.view_up = (t_v3d){0, 1, 0};

	camera_params.vertical_fov_degrees = 40.0;
	camera_params.aperture = 0.0;
	camera_params.focus_distance = 2.0;

	initialize_camera(&(ctl->camera), ctl->aspect_ratio, camera_params);
}

static void initialize_ray_tracer(t_minirt *ctl, char **arguments)
{
	ctl->file_name = arguments[1];

	ctl->aspect_ratio = 16.0 / 9.0;
	// ctl->width = 1920;
	ctl->width = 400;
	ctl->height = (int)(ctl->width / ctl->aspect_ratio);
	ctl->samples_per_pixel = 10;
	ctl->max_depth = 50;

	configure_camera(ctl);
	initialize_world(&(ctl->materials), &(ctl->spheres));
}

int main(int argc, char **argv)
{
	t_minirt ctl;
	t_bitmap_image image;

	handle_arguments(argc);
	initialize_ray_tracer(&ctl, argv);
	bm_initialize_bitmap(&image, ctl.width, ctl.height);

	log_start(&ctl);
	generate_image(&image, &ctl, ctl.camera);
	log_end();
	cleanup_ray_tracer(&ctl);

	bm_save_bitmap(&image, ctl.file_name);
	bm_free_bitmap(&image);
	return (EXIT_SUCCESS);
}
