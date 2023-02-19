/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   translate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 18:14:11 by lpaulo-m          #+#    #+#             */
/*   Updated: 2023/02/19 18:48:00 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

void	translate_object(t_object *object, t_p3d new_origin)
{
	t_matrix	translation_mx;

	translation((t_v3d)new_origin, &translation_mx);
	multiply_transform(object, translation_mx);
}
