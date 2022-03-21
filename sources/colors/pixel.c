/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixel.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/27 15:06:25 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/03/20 22:21:25 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

static t_c3d	gamma2_correct(t_c3d color_3d)
{
	return (vsqrt(color_3d));
}

t_rgb	get_gamma2_pixel(t_c3d color_3d)
{
	color_3d = gamma2_correct(color_3d);
	return (c3d_to_rgb(color_3d));
}
