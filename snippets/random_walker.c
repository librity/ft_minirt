/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   random_walker.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/26 03:39:38 by lpaulo-m          #+#    #+#             */
/*   Updated: 2021/04/13 23:44:27 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// clang -I ../includes random_walker.c -lbsd -lmlx -lXext -lX11 && ./a.out
// gcc -I ../includes random_walker.c -lbsd -lmlx -lXext -lX11 && ./a.out

#include "stdbool.h"

#include "mlx_int.h"
#include "mlx_int.h"

void *mlx;

void *window;
const int width = 500;
const int height = 300;

void fill_window(int color)
{
	int x;
	int y;

	x = width;
	while (x--)
	{
		y = height;
		while (y--)
			mlx_pixel_put(mlx, window, x, y, color);
	}
}

void clear_window(void)
{
	fill_window(0x00000000);
}

void blank_window(void)
{
	fill_window(0x00FFFFFF);
}

void die(void)
{
	printf(" ERROR!\n");
	exit(1);
}

void initialize(void)
{
	printf("=== MinilibX Test Program: Random Walker ===\n");

	printf(" => Initializing minilibx...");
	mlx = mlx_init();
	if (mlx == NULL)
		die();
	printf(" OK (use_xshm: %d, pshm_format: %d)\n", ((t_xvar *)mlx)->use_xshm, ((t_xvar *)mlx)->pshm_format);

	printf(" => Creating window %dx%d ...", width, height);
	window = mlx_new_window(mlx, width, height, "Random Walker");
	if (window == NULL)
		die();
	printf(" OK\n");

	// printf(" => Blanking window ...");
	// blank_window();
	// printf(" OK\n");

	printf(" => Clearing window ...");
	// mlx_clear_window(mlx, window);
	clear_window();
	printf(" OK\n");
}

void draw_square(int x, int y, int size, int color)
{
	int half = size / 2;
	int i;
	int j;

	i = -half;
	while (i < half)
	{
		j = -half;
		while (j < half)
		{
			mlx_pixel_put(mlx, window, x + i, y + j, color);
			j++;
		}
		i++;
	}
}

void walk(void)
{
	int x = width / 2;
	int y = height / 2;

	while (true)
	{
		draw_square(x, y, 10, 0x00999999);
		sleep(0.2);
	}
}

int main(void)
{
	initialize();
	walk();
	return (0);
}
