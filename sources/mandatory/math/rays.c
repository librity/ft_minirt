/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rays.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 18:37:20 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/12/21 19:01:29 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

t_p3d	ray_at(t_ray r, double translation)
{
	t_p3d	result;

	result = scalar_times(translation, r.direction);
	add(r.origin, result);
	return (result);
}
