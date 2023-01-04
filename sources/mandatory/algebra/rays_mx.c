/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rays_mx.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 18:37:20 by lpaulo-m          #+#    #+#             */
/*   Updated: 2023/01/04 19:52:56 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

t_ray	transform(t_ray ray, t_matrix matrix)
{
	ray.direction = mx_tuple_multiply(matrix, ray.direction);
	ray.origin = mx_tuple_multiply(matrix, ray.origin);
	return (ray);
}
