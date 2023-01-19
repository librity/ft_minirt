/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   view.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 19:35:37 by lpaulo-m          #+#    #+#             */
/*   Updated: 2023/01/18 20:20:33 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

void	view_transformation(t_p3d from, t_p3d to, t_v3d up, t_matrix *result)
{
	t_v3d		forward;
	t_v3d		left;
	t_v3d		true_up;
	t_matrix	_orientation;
	t_matrix	_translation;

	forward = normalize(sub(to, from));
	up = normalize(up);
	left = cross(forward, up);
	true_up = cross(left, forward);
	mx_set(&_orientation, (t_mx_set){
		left.x, left.y, left.z, 0.0,
		true_up.x, true_up.y, true_up.z, 0.0,
		-forward.x, -forward.y, -forward.z, 0.0,
		0.0, 0.0, 0.0, 1.0,
	});
	translation(neg(from), &_translation);
	mxs_multiply(_orientation, _translation, result);
}
