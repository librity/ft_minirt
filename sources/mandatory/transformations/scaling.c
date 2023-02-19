/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scaling.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 16:35:38 by lpaulo-m          #+#    #+#             */
/*   Updated: 2023/02/19 19:20:54 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

void	scaling(t_v3d vector, t_matrix *result)
{
	mx_set_identity(result);
	(*result)[0][0] = vector.x;
	(*result)[1][1] = vector.y;
	(*result)[2][2] = vector.z;
}
