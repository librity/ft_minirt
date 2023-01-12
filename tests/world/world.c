#include "../tests.h"

t_light expected_light;
t_light result_light;
t_dlist *node;
t_object *_object;
t_matrix mx;

void test_setup(void)
{
}
void test_teardown(void)
{
	free_lalloc();
}

MU_TEST(default_world_tst)
{
	set_default_world();

	expected_light = point_light(
		point(-10, 10, -10), 1.0,
		color_rgb(255, 255, 255));
	result_light = light();
	assert_tuple_eq(expected_light.origin, result_light.origin);
	assert_tuple_eq(expected_light.color_3d, result_light.color_3d);
	assert_tuple_eq(expected_light.intensity, result_light.intensity);
	mu_assert_double_eq(expected_light.brightness, result_light.brightness);

	node = *objects();
	mu_check(node != NULL);

	_object = node->content;
	assert_tuple_eq(color(0.8, 1.0, 0.6), _object->material.color);
	mu_assert_double_eq(0.7, _object->material.diffuse);
	mu_assert_double_eq(0.2, _object->material.specular);

	_object = node->next->content;
	scaling(vector(0.5, 0.5, 0.5), &mx);
	mu_check(mxs_are_equal(mx, _object->transform));
}

MU_TEST_SUITE(world_suite)
{
	MU_SUITE_CONFIGURE(&test_setup, &test_teardown);

	MU_RUN_TEST(default_world_tst);
}

MU_MAIN
{
	MU_DIVIDER;
	MU_RUN_SUITE(world_suite);
	MU_REPORT();
	return (MU_EXIT_CODE);
}
