/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   die.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 00:17:03 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/03/21 16:11:14 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

const char	*g_error_messages[EC_GENERIC] = {
	"Couldn't initialize mlx.",
	"Couldn't create mlx window.",
	"Generic miniRT error.",
};

void	help_and_die(void)
{
	ft_putstr(HELP_MSG);
	exit(EXIT_FAILURE);
}

static void	print_error(char *message)
{
	ft_putstr(R);
	ft_putendl(ERR_INDICATOR);
	ft_putstr(message);
	ft_putendl(RC);
}

void	die(t_errors code)
{
	print_error((char *)g_error_messages[code]);
	exit(EXIT_FAILURE);
}

void	die_if_null(void *ptr, t_errors code)
{
	if (ptr == NULL)
		die(code);
}
