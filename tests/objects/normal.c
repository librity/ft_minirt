/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 18:37:51 by lpaulo-m          #+#    #+#             */
/*   Updated: 2023/01/05 19:08:44 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../tests.h"

t_object	*_sphere;
t_v3d		normal;

void	test_setup(void)
{
}
void	test_teardown(void)
{
	free_lalloc();
}

MU_TEST(normal_at_tst)
{
	double	sqrt3o3 = sqrt(3.0) / 3.0;
	_sphere = sphere();

	normal = normal_at(_sphere, point(1, 0, 0));
	assert_tuple_eq(vector(1, 0, 0), normal);

	normal = normal_at(_sphere, point(0, 1, 0));
	assert_tuple_eq(vector(0, 1, 0), normal);

	normal = normal_at(_sphere, point(0, 0, 1));
	assert_tuple_eq(vector(0, 0, 1), normal);

	normal = normal_at(_sphere, point(-1, 0, 0));
	assert_tuple_eq(vector(-1, 0, 0), normal);

	normal = normal_at(_sphere, point(0, -1, 0));
	assert_tuple_eq(vector(0, -1, 0), normal);

	normal = normal_at(_sphere, point(0, 0, -1));
	assert_tuple_eq(vector(0, 0, -1), normal);

	normal = normal_at(_sphere, point(sqrt3o3, sqrt3o3, sqrt3o3));
	assert_tuple_eq(vector(sqrt3o3, sqrt3o3, sqrt3o3), normal);
}

MU_TEST(normal_at_radius_tst)
{
	double	sqrt3o3 = sqrt(3.0) / 3.0;
	_sphere = new_sphere(point(0, 0, 0), 42.0, rgb_red());

	normal = normal_at(_sphere, point(1, 0, 0));
	assert_tuple_eq(vector(1, 0, 0), normal);

	normal = normal_at(_sphere, point(0, 1, 0));
	assert_tuple_eq(vector(0, 1, 0), normal);

	normal = normal_at(_sphere, point(0, 0, 1));
	assert_tuple_eq(vector(0, 0, 1), normal);

	normal = normal_at(_sphere, point(-1, 0, 0));
	assert_tuple_eq(vector(-1, 0, 0), normal);

	normal = normal_at(_sphere, point(0, -1, 0));
	assert_tuple_eq(vector(0, -1, 0), normal);

	normal = normal_at(_sphere, point(0, 0, -1));
	assert_tuple_eq(vector(0, 0, -1), normal);

	normal = normal_at(_sphere, point(sqrt3o3, sqrt3o3, sqrt3o3));
	assert_tuple_eq(vector(sqrt3o3, sqrt3o3, sqrt3o3), normal);
}

MU_TEST(normalized_vector_tst)
{
	double	sqrt3o3 = sqrt(3.0) / 3.0;

	_sphere = sphere();
	normal = normal_at(_sphere, point(sqrt3o3, sqrt3o3, sqrt3o3));
	assert_tuple_eq(normalize(normal), normal);
}


MU_TEST_SUITE(normal_suite)
{
	MU_SUITE_CONFIGURE(&test_setup, &test_teardown);

	MU_RUN_TEST(normal_at_tst);
	MU_RUN_TEST(normal_at_radius_tst);
	MU_RUN_TEST(normalized_vector_tst);
}

MU_MAIN
{
	MU_DIVIDER;
	MU_RUN_SUITE(normal_suite);
	MU_REPORT();
	return (MU_EXIT_CODE);
}
