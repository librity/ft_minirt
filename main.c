/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/26 16:21:36 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/03/19 00:10:14 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

static void initialize_world(t_minirt *ctl)
{
	add_sphere(ctl,
		(t_new_sphere){
			point(0.0, -100.5, -1.0),
			100.0,
			color(0.8, 0.8, 0.0)});

	add_sphere(ctl,
		(t_new_sphere){
			point(-1.0, 0.0, -1.0),
			0.5,
			color(0.5, 0.1, 0.3)});

	add_sphere(ctl,
		(t_new_sphere){
			point(0.0, 0.0, -1.0),
			0.5,
			color(0.1, 0.2, 0.5)});

	add_sphere(ctl,
		(t_new_sphere){
			point(1.0, 0.0, -1.0),
			0.5,
			color(0.8, 0.6, 0.2)});
}

static void configure_camera(t_minirt *ctl)
{
	t_new_camera p;

	p.look_from = (t_p3d){-2, 2, 1};
	p.look_at = (t_p3d){0, 0, -1};
	p.view_up = (t_v3d){0, 1, 0};

	p.vertical_fov_degrees = 40.0;
	p.aperture = 0.0;
	p.focus_distance = 2.0;
	p.aspect_ratio = ctl->aspect_ratio;

	p.mlx = ctl->mlx;
	p.width = ctl->width;
	p.height = ctl->height;

	add_camera(ctl, p);
}

static void initialize(t_minirt *ctl, char **arguments)
{
	ctl->file_name = arguments[1];

	ctl->aspect_ratio = 16.0 / 9.0;
	ctl->width = 400;
	ctl->height = (int)(ctl->width / ctl->aspect_ratio);

	configure_camera(ctl);
	initialize_world(ctl);
}

int main(int argc, char **argv)
{
	t_minirt		ctl;
	t_camera		*camera;

	initialize_ctl(&ctl);
	handle_arguments(argc);
	initialize_mlx(&ctl);
	initialize(&ctl, argv);

	log_scene(&ctl);
	log_msg(TRACING_MSG);
	camera = ctl.cameras->content;
	generate_image(&ctl, camera);
	log_endl(SUCCESS_MSG);
	cleanup_ray_tracer(&ctl);

	bm_save_mlx_image(&(camera->buffer), ctl.file_name);
	return (EXIT_SUCCESS);
}
