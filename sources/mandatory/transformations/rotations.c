/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotations.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 17:15:54 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/12/30 17:38:34 by lpaulo-m         ###   ########.fr       */
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
	(*result)[2][1] = -sin(radians);
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
