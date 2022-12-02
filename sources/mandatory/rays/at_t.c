/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transaltion.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/27 16:21:01 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/03/20 20:24:22 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

t_p3d	ray_at_t(double translation, t_ray ray)
{
	t_v3d	reach;

	reach = scalar_times(translation, ray.direction);
	return (add(ray.origin, reach));
}
