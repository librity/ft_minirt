/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   objects.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 19:23:52 by lpaulo-m          #+#    #+#             */
/*   Updated: 2023/02/12 20:30:12 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

t_dlist	**objects(void)
{
	return (&(c()->objects));
}

char	*resolve_shape_name(t_shape shape)
{
	static char	*names[] = {"NULL", "SPHERE", "PLANE", "CYLINDER"};

	return (names[shape]);
}

void	inspect_object(t_object *object)
{
	printf("=== object ===\n");
	printf("\tid: %d\n", object->id);
	printf("\tshape: %d (%s)\n", object->shape,
		resolve_shape_name(object->shape));
	printf("\torigin: %f %f %f\n", object->origin.x, object->origin.y,
		object->origin.z);
	printf("\tnormal: %f %f %f\n", object->normal.x, object->normal.y,
		object->normal.z);
	printf("\tdiameter: %f\n", object->diameter);
	printf("\tradius: %f\n", object->radius);
	printf("\theight: %f\n", object->height);
	printf("\tcolor_3d: %f %f %f\n", object->material.color.x,
		object->material.color.y, object->material.color.z);
}

void	inspect_objects(void)
{
	t_dlist		*node;

	node = c()->objects;
	while (node != NULL)
	{
		inspect_object(node->content);
		node = node->next;
	}
}
