/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/24 11:56:07 by lpaulo-m          #+#    #+#             */
/*   Updated: 2023/01/05 18:51:30 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

t_v3d	normal_at(t_object *object, t_p3d point)
{
	t_v3d	result;

	result = sub(point, object->origin);
	result = normalize(result);
	return (result);
}
