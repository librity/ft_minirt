/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   point.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/03 16:30:28 by lpaulo-m          #+#    #+#             */
/*   Updated: 2021/04/04 21:49:18 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

t_point_3d	point(double x, double y, double z)
{
	return (point_3d(x, y, z));
}

t_point_3d	point_3d(double x, double y, double z)
{
	return ((t_point_3d){x, y, z});
}
