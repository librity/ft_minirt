/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrices.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 20:54:40 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/12/29 21:40:33 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

void	set_matrix(t_matrix *matrix, t_set_matrix set)
{
	t_set_matrix_union	set_union;
	int					i;
	int					j;

	set_union.set = set;
	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			(*matrix)[i][j] = set_union.values[i * 4 + j];
			j++;
		}
		i++;
	}
}

void	clear_matrix(t_matrix *matrix)
{
	int	i;
	int	j;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			(*matrix)[i][j] = 0.0;
			j++;
		}
		i++;
	}
}
