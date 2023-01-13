/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   default.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 19:08:51 by lpaulo-m          #+#    #+#             */
/*   Updated: 2023/01/13 18:47:55 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

void	set_default_world(void)
{
	t_object	*_sphere;

	set_light(point(-10, 10, -10), 1.0);
	_sphere = create_sphere(point(0, 0, 0), 2.0, color_rgb(255, 0, 0));
	_sphere->material.color = color(0.8, 1.0, 0.6);
	_sphere->material.specular = 0.2;
	_sphere->material.diffuse = 0.7;
	_sphere = create_sphere(point(0, 0, 0), 2.0, color_rgb(255, 0, 0));
	scaling(vector(0.5, 0.5, 0.5), &_sphere->transform);
}
