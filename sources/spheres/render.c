/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/28 01:46:52 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/03/16 00:36:27 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

// TODO: IMPLEMENT HARD SHADOWS:
// CAST RAY TOWARDS ALL LIGHTS AND ATENUATE COLOR FOR EVERY HIT.
// SEE AWFL'S raytrace.c
t_c3d	render_sphere(t_minirt *ctl, t_ray ray, t_hit_record *record)
{
	ray = ray;
	ctl = ctl;
	return (record->color);
}
