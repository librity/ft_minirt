/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_intersections.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 18:29:56 by lpaulo-m          #+#    #+#             */
/*   Updated: 2023/01/25 19:12:35 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

static void	swap(t_intx **a, t_intx **b)
{
	t_intx	*temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

static int	partition(t_intx **intxs_lst, int start, int end)
{
	double	pivot;
	int		i;
	int		j;

	i = start;
	pivot = intxs_lst[end]->t;
	j = start;
	while (j < end)
	{
		if (intxs_lst[j]->t <= pivot)
		{
			swap(&intxs_lst[j], &intxs_lst[i]);
			i++;
		}
		j++;
	}
	swap(&intxs_lst[i], &intxs_lst[end]);
	return (i);
}

static void	quick_sort(t_intx **intxs_lst, int start, int end)
{
	int	_partition;

	if (start < end)
	{
		_partition = partition(intxs_lst, start, end);
		quick_sort(intxs_lst, start, _partition - 1);
		quick_sort(intxs_lst, _partition + 1, end);
	}
}

static void	get_intxs_array(t_intx **intxs, t_dlist *list)
{
	while (list)
	{
		*intxs = list->content;
		intxs++;
		list = list->next;
	}
}

void	sort_intersections(t_dlist **intxs_lst)
{
	t_dlist	*node;
	t_intx	**intxs;
	int		intxs_list_size;
	int		i;

	node = *intxs_lst;
	intxs_list_size = ft_dlstsize(node);
	intxs = ft_calloc(intxs_list_size, sizeof(*intxs));
	get_intxs_array(intxs, node);
	quick_sort(intxs, 0, intxs_list_size - 1);
	i = 0;
	while (node)
	{
		node->content = intxs[i];
		i++;
		node = node->next;
	}
	free(intxs);
}
