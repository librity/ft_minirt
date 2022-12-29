/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 19:03:08 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/12/29 15:00:44 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

void	mlx_demo_img(void)
{
	int	x;
	int	y;

	x = 0;
	while (x < width())
	{
		y = 0;
		while (y < height())
		{
			mlx_image_draw_rgb(&c()->camera.buffer, rgb_red(), x, y);
			y++;
		}
		x++;
	}
	mlx_put_image_to_window(mlx(), window(), camera_buffer()->img, 0,
		0);
}

void	mlx_hello_world_img(void)
{
	int		x;
	int		y;
	t_c3d	color;

	x = 0;
	while (x < width())
	{
		y = 0;
		while (y < height())
		{
			color.x = (double) x / width() - 1;
			color.y = (double) y / height() - 1;
			color.z = 0.25;

			mlx_image_draw_c3d(&c()->camera.buffer, color, x, y);
			y++;
		}
		x++;
	}
	mlx_put_image_to_window(mlx(), window(), camera_buffer()->img, 0,
		0);
}

void	mlx_image_header(int fd, int width, int height)
{
	char	*width_s;
	char	*height_s;

	width_s = ft_itoa(width);
	height_s = ft_itoa(height);
	ft_putendl_fd("P3", fd);
	ft_putstr_fd(width_s, fd);
	ft_putstr_fd(" ", fd);
	ft_putendl_fd(height_s, fd);
	ft_putendl_fd("255", fd);
	free(width_s);
	free(height_s);
}

void	write_color_to_ppm(int fd, t_rgb color)
{
	char	*red_s;
	char	*green_s;
	char	*blue_s;

	red_s = ft_itoa(color.red);
	green_s = ft_itoa(color.green);
	blue_s = ft_itoa(color.blue);
	ft_putstr_fd(red_s, fd);
	ft_putstr_fd(" ", fd);
	ft_putstr_fd(green_s, fd);
	ft_putstr_fd(" ", fd);
	ft_putstr_fd(blue_s, fd);
	ft_putstr_fd(" ", fd);
	free(red_s);
	free(green_s);
	free(blue_s);
}

void	mlx_image_save_ppm(t_mlx_image *image, char *filename)
{
	int		fd;
	int		x;
	int		y;
	t_rgb	color;

	fd = open(filename, O_CREAT | O_TRUNC | O_WRONLY, 0664);
	mlx_image_header(fd, image->width, image->height);
	y = 0;
	while (y < image->height)
	{
		x = 0;
		while (x < image->width)
		{
			color = int_to_rgb(mlx_image_get_pixel_int(image, x, y));
			write_color_to_ppm(fd, color);
			x++;
		}
		ft_putstr_fd("\n", fd);
		y++;
		ft_putstr(".");
	}
	close(fd);
}


void	ppm_hello_world_img(void)
{
	int		x;
	int		y;
	t_c3d	color;

	x = 0;
	while (x < width())
	{
		y = 0;
		while (y < height())
		{
			color.x = (double) x / width() - 1;
			color.y = (double) y / height() - 1;
			color.z = 0.25;

			mlx_image_draw_c3d(&c()->camera.buffer, color, x, y);
			y++;
		}
		x++;
	}

	mlx_image_save_ppm(camera_buffer(), "teste.ppm");
}
