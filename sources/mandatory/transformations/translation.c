/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   translation.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 16:35:38 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/12/30 16:53:19 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

void	translation(t_v3d trans_vector, t_matrix *result)
{
	mx_set_identity(result);
	(*result)[0][3] = trans_vector.x;
	(*result)[1][3] = trans_vector.y;
	(*result)[2][3] = trans_vector.z;
}
