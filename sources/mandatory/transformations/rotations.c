/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotations.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 17:15:54 by lpaulo-m          #+#    #+#             */
/*   Updated: 2023/02/19 18:15:04 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

void	rotation_x(double radians, t_matrix *result)
{
	mx_set_identity(result);
	(*result)[1][1] = cos(radians);
	(*result)[1][2] = -sin(radians);
	(*result)[2][1] = sin(radians);
	(*result)[2][2] = cos(radians);
}

void	rotation_y(double radians, t_matrix *result)
{
	mx_set_identity(result);
	(*result)[0][0] = cos(radians);
	(*result)[0][2] = sin(radians);
	(*result)[2][0] = -sin(radians);
	(*result)[2][2] = cos(radians);
}

void	rotation_z(double radians, t_matrix *result)
{
	mx_set_identity(result);
	(*result)[0][0] = cos(radians);
	(*result)[0][1] = -sin(radians);
	(*result)[1][0] = sin(radians);
	(*result)[1][1] = cos(radians);
}

void	skew_symmetric_matrix(t_v3d axis, t_matrix *result)
{
	mx_clear(result);
	(*result)[0][1] = -axis.z;
	(*result)[0][2] = axis.y;
	(*result)[1][2] = -axis.x;
	(*result)[1][0] = axis.z;
	(*result)[2][0] = -axis.y;
	(*result)[2][1] = axis.x;
}
