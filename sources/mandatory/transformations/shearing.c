/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shearing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 17:15:54 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/12/30 17:55:16 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

void	shearing(t_shearing shear, t_matrix *result)
{
	mx_set_identity(result);
	(*result)[0][1] = shear.xy;
	(*result)[0][2] = shear.xz;
	(*result)[1][0] = shear.yx;
	(*result)[1][2] = shear.yz;
	(*result)[2][0] = shear.zx;
	(*result)[2][1] = shear.zy;
}
