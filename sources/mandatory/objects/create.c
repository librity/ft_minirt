/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/24 11:56:07 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/12/24 11:58:19 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

static int	new_object_id(void)
{
	static int	id;

	return (id++);
}

void	create_object(t_object *object)
{
	object->id = new_object_id();
	ft_dlst_addb_lalloc(lalloc(), objects(), object);
}
