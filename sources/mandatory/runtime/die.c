/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   die.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 13:15:13 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/12/09 13:20:19 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

void print_error(char *error_message)
{
	printf("Error\n%s\n", error_message);
}

void die(char *error_message)
{
	print_error(error_message);
	exit(EXIT_FAILURE);
}
