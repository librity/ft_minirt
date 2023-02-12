/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   material.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/24 11:56:07 by lpaulo-m          #+#    #+#             */
/*   Updated: 2023/02/12 20:41:49 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

t_material	default_material(void)
{
	t_material	_material;

	_material.color = color_3d(1, 1, 1);
	_material.ambient = 0.1;
	_material.diffuse = 0.9;
	_material.specular = 0.9;
	_material.shininess = 200.0;
	return (_material);
}
