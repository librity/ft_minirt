/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 00:58:04 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/03/19 00:09:20 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

void	cleanup_ray_tracer(t_minirt *ctl)
{
	// FOR EACH CAMERA
	// mlx_destroy_image(ctl->mlx, ctl->buffer.img);
	free_spheres(ctl);
}
