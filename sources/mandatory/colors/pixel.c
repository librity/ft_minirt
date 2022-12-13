/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixel.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/27 15:06:25 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/03/21 23:39:06 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

t_rgb	gamma2_correct_pixel(t_c3d color_3d)
{
	color_3d = vsqrt(color_3d);
	return (c3d_to_rgb(color_3d));
}
