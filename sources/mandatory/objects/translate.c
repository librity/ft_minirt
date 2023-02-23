/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   translate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaulo-d <ppaulo-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 18:14:11 by lpaulo-m          #+#    #+#             */
/*   Updated: 2023/02/22 21:29:06 by ppaulo-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

void	translate_object(t_object *object, t_p3d new_origin)
{
	t_matrix	translation_mx;

	translation(vector(new_origin.x, new_origin.y, new_origin.z), &translation_mx);
	multiply_transform(object, translation_mx);
}
