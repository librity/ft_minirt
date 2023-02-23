/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scale.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaulo-d <ppaulo-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 18:14:11 by lpaulo-m          #+#    #+#             */
/*   Updated: 2023/02/22 22:05:47 by ppaulo-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

void	scale_object(t_object *object, t_v3d new_scale)
{
	t_matrix	scale_mx;

	scaling(new_scale, &scale_mx);
	multiply_transform(object, scale_mx);
}
