/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/20 21:31:16 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/03/20 21:31:38 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

static void	set_params(t_minirt *ctl, t_add_camera add_p, t_new_camera *new_p)
{
	new_p->origin = add_p.origin;
	new_p->orientation = add_p.orientation;
	new_p->horz_fov_deg = add_p.horz_fov_deg;
	new_p->mlx = ctl->mlx;
	new_p->width = ctl->width;
	new_p->height = ctl->height;
	new_p->aspect_ratio = ctl->aspect_ratio;
}

void	add_camera(t_minirt *ctl, t_add_camera add_p)
{
	t_camera		*camera;
	t_new_camera	new_p;

	set_params(ctl, add_p, &new_p);
	camera = new_camera(new_p);
	ft_lst_add(&(ctl->cameras), camera);
}
