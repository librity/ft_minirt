/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   objects.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 19:23:52 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/12/24 10:32:38 by lpaulo-m         ###   ########.fr       */
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
	printf("\tshape: %d (%s)\n", object->shape,
		resolve_shape_name(object->shape));
	printf("\torigin: %f %f %f\n", object->origin.x, object->origin.y,
		object->origin.z);
	printf("\tnormal: %f %f %f\n", object->normal.x, object->normal.y,
		object->normal.z);
	printf("\tdiameter: %f\n", object->diameter);
	printf("\tradius: %f\n", object->radius);
	printf("\theight: %f\n", object->height);
	printf("\tcolor_rgb: %d %d %d\n", object->color_rgb.red,
		object->color_rgb.green, object->color_rgb.blue);
	printf("\tcolor_3d: %f %f %f\n", object->color_3d.x, object->color_3d.y,
		object->color_3d.z);
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
