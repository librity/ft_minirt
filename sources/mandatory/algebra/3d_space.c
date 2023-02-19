/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3d_space.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 18:38:18 by lpaulo-m          #+#    #+#             */
/*   Updated: 2023/02/19 18:52:39 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

t_v3d	space_origin(void)
{
	return (point(0, 0, 0));
}

t_v3d	x_axis_normal(void)
{
	return (vector(1, 0, 0));
}

t_v3d	y_axis_normal(void)
{
	return (vector(0, 1, 0));
}

t_v3d	z_axis_normal(void)
{
	return (vector(0, 0, 1.0));
}
