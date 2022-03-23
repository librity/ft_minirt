/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 00:17:03 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/03/22 23:06:44 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

const char	*g_error_messages[EC_GENERIC] = {
	"Couldn't initialize mlx.",
	"Couldn't create mlx window.",
	"Couldn't open scene file.",
	"Couldn't read scene file (GNL).",
	"Invalid scene identifier.",
	"Ambient light brightness should be a double in range [0.0,1.0].",
	"Ambient light color should be three comma-separated ints in range\
[0-255].",
	"Generic miniRT error.",
};

void	print_error(int code)
{
	ft_redb_endl(ERR_INDICATOR);
	ft_red_endl((char *)g_error_messages[code - 1]);
}
