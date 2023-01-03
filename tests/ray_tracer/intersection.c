/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersection.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 16:59:18 by lpaulo-m          #+#    #+#             */
/*   Updated: 2023/01/02 21:10:36 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../tests.h"

t_object		*_sphere;
t_intersection	*_intersection;
t_dlist			*_intersections;
int				intersection_size;

void	test_setup(void)
{
}
void	test_teardown(void)
{
}

MU_TEST(intersection_tst)
{
	_sphere = sphere();
	_intersection = intersection(3.5, _sphere);

	mu_assert_double_eq(3.5, _intersection->t);
	mu_check(_sphere == _intersection->object);
}

MU_TEST(add_intersection_tst)
{
	_sphere = sphere();
	add_intersection(&_intersections, intersection(1, _sphere));
	add_intersection(&_intersections, intersection(2, _sphere));

	intersection_size = ft_dlstsize(_intersections);
	mu_assert_int_eq(2, intersection_size);

	_intersection = _intersections->content;
	mu_assert_double_eq(1, _intersection->t);

	_intersection = _intersections->next->content;
	mu_assert_double_eq(2, _intersection->t);
}

MU_TEST_SUITE(intersection_suite)
{
	MU_SUITE_CONFIGURE(&test_setup, &test_teardown);

	MU_RUN_TEST(intersection_tst);
	MU_RUN_TEST(add_intersection_tst);
}

MU_MAIN
{
	MU_DIVIDER;
	MU_RUN_SUITE(intersection_suite);
	MU_REPORT();
	return (MU_EXIT_CODE);
}
