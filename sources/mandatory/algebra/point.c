/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   point.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/03 16:30:28 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/12/26 15:12:50 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

t_p3d	point(double x, double y, double z)
{
	return (point_3d(x, y, z));
}

t_p3d	point_3d(double x, double y, double z)
{
	return (tuple(x, y, z, POINT_TYPE));
}

void	inspect_p3d(t_v3d point)
{
	printf("POINT: %f %f %f\n", point.x, point.y, point.z);
}
