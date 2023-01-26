/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_intersections_broken.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 18:29:56 by lpaulo-m          #+#    #+#             */
/*   Updated: 2023/01/25 19:14:05 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

static double	get_t_by_index(t_dlist **intersections, int index)
{
	t_dlist	*node;
	t_intx	*_intersection;

	node = ft_dlst_get_safe(intersections, index);
	_intersection = node->content;
	return (_intersection->t);
}

static void	swap_content_by_index(t_dlist **stack, int i_index, int j_index)
{
	t_dlist	*i_node;
	t_dlist	*j_node;
	void	*aux;

	i_node = ft_dlst_get_safe(stack, i_index);
	j_node = ft_dlst_get_safe(stack, j_index);
	aux = i_node->content;
	i_node->content = j_node->content;
	j_node->content = aux;
}

static int	partition(t_dlist **intersections, int start, int end)
{
	double	pivot;
	int		i;
	int		j;

	pivot = get_t_by_index(intersections, (start + end) / 2);
	i = start;
	j = end;
	while (true)
	{
		while (get_t_by_index(intersections, i) < pivot)
			i++;
		while (get_t_by_index(intersections, j) > pivot)
			j--;
		if (i >= j)
			return (j);
		swap_content_by_index(intersections, i, j);
	}
}

static void	free_quick_sort(t_dlist **intersections, int start, int end)
{
	int	division_index;

	if (start < 0)
		return ;
	if (end < 0)
		return ;
	if (start >= end)
		return ;
	division_index = partition(intersections, start, end);
	free_quick_sort(intersections, start, division_index);
	free_quick_sort(intersections, division_index + 1, end);
}

// TODO: Fix infinite loop.
void	sort_intersections_broken(t_dlist **intersections)
{
	ft_debug("intersections = %p", intersections);
	ft_debug("*intersections = %p", *intersections);
	free_quick_sort(intersections, 0, ft_dlstsize(*intersections) - 1);
}
