/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scale.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 18:14:11 by lpaulo-m          #+#    #+#             */
/*   Updated: 2023/02/19 19:21:06 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

void	scale_object(t_object *object, t_v3d new_scale)
{
	t_matrix	scale_mx;

	scaling((t_v3d)new_scale, &scale_mx);
	multiply_transform(object, scale_mx);
}
