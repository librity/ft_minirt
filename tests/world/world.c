#include "../tests.h"

t_light expected_light;
t_light result_light;
t_dlist *node;
t_object *_object;
t_object *_inner;
t_object *_outer;
t_matrix mx;
t_ray	_ray;
t_intx	*_intersection;
t_intxs	_intersections;
t_intx	_intersect;
t_ray_comp	_ray_comp;
t_c3d		_color;

void test_setup(void)
{
	c()->objects = NULL;
}
void test_teardown(void)
{
	free_world_lalloc();
	c()->objects = NULL;
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

	mu_assert_int_eq(2, ft_dlstsize(*objects()));
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

MU_TEST(intersect_ray_tst)
{
	set_default_world();

	_ray = ray(point(0, 0, -5), vector(0, 0, 1));
	_intersections = intersect_world(_ray);

	mu_assert_int_eq(4, ft_dlstsize(_intersections.list));
	mu_assert_int_eq(4, _intersections.count);

	node = _intersections.list;
	_intersection = node->content;
	mu_assert_double_eq(4, _intersection->t);

	node =node->next;
	_intersection = node->content;
	mu_assert_double_eq(4.5, _intersection->t);

	node =node->next;
	_intersection = node->content;
	mu_assert_double_eq(5.5, _intersection->t);

	node =node->next;
	_intersection = node->content;
	mu_assert_double_eq(6, _intersection->t);
}

MU_TEST(precomp_intersect_tst){
	_ray = ray(point(0, 0, -5), vector(0, 0, 1));
	_object = sphere();
	_intersect = (t_intx){4.0, _object};
	_ray_comp = prepare_computations(_intersect, _ray);

	mu_assert_double_eq(_intersect.t, _ray_comp.t);
	mu_check(_ray_comp.object == _intersect.object);
	assert_tuple_eq(point(0, 0, -1), _ray_comp.point);
	assert_tuple_eq(vector(0, 0, -1), _ray_comp.eyev);
	assert_tuple_eq(vector(0, 0, -1), _ray_comp.normalv);
}

MU_TEST(precomp_outside_tst){
	_ray = ray(point(0, 0, -5), vector(0, 0, 1));
	_object = sphere();
	_intersect = (t_intx){4.0, _object};
	_ray_comp = prepare_computations(_intersect, _ray);

	mu_check(_ray_comp.inside == false);
}

MU_TEST(precomp_inside_tst){
	_ray = ray(point(0, 0, 0), vector(0, 0, 1));
	_object = sphere();
	_intersect = (t_intx){1.0, _object};
	_ray_comp = prepare_computations(_intersect, _ray);


	mu_check(_ray_comp.object == _intersect.object);
	assert_tuple_eq(point(0, 0, 1), _ray_comp.point);
	assert_tuple_eq(vector(0, 0, -1), _ray_comp.eyev);
	assert_tuple_eq(vector(0, 0, -1), _ray_comp.normalv);
	mu_check(_ray_comp.inside == true);
}

// Scenario: The hit should offset the point
//  Given r ← ray(point(0, 0, -5), vector(0, 0, 1))
//  And shape ← sphere() with:
//  | transform | translation(0, 0, 1) |
//  And i ← intersection(5, shape)
//  When comps ← prepare_computations(i, r)
//  Then comps.over_point.z < -EPSILON/2
//  And comps.point.z > comps.over_point.z
MU_TEST(precomp_over_point_tst){
	_ray = ray(point(0, 0, -5), vector(0, 0, 1));
	_object = sphere();
	translation(vector(0, 0, 1), &_object->transform);
	_intersect = (t_intx){5.0, _object};
	_ray_comp = prepare_computations(_intersect, _ray);

	mu_check(_ray_comp.over_point.z < -NEAR_ZERO_TOLERANCE/2.0);
	mu_check(_ray_comp.point.z > _ray_comp.over_point.z);
}

MU_TEST(shading_intersection_tst)
{
	set_default_world();
	_ray = ray(point(0, 0, -5), vector(0, 0, 1));
	_object = (*objects())->content;
	_intersect = (t_intx){4.0, _object};
	_ray_comp = prepare_computations(_intersect, _ray);
	_color = shade_hit(_ray_comp);

	assert_tuple_eq(color_3d(0.38066, 0.47583, 0.2855), _color);
}

MU_TEST(shading_intersection_inside_tst)
{
	set_default_world();
	set_light(point(0, 0.25, 0), 1.0);
	_ray = ray(point(0, 0, 0), vector(0, 0, 1));
	_object = (*objects())->next->content;
	_intersect = (t_intx){0.5, _object};
	_ray_comp = prepare_computations(_intersect, _ray);
	_color = shade_hit(_ray_comp);

	assert_tuple_eq(color_3d(0.90498, 0.90498, 0.90498), _color);
}

MU_TEST(shade_hit_shadow_tst)
{
	// set_default_world();
	set_light(point(0, 0, -10), 1.0);
	_object = sphere();
	_object = sphere();
	translation(vector(0, 0, 10), &_object->transform);
	_ray = ray(point(0, 0, 5), vector(0, 0, 1));
	_intersect = (t_intx){4, _object};
	_ray_comp = prepare_computations(_intersect, _ray);
	_color = shade_hit(_ray_comp);

	assert_tuple_eq(color_3d(0.1, 0.1, 0.1), _color);
}

MU_TEST(color_at_misses_tst)
{
	set_default_world();
	_ray = ray(point(0, 0, -5), vector(0, 1, 0));
	_color = color_at(_ray);

	assert_tuple_eq(color(0.0, 0.0, 0.0), _color);
}

MU_TEST(color_at_hits_tst)
{
	set_default_world();
	_ray = ray(point(0, 0, -5), vector(0, 0, 1));
	_color = color_at(_ray);

	assert_tuple_eq(color(0.38066, 0.47583, 0.2855), _color);
}

MU_TEST(color_at_behind_tst)
{
	set_default_world();
	_outer = (*objects())->content;
	_outer->material.ambient = 1.0;
	_inner = (*objects())->next->content;
	_inner->material.ambient = 1.0;

	_ray = ray(point(0, 0, 0.75), vector(0, 0, -1));
	_color = color_at(_ray);
	assert_tuple_eq(_inner->material.color, _color);
}

MU_TEST_SUITE(world_suite)
{
	MU_SUITE_CONFIGURE(&test_setup, &test_teardown);

	MU_RUN_TEST(default_world_tst);
	MU_RUN_TEST(intersect_ray_tst);

	MU_RUN_TEST(precomp_intersect_tst);
	MU_RUN_TEST(precomp_outside_tst);
	MU_RUN_TEST(precomp_inside_tst);
	MU_RUN_TEST(precomp_over_point_tst);

	MU_RUN_TEST(shading_intersection_tst);
	MU_RUN_TEST(shading_intersection_inside_tst);
	MU_RUN_TEST(shade_hit_shadow_tst);

	MU_RUN_TEST(color_at_misses_tst);
	MU_RUN_TEST(color_at_hits_tst);
	MU_RUN_TEST(color_at_behind_tst);
}

MU_MAIN
{
	MU_DIVIDER;
	MU_RUN_SUITE(world_suite);
	MU_REPORT();
	return (MU_EXIT_CODE);
}
