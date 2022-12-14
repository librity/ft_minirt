/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 19:31:38 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/12/14 19:41:15 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_light	light(void)
{
	return (c()->light);
}

void	set_light(t_p3d origin, double brightness)
{
	c()->light.origin = origin;
	c()->light.brightness = brightness;
}

void	inspect_light(void)
{
	t_light	light;

	light = c()->light;
	printf("light:\n");
	printf("\torigin: %f %f %f\n", light.origin.x, light.origin.y, light.origin.z);
	printf("\tbrightness: %f\n", light.brightness);
}
