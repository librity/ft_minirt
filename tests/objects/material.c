/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   material.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 18:37:51 by lpaulo-m          #+#    #+#             */
/*   Updated: 2023/01/17 19:13:04 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../tests.h"

t_object	*_sphere;
t_material		_material;

void	test_setup(void)
{
}
void	test_teardown(void)
{
	free_world_lalloc();
}

MU_TEST(default_material_tst)
{
	_material = material();

	assert_tuple_eq(color(1, 1, 1), _material.color);
	mu_assert_double_eq(0.1, _material.ambient);
	mu_assert_double_eq(0.9, _material.diffuse);
	mu_assert_double_eq(0.9, _material.specular);
	mu_assert_double_eq(200.0, _material.shininess);
}

MU_TEST(sphere_material_tst)
{
	_sphere = sphere();
	_material = material();

	assert_tuple_eq(_material.color, _sphere->material.color);
	mu_assert_double_eq(_material.ambient, _sphere->material.ambient);
	mu_assert_double_eq(_material.diffuse, _sphere->material.diffuse);
	mu_assert_double_eq(_material.specular, _sphere->material.specular);
	mu_assert_double_eq(_material.shininess, _sphere->material.shininess);
}

MU_TEST(set_sphere_material_tst)
{
	_sphere = sphere();
	_material = material();
	_material.ambient = 1;
	_sphere->material = _material;

	assert_tuple_eq(_material.color, _sphere->material.color);
	mu_assert_double_eq(_material.ambient, _sphere->material.ambient);
	mu_assert_double_eq(_material.diffuse, _sphere->material.diffuse);
	mu_assert_double_eq(_material.specular, _sphere->material.specular);
	mu_assert_double_eq(_material.shininess, _sphere->material.shininess);
}

MU_TEST_SUITE(material_suite)
{
	MU_SUITE_CONFIGURE(&test_setup, &test_teardown);

	MU_RUN_TEST(default_material_tst);
	MU_RUN_TEST(sphere_material_tst);
	MU_RUN_TEST(set_sphere_material_tst);
}

MU_MAIN
{
	MU_DIVIDER;
	MU_RUN_SUITE(material_suite);
	MU_REPORT();
	return (MU_EXIT_CODE);
}
