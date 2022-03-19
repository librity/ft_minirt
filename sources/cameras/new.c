/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/27 17:51:38 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/03/18 23:56:04 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

static void	set_orthonormal_basis(t_camera *camera, t_new_camera p)
{
	camera->basis_w = unit(sub(p.look_from, p.look_at));
	camera->basis_u = unit(cross(p.view_up, camera->basis_w));
	camera->basis_v = cross(camera->basis_w, camera->basis_u);
}

static void	set_position(t_camera *camera,
							t_new_camera p,
							double viewport_width,
							double viewport_height)
{
	camera->origin = p.look_from;
	camera->horizontal = scalar_times(p.focus_distance * viewport_width,
			camera->basis_u);
	camera->vertical = scalar_times(p.focus_distance * viewport_height,
			camera->basis_v);
}

static void	set_lower_left_corner(t_camera *camera, t_new_camera p)
{
	t_p3d	lower_left_corner;

	lower_left_corner = sub(camera->origin,
			scalar_div(2.0, camera->horizontal));
	lower_left_corner = sub(lower_left_corner,
			scalar_div(2.0, camera->vertical));
	lower_left_corner = sub(lower_left_corner,
			scalar_times(p.focus_distance, camera->basis_w));
	camera->lower_left_corner = lower_left_corner;
}

static void	initialize_mlx_buffer(t_camera *camera, t_new_camera p)
{
	log_msg(BUFFER_MSG);
	bm_initialize_mlx_image(&(camera->buffer), p.mlx, p.width, p.height);
	log_endl(SUCCESS_MSG);
}

t_camera	*new_camera(t_new_camera p)
{
	t_camera	*new;
	double		height;
	double		viewport_height;
	double		viewport_width;

	new = (t_camera *)ft_salloc(sizeof(t_camera));
	if (new == NULL)
		return (NULL);
	height = degrees_to_radians(p.vertical_fov_degrees);
	height = tan(height / 2);
	viewport_height = 2.0 * height;
	viewport_width = p.aspect_ratio * viewport_height;
	set_orthonormal_basis(new, p);
	set_position(new, p, viewport_width, viewport_height);
	set_lower_left_corner(new, p);
	initialize_mlx_buffer(new, p);
	return (new);
}
