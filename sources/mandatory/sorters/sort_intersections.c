/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_intersections.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 18:29:56 by lpaulo-m          #+#    #+#             */
/*   Updated: 2023/01/13 18:44:24 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

static double	get_t_by_index(t_dlist **intersections, int index)
{
	t_dlist			*node;
	t_intersection	*_intersection;

	node = ft_dlst_get_safe(intersections, index);
	_intersection = node->content;
	return (_intersection->t);
}

static void	swap_content_by_index(t_dlist **stack, int i_index, int j_index)
{
	t_dlist	*i_node;
	t_dlist	*j_node;
	void	*i_content;
	void	*j_content;

	i_node = ft_dlst_get_safe(stack, i_index);
	j_node = ft_dlst_get_safe(stack, j_index);
	i_content = i_node->content;
	j_content = j_node->content;
	i_node->content = j_content;
	j_node->content = i_content;
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

void	sort_intersections(t_dlist **intersections)
{
	free_quick_sort(intersections, 0, ft_dlstsize(*intersections) - 1);
}
