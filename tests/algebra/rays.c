/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rays.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 18:47:59 by lpaulo-m          #+#    #+#             */
/*   Updated: 2023/01/25 19:23:48 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../tests.h"

t_ray	result;
t_ray	_ray;
t_t3d	expected_t3d;
t_object	*_sphere;
t_intxs	xs;
t_dlist		*intersections;
t_intx	*inter;
t_matrix	mx;
double	t;

void test_setup(void)
{
}
void test_teardown(void)
{
	free_world_lalloc();
}

MU_TEST(rays_tst)
{
	result = ray(point(1, 2, 3), vector(4, 5, 6));

	expected_t3d = point(1, 2, 3);
	assert_tuple_eq(expected_t3d, result.origin);

	expected_t3d = vector(4, 5, 6);
	assert_tuple_eq(expected_t3d, result.direction);
}

MU_TEST(position_tst)
{
	_ray = ray(point(2, 3, 4), vector(1, 0, 0));

	expected_t3d = position(_ray, 0);
	assert_tuple_eq(expected_t3d, point(2, 3, 4));

	expected_t3d = position(_ray, 1);
	assert_tuple_eq(expected_t3d, point(3, 3, 4));

	expected_t3d = position(_ray, -1);
	assert_tuple_eq(expected_t3d, point(1, 3, 4));

	expected_t3d = position(_ray, 2.5);
	assert_tuple_eq(expected_t3d, point(4.5, 3, 4));
}

MU_TEST(ray_intersects_tst)
{
	_ray = ray(point(0, 0, -5), vector(0, 0, 1));
	_sphere = sphere();
	xs = intersect_sphere(_sphere, _ray);

	mu_assert_int_eq(2, xs.count);

	inter = xs.list->content;
	mu_assert_double_eq(4.0, inter->t);
	mu_check(_sphere == inter->object);

	inter = xs.list->next->content;
	mu_assert_double_eq(6.0, inter->t);
	mu_check(_sphere == inter->object);
}

MU_TEST(ray_misses_tst)
{
	_ray = ray(point(0, 2, -5), vector(0, 0, 1));
	_sphere = sphere();
	xs = intersect_sphere(_sphere, _ray);

	mu_assert_int_eq(0, xs.count);
}

MU_TEST(ray_inside_tst)
{
	_ray = ray(point(0, 0, 0), vector(0, 0, 1));
	_sphere = sphere();
	xs = intersect_sphere(_sphere, _ray);

	mu_assert_int_eq(2, xs.count);

	inter = xs.list->content;
	mu_assert_double_eq(-1.0, inter->t);
	mu_check(_sphere == inter->object);

	inter = xs.list->next->content;
	mu_assert_double_eq(1.0, inter->t);
	mu_check(_sphere == inter->object);
}


MU_TEST(ray_behind_tst)
{
	_ray = ray(point(0, 0, 5), vector(0, 0, 1));
	_sphere = sphere();
	xs = intersect_sphere(_sphere, _ray);

	mu_assert_int_eq(2, xs.count);
	inter = xs.list->content;
	mu_assert_double_eq(-6.0, inter->t);
	mu_check(_sphere == inter->object);

	inter = xs.list->next->content;
	mu_assert_double_eq(-4.0, inter->t);
	mu_check(_sphere == inter->object);
}

MU_TEST(intersection_tst)
{
	_sphere = sphere();
	inter = new_intersection(3.5, _sphere);

	mu_assert_double_eq(3.5, inter->t);
	mu_check(_sphere == inter->object);
}

MU_TEST(add_intersection_tst)
{
	_sphere = sphere();
	create_intersection(&intersections, 1, _sphere);
	create_intersection(&intersections, 2, _sphere);

	mu_assert_int_eq(2, ft_dlstsize(intersections));

	inter = intersections->content;
	mu_assert_double_eq(1, inter->t);

	inter = intersections->next->content;
	mu_assert_double_eq(2, inter->t);
}

MU_TEST(hit_tst){
	_sphere = sphere();

	xs.list = NULL;
	xs.count = 2;
	create_intersection(&xs.list, 1, _sphere);
	create_intersection(&xs.list, 2, _sphere);

	inter = hit(xs);
	mu_assert_double_eq(1, inter->t);
	mu_check(_sphere == inter->object);
}

MU_TEST(hit_negative_tst){
	_sphere = sphere();

	xs.list = NULL;
	xs.count = 2;
	create_intersection(&xs.list, -1, _sphere);
	create_intersection(&xs.list, 1, _sphere);

	inter = hit(xs);
	mu_assert_double_eq(1, inter->t);
	mu_check(_sphere == inter->object);
}

MU_TEST(hit_positive_negative_tst){
	_sphere = sphere();

	xs.list = NULL;
	xs.count = 2;
	create_intersection(&xs.list, 1, _sphere);
	create_intersection(&xs.list, -1, _sphere);

	inter = hit(xs);
	mu_assert_double_eq(1, inter->t);
	mu_check(_sphere == inter->object);
}

MU_TEST(hit_all_negative_tst){
	_sphere = sphere();

	xs.list = NULL;
	xs.count = 2;
	create_intersection(&xs.list, -2, _sphere);
	create_intersection(&xs.list, -1, _sphere);

	inter = hit(xs);
	mu_check(NULL == inter);
}

MU_TEST(hit_multiple_tst){
	_sphere = sphere();

	xs.list = NULL;
	xs.count = 4;
	create_intersection(&xs.list, 5, _sphere);
	create_intersection(&xs.list, 7, _sphere);
	create_intersection(&xs.list, -3, _sphere);
	create_intersection(&xs.list, 2, _sphere);

	inter = hit(xs);
	mu_assert_double_eq(2, inter->t);
	mu_check(_sphere == inter->object);
}

MU_TEST(transform_translation_tst){

	_ray = ray(point(1, 2, 3), vector(0, 1, 0));
	translation(vector(3, 4, 5), &mx);
	result = transform(_ray, mx);

	assert_tuple_eq(point(4, 6, 8), result.origin);
	assert_tuple_eq(vector(0, 1, 0), result.direction);
}

MU_TEST(transform_scaling_tst){
	_ray = ray(point(1, 2, 3), vector(0, 1, 0));
	scaling(vector(2, 3, 4), &mx);
	result = transform(_ray, mx);

	assert_tuple_eq(point(2, 6, 12), result.origin);
	assert_tuple_eq(vector(0, 3, 0), result.direction);
}

MU_TEST(sphere_transform_tst){
	_sphere = sphere();

	mx_set_identity(&mx);
	mu_check(mxs_are_equal(mx, _sphere->transform));

	translation(vector(2, 3, 4), &mx);
	set_transform(_sphere, mx);
	mu_check(mxs_are_equal(mx, _sphere->transform));
}

MU_TEST(intersect_scaled_tst)
{
	_ray = ray(point(0, 0, -5), vector(0, 0, 1));
	_sphere = sphere();
	scaling(vector(2, 2, 2), &mx);
	set_transform(_sphere, mx);
	xs = intersect_sphere(_sphere, _ray);

	mu_assert_int_eq(2, xs.count);

	inter = xs.list->content;
	mu_assert_double_eq(3.0, inter->t);
	mu_check(_sphere == inter->object);

	inter = xs.list->next->content;
	mu_assert_double_eq(7.0, inter->t);
	mu_check(_sphere == inter->object);
}

MU_TEST(intersect_translated_tst)
{
	_ray = ray(point(0, 0, -5), vector(0, 0, 1));
	_sphere = sphere();
	translation(vector(5, 0, 0), &mx);
	set_transform(_sphere, mx);
	xs = intersect_sphere(_sphere, _ray);

	mu_assert_int_eq(0, xs.count);
}

MU_TEST_SUITE(rays_suite)
{
	MU_SUITE_CONFIGURE(&test_setup, &test_teardown);

	MU_RUN_TEST(rays_tst);
	MU_RUN_TEST(position_tst);

	MU_RUN_TEST(ray_intersects_tst);
	MU_RUN_TEST(ray_inside_tst);
	MU_RUN_TEST(ray_misses_tst);
	MU_RUN_TEST(ray_behind_tst);
	MU_RUN_TEST(intersect_scaled_tst);
	MU_RUN_TEST(intersect_translated_tst);


	MU_RUN_TEST(intersection_tst);
	MU_RUN_TEST(add_intersection_tst);

	MU_RUN_TEST(hit_tst);
	MU_RUN_TEST(hit_negative_tst);
	MU_RUN_TEST(hit_positive_negative_tst);
	MU_RUN_TEST(hit_all_negative_tst);
	MU_RUN_TEST(hit_multiple_tst);

	MU_RUN_TEST(transform_translation_tst);
	MU_RUN_TEST(transform_scaling_tst);

	MU_RUN_TEST(sphere_transform_tst);
}

MU_MAIN
{
	MU_DIVIDER;
	MU_RUN_SUITE(rays_suite);
	MU_REPORT();
	return (MU_EXIT_CODE);
}
