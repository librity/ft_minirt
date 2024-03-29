/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/20 21:53:02 by lpaulo-m          #+#    #+#             */
/*   Updated: 2023/01/25 20:35:15 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TESTS_H
# define TESTS_H

# include "minunit.h"
# include <fcntl.h>
# include <minirt.h>
# include <sys/wait.h>

# define MY_PI           3.14159265358979323846

void assert_strarr_eq(char **expected, char **result)
{
	int i;

	if (expected == NULL && result == NULL)
		return;
	i = 0;
	while (i < (int)ft_strarr_size(expected))
	{
		mu_assert_string_eq(expected[i], result[i]);
		i++;
	}
}

void assert_in_strarr(char **haystack, char *needle)
{
	mu_check(true == ft_str_in_strarr(haystack, needle));
}

void assert_strarr_equivalent(char **expected, char **result)
{
	int i;

	if (expected == NULL && result == NULL)
		return;
	i = 0;
	while (i < (int)ft_strarr_len(expected))
	{
		assert_in_strarr(result, expected[i]);
		i++;
	}
}

void assert_dlist_eq(t_dlist *expected, t_dlist *result, size_t content_size)
{
	void	*expected_content;
	void	*result_result;

	mu_check(ft_dlstsize(expected) == ft_dlstsize(result));

	while (expected != NULL)
	{
		expected_content = expected->content;
		result_result = result->content;
		mu_check(0 == ft_memcmp(expected_content, result_result, content_size));
		expected = expected->next;
		result = result->next;
	}
}

typedef void (*t_content_cb)(void *, void *);
void assert_dlist_equivalent(t_dlist *expected, t_dlist *result, t_content_cb compare)
{
	void	*expected_content;
	void	*result_result;

	mu_check(ft_dlstsize(expected) == ft_dlstsize(result));

	while (expected != NULL)
	{
		expected_content = expected->content;
		result_result = result->content;
		compare(expected_content, result_result);
		expected = expected->next;
		result = result->next;
	}
}

void assert_tuple_eq(t_t3d _expected, t_t3d _result)
{
	mu_assert_double_eq(_expected.x, _result.x);
	mu_assert_double_eq(_expected.y, _result.y);
	mu_assert_double_eq(_expected.z, _result.z);
	mu_assert_double_eq(_expected.type, _result.type);
}

void assert_material_eq(t_material _expected, t_material _result)
{
	assert_tuple_eq(_expected.color, _result.color);
	mu_assert_double_eq(_expected.ambient, _result.ambient);
	mu_assert_double_eq(_expected.shininess, _result.shininess);
	mu_assert_double_eq(_expected.diffuse, _result.diffuse);
	mu_assert_double_eq(_expected.specular, _result.specular);
}

#endif
