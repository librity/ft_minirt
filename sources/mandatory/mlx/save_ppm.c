/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_ppm.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 15:45:29 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/12/29 17:18:31 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

static char	*write_header(int width, int height, char *cursor)
{
	char	*width_s;
	char	*height_s;

	width_s = ft_itoa(width);
	height_s = ft_itoa(height);
	cursor = ft_strcpy_end(cursor, "P3\n");
	cursor = ft_strcpy_end(cursor, width_s);
	cursor = ft_strcpy_end(cursor, " ");
	cursor = ft_strcpy_end(cursor, height_s);
	cursor = ft_strcpy_end(cursor, "\n255\n");
	free(width_s);
	free(height_s);
	return (cursor);
}

static char	*write_component(char *cursor, int component)
{
	char	*component_str;

	component_str = ft_itoa(component);
	cursor = ft_strcpy_end(cursor, component_str);
	cursor = ft_strcpy_end(cursor, " ");
	free(component_str);
	return (cursor);
}

static char	*write_color(char *cursor, t_rgb color)
{
	cursor = write_component(cursor, color.red);
	cursor = write_component(cursor, color.green);
	cursor = write_component(cursor, color.blue);
	return (cursor);
}

static void	write_colors(t_mlx_image *image, char *cursor)
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
			cursor = write_color(cursor, color);
			x++;
		}
		cursor = ft_strcpy_end(cursor, "\n");
		y++;
	}
}

static char	*build_buffer(t_mlx_image *image)
{
	size_t	buffer_size;
	char	*buffer;
	char	*cursor;

	buffer_size = 250 + image->height * (image->width * 12 + 1);
	buffer = ft_calloc(1, buffer_size);
	cursor = buffer;
	cursor = write_header(image->width, image->height, cursor);
	write_colors(image, cursor);
	return (buffer);
}

static void	save_buffer(char *buffer, char *filename)
{
	int	fd;

	fd = open(filename, O_CREAT | O_TRUNC | O_WRONLY, 0664);
	ft_putstr_fd(buffer, fd);
	close(fd);
}

void	mlx_image_save_ppm(t_mlx_image *image, char *filename)
{
	char	*buffer;

	buffer = build_buffer(image);
	save_buffer(buffer, filename);
	free(buffer);
}
