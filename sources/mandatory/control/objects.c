/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   objects.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 19:23:52 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/12/14 21:44:28 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

t_dlist	**objects(void)
{
	return (&(c()->objects));
}

void	inspect_objects(void)
{
	t_dlist		*node;
	t_object	*object;

	node = c()->objects;
	while (node != NULL)
	{
		object = node->content;
		printf("=== object ===\n");
		printf("\tshape: %d\n", object->shape);
		printf("\torigin: %f %f %f\n", object->origin.x, object->origin.y,
			object->origin.z);
		printf("\tshape: %f\n", object->diameter);
		printf("\tcolor_rgb: %d %d %d\n", object->color_rgb.red,
			object->color_rgb.green, object->color_rgb.blue);
		node = node->next;
	}
}
