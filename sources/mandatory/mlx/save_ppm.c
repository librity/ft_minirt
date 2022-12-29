/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_ppm.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 15:45:29 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/12/29 16:13:30 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

static void	write_header(int fd, int width, int height)
{
	char	*header;

	header = ft_strdup("P3\n");
	header = ft_strjoin_free_free(header, ft_itoa(width));
	header = ft_strjoin_free(header, " ");
	header = ft_strjoin_free_free(header, ft_itoa(height));
	header = ft_strjoin_free(header, "\n255\n");
	ft_putstr_fd(header, fd);
	free(header);
}

static void	write_color(int fd, t_rgb color)
{
	char	*pixel;

	pixel = ft_itoa(color.red);
	pixel = ft_strjoin_free(pixel, " ");
	pixel = ft_strjoin_free_free(pixel, ft_itoa(color.green));
	pixel = ft_strjoin_free(pixel, " ");
	pixel = ft_strjoin_free_free(pixel, ft_itoa(color.blue));
	pixel = ft_strjoin_free(pixel, " ");
	ft_putstr_fd(pixel, fd);
	free(pixel);
}

static void	write_colors(t_mlx_image *image, int fd)
{
	int		x;
	int		y;
	t_rgb	color;

	y = 0;
	while (y < image->height)
	{
		x = 0;
		while (x < image->width)
		{
			color = mlx_image_get_pixel_rgb(image, x, y);
			write_color(fd, color);
			x++;
		}
		ft_putstr_fd("\n", fd);
		y++;
		ft_putstr(".");
	}
}

void	mlx_image_save_ppm(t_mlx_image *image, char *filename)
{
	int	fd;

	fd = open(filename, O_CREAT | O_TRUNC | O_WRONLY, 0664);
	write_header(fd, image->width, image->height);
	write_colors(image, fd);
	close(fd);
}
