/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transform.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 20:11:09 by lpaulo-m          #+#    #+#             */
/*   Updated: 2023/02/12 20:54:35 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

void	set_transform(t_object *object, t_matrix mx)
{
	mx_copy(mx, &(object->transform));
}

void	multiply_transform(t_object *object, t_matrix mx)
{
	t_matrix	result;

	mxs_multiply(object->transform, mx, &result);
	mx_copy(result, &(object->transform));
}
