/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/24 11:56:07 by lpaulo-m          #+#    #+#             */
/*   Updated: 2023/02/12 20:41:29 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

static int	new_object_id(void)
{
	static int	id;

	return (id++);
}

t_object	*create_object(void)
{
	t_object	*object;

	object = ft_clalloc(world_lalloc(), 1, sizeof(t_object));
	ft_dlst_addb_lalloc(world_lalloc(), objects(), object);
	object->id = new_object_id();
	object->shape = NULL_SHAPE;
	object->material = default_material();
	object->intersect = NULL;
	object->normal_at = NULL;
	mx_set_identity(&(object->transform));
	return (object);
}
