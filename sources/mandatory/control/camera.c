/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 19:23:52 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/12/20 19:23:16 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

t_camera	camera(void)
{
	return (c()->camera);
}

t_mlx_image	*camera_buffer(void)
{
	return (&c()->camera.buffer);
}

void	initialize_camera(void)
{
	mlx_image_initialize(&c()->camera.buffer, c()->mlx,
		c()->width, c()->height);
}

void	destroy_camera(void)
{
	mlx_image_destroy(&c()->camera.buffer);
}

void	set_camera(t_p3d origin, t_v3d orientation, double horz_fov_deg)
{
	c()->camera.origin = origin;
	c()->camera.orientation = orientation;
	c()->camera.horz_fov_deg = horz_fov_deg;
	c()->camera.horz_fov_rad = degrees_to_radians(horz_fov_deg);
}

void	inspect_camera(void)
{
	t_camera	cam;

	cam = c()->camera;
	printf("=== camera ===\n");
	printf("\torigin: %f %f %f\n", cam.origin.x, cam.origin.y, cam.origin.z);
	printf("\torientation: %f %f %f\n", cam.orientation.x, cam.orientation.y,
		cam.orientation.z);
	printf("\thorz_fov_deg: %f\n", cam.horz_fov_deg);
	printf("\thorz_fov_rad: %f\n", cam.horz_fov_rad);
}
