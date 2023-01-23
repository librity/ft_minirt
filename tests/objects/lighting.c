/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lighting.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 18:37:51 by lpaulo-m          #+#    #+#             */
/*   Updated: 2023/01/23 18:27:21 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../tests.h"

t_object	*_sphere;
t_material	_material;
t_p3d		_position;
t_light		_light;
t_v3d		eye;
t_v3d		normal;
t_c3d		expected_color;
t_c3d		result_color;

void	test_setup(void)
{
	_material = material();
	_position = point(0, 0, 0);
}
void	test_teardown(void)
{
	free_world_lalloc();
}

MU_TEST(eye_tst)
{
	eye = vector(0, 0, -1);
	normal = vector(0, 0, -1);
	_light = point_light(point(0, 0, -10), 1.0, color_rgb(255, 255, 255));
	result_color = lighting(_material, _light, _position, eye, normal, false);
	expected_color = color_3d(1.9, 1.9, 1.9);

	assert_tuple_eq(expected_color, result_color);
}

MU_TEST(eye_fortyfive_degree_tst)
{
	eye = vector(0, sqrt(2) / 2, -sqrt(2) / 2);
	normal = vector(0, 0, -1);
	_light = point_light(point(0, 0, -10), 1.0, color_rgb(255, 255, 255));
	result_color = lighting(_material, _light, _position, eye, normal, false);
	expected_color = color_3d(1.0, 1.0, 1.0);

	assert_tuple_eq(expected_color, result_color);
}

MU_TEST(light_fortyfive_degree_tst)
{
	eye = vector(0, 0, -1);
	normal = vector(0, 0, -1);
	_light = point_light(point(0, 10, -10), 1.0, color_rgb(255, 255, 255));
	result_color = lighting(_material, _light, _position, eye, normal, false);
	expected_color = color_3d(0.7364, 0.7364, 0.7364);

	assert_tuple_eq(expected_color, result_color);
}

MU_TEST(light_ninety_degree_tst)
{
	eye = vector(0, -sqrt(2)/2, -sqrt(2)/2);
	normal = vector(0, 0, -1);
	_light = point_light(point(0, 10, -10), 1.0, color_rgb(255, 255, 255));
	result_color = lighting(_material, _light, _position, eye, normal, false);
	expected_color = color_3d(1.6364, 1.6364, 1.6364);

	assert_tuple_eq(expected_color, result_color);
}

MU_TEST(light_behind_tst)
{
	eye = vector(0, 0, -1);
	normal = vector(0, 0, -1);
	_light = point_light(point(0, 0, 10), 1.0, color_rgb(255, 255, 255));
	result_color = lighting(_material, _light, _position, eye, normal, false);
	expected_color = color_3d(0.1, 0.1, 0.1);

	assert_tuple_eq(expected_color, result_color);
}

MU_TEST(lighting_shadow_tst)
{
	eye = vector(0, 0, -1);
	normal = vector(0, 0, -1);
	_light = point_light(point(0, 0, -10), 1.0, color_rgb(255, 255, 255));
	result_color = lighting(_material, _light, _position, eye, normal, true);

	assert_tuple_eq(color(0.1, 0.1, 0.1), result_color);
}

MU_TEST_SUITE(lighting_suite)
{
	MU_SUITE_CONFIGURE(&test_setup, &test_teardown);

	MU_RUN_TEST(eye_tst);
	MU_RUN_TEST(eye_fortyfive_degree_tst);
	MU_RUN_TEST(light_fortyfive_degree_tst);
	MU_RUN_TEST(light_ninety_degree_tst);
	MU_RUN_TEST(light_behind_tst);

	MU_RUN_TEST(lighting_shadow_tst);
}

MU_MAIN
{
	MU_DIVIDER;
	MU_RUN_SUITE(lighting_suite);
	MU_REPORT();
	return (MU_EXIT_CODE);
}
