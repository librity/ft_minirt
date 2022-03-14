/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/03 00:51:20 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/03/14 17:51:06 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

double		rp(void)
{
	return (random_from(-1.0, 1.0));
}

double		rr(void)
{
	return (random_from(0.0, 0.1));
}

t_color_3d	rc(void)
{
	return (random_vector_in(0.0, 1.0));
}

t_color_3d	rcr(double min, double max)
{
	return (random_vector_in(min, max));
}
