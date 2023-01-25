/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersections.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 18:44:01 by lpaulo-m          #+#    #+#             */
/*   Updated: 2023/01/25 19:13:44 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../tests.h"

t_dlist *intersections;
t_dlist *node;

void test_setup(void)
{
}
void test_teardown(void)
{
}

MU_TEST(sort_tst)
{
	ft_dlstadd_back(&intersections, ft_dlstnew(new_intersection(9.0, NULL)));
	ft_dlstadd_back(&intersections, ft_dlstnew(new_intersection(2.0, NULL)));
	ft_dlstadd_back(&intersections, ft_dlstnew(new_intersection(4.0, NULL)));
	ft_dlstadd_back(&intersections, ft_dlstnew(new_intersection(1.0, NULL)));
	ft_dlstadd_back(&intersections, ft_dlstnew(new_intersection(2.0, NULL)));
	ft_dlstadd_back(&intersections, ft_dlstnew(new_intersection(454.0, NULL)));
	ft_dlstadd_back(&intersections, ft_dlstnew(new_intersection(3.0, NULL)));
	ft_dlstadd_back(&intersections, ft_dlstnew(new_intersection(-2.0, NULL)));
	ft_dlstadd_back(&intersections, ft_dlstnew(new_intersection(3.4, NULL)));

	node = intersections;
	sort_intersections(&intersections);
	while (node)
	{
		printf("%f\n", ((t_intx *)node->content)->t);
		node = node->next;
	}
	mu_assert_double_eq(-2.0, ((t_intx *)intersections->content)->t);
	ft_dlstclear(&intersections, free);
}

MU_TEST(sort_broken_tst)
{
	ft_dlstadd_back(&intersections, ft_dlstnew(new_intersection(9.0, NULL)));
	ft_dlstadd_back(&intersections, ft_dlstnew(new_intersection(2.0, NULL)));
	ft_dlstadd_back(&intersections, ft_dlstnew(new_intersection(4.0, NULL)));
	ft_dlstadd_back(&intersections, ft_dlstnew(new_intersection(1.0, NULL)));
	ft_dlstadd_back(&intersections, ft_dlstnew(new_intersection(2.0, NULL)));
	ft_dlstadd_back(&intersections, ft_dlstnew(new_intersection(454.0, NULL)));
	ft_dlstadd_back(&intersections, ft_dlstnew(new_intersection(3.0, NULL)));
	ft_dlstadd_back(&intersections, ft_dlstnew(new_intersection(-2.0, NULL)));
	ft_dlstadd_back(&intersections, ft_dlstnew(new_intersection(3.4, NULL)));

	node = intersections;
	sort_intersections_broken(&intersections);
	while (node)
	{
		printf("%f\n", ((t_intx *)node->content)->t);
		node = node->next;
	}
	mu_assert_double_eq(-2.0, ((t_intx *)intersections->content)->t);
	ft_dlstclear(&intersections, free);
}

MU_TEST_SUITE(sort_intersections_suite)
{
	MU_SUITE_CONFIGURE(&test_setup, &test_teardown);

	MU_RUN_TEST(sort_tst);
	// MU_RUN_TEST(sort_broken_tst);
}

MU_MAIN
{
	MU_DIVIDER;
	MU_RUN_SUITE(sort_intersections_suite);
	MU_REPORT();
	return (MU_EXIT_CODE);
}
