/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera_2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 19:18:56 by lpaulo-m          #+#    #+#             */
/*   Updated: 2023/02/26 16:01:07 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static t_v3d	resolve_up_vector(t_v3d orientation)
{
	t_v3d	temp;

	if (doubles_are_equal(orientation.y, 1.0)
		|| doubles_are_equal(orientation.y, -1.0))
	{
		temp = cross(orientation, vector(1, 0, 0));
		return (cross(temp, orientation));
	}
	return (vector(0, 1, 0));
}

void	set_camera(t_p3d origin, t_v3d orientation, double horz_fov_deg)
{
	t_camera	*cam;

	cam = &(c()->camera);
	cam->origin = origin;
	cam->orientation = orientation;
	cam->fov_deg = horz_fov_deg;
	cam->fov_rad = degrees_to_radians(horz_fov_deg);
	set_challenge_camera(WINDOW_WIDTH, WINDOW_HEIGHT, cam->fov_rad);
	view_transformation(origin,
		add(origin, orientation),
		resolve_up_vector(orientation),
		&cam->transform);
}
