/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mx_invertible.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 15:04:53 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/12/30 15:06:04 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

bool	mx_is_invertible(t_matrix matrix, int size)
{
	if (mx_determinant(matrix, size))
		return (true);
	return (false);
}
