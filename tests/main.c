/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/13 22:59:02 by lpaulo-m          #+#    #+#             */
/*   Updated: 2021/03/26 03:18:54 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <tests.h>

void setUp(void){};

void tearDown(void){};

int main(void)
{
	UNITY_BEGIN();

	RUN_TEST(test_something);

	return UNITY_END();
}
