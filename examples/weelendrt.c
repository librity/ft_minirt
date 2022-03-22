/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   weelendrt.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/26 16:21:36 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/03/21 23:40:06 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

static void	initialize_world(t_minirt *ctl)
{
	set_ambient_light(
		ctl,
		0.2,
		color_rgb(255, 255, 255));
	add_sphere(ctl,
		(t_new_sphere){
			point(0.0, -100.5, -1.0),
			200.0,
			color_rgb(200,200,0)});
	add_sphere(ctl,
		(t_new_sphere){
			point(-1.0, 0.0, -1.0),
			1.0,
			color_rgb(255,0,0)});
	add_sphere(ctl,
		(t_new_sphere){
			point(0.0, 0.0, -1.0),
			1.0,
			color_rgb(25, 50, 125)});
	add_sphere(ctl,
		(t_new_sphere){
			point(1.0, 0.0, -1.0),
			1.0,
			color_rgb(200, 150, 50)});
}

static void	configure_camera(t_minirt *ctl)
{
	t_add_camera	p;

	p.look_from = point_3d(-2, 2, 1);
	p.look_at = vector_3d(0, 0, -1);
	p.horz_fov_deg = 70;
	add_camera(ctl, p);
	ctl->current_cam = ctl->cameras->content;
}

static void	initialize(t_minirt *ctl, int argc, char **argv)
{
	handle_arguments(argc);
	initialize_ctl(ctl);
	initialize_mlx(ctl);
	ctl->file_name = argv[1];
	configure_camera(ctl);
	initialize_world(ctl);
}

static void	trace_current_cam(t_minirt *ctl)
{
	log_scene(ctl);
	log_msg(TRACING_MSG);
	generate_image(ctl, ctl->current_cam);
	log_endl(SUCCESS_MSG);
	mlx_put_image_to_window(ctl->mlx, ctl->window,
		ctl->current_cam->buffer.img, 0, 0);
}

int	main(int argc, char **argv)
{
	t_minirt	ctl;

	initialize(&ctl, argc, argv);
	trace_current_cam(&ctl);

	save_camera_buffer(ctl.current_cam);
	mlx_loop(ctl.mlx);

	clean(&ctl);
	return (EXIT_SUCCESS);
}
