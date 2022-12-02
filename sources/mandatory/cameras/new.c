/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/27 17:51:38 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/03/21 23:11:56 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

static void	calculate_basis(t_new_camera *p)
{
	const t_v3d	up = vector_3d(0.0, 1.0, 0.0);

	p->horz_fov_rad = degrees_to_radians(p->horz_fov_deg);
	p->view_width = 2.0 * tan(p->horz_fov_rad / 2.0);
	p->view_height = p->view_width / p->aspect_ratio;
	p->base_w = unit(sub(p->look_from, p->look_at));
	p->base_u = unit(cross(up, p->base_w));
	p->base_v = cross(p->base_w, p->base_u);
}

static void	set_offset_factors(t_camera *new, t_new_camera *p)
{
	new->horizontal = scalar_times(p->view_width, p->base_u);
	new->vertical = scalar_times(p->view_height, p->base_v);
}

static void	set_lower_left_corner(t_camera *new, t_new_camera *p)
{
	t_p3d	ll_corner;

	ll_corner = sub(new->origin, scalar_div(2.0, new->horizontal));
	ll_corner = sub(ll_corner, scalar_div(2.0, new->vertical));
	ll_corner = sub(ll_corner, p->base_w);
	new->ll_corner = ll_corner;
}

static void	initialize_mlx_buffer(t_camera *new, t_new_camera *p)
{
	log_msg(BUFFER_MSG);
	mlx_image_initialize(&(new->buffer), p->mlx, p->width, p->height);
	log_endl(SUCCESS_MSG);
}

t_camera	*new_camera(t_new_camera p)
{
	t_camera	*new;

	new = (t_camera *)ft_salloc(sizeof(t_camera));
	new->number = p.number;
	new->origin = p.look_from;
	calculate_basis(&p);
	set_offset_factors(new, &p);
	set_lower_left_corner(new, &p);
	initialize_mlx_buffer(new, &p);
	return (new);
}
