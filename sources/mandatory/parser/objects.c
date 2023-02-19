/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   objects.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 19:12:59 by lpaulo-m          #+#    #+#             */
/*   Updated: 2023/02/19 17:03:34 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

void	parse_sphere(char *line)
{
	t_p3d		origin;
	double		diameter;
	t_rgb		color;
	t_object	*_sphere;
	t_matrix	translation_mx;

	line = skip_field(line);
	origin = parse_point(line);
	line = skip_field(line);
	diameter = ft_atof(line);
	line = skip_field(line);
	color = parse_color(line);
	_sphere = create_sphere(point(0, 0, 0), diameter, color);
	translation((t_v3d)origin, &translation_mx);
	multiply_transform(_sphere, translation_mx);
}

void	rotate_plane(t_object *_plane, t_v3d new_normal)
{
	t_matrix	identity_mx;
	t_matrix	skew_mx;
	t_matrix	axis_mx;
	t_matrix	axis_transposed_mx;
	t_matrix	axis_scaled_mx;
	t_matrix	mx_1;
	t_matrix	mx_2;
	t_v3d		old_normal;
	t_v3d		rotation_axis;
	double		theta;
	double		cos_theta;

	old_normal = _plane->normal;
	theta = acos(dot(old_normal, new_normal));
	cos_theta = cos(theta);
	rotation_axis = cross(old_normal, new_normal);

	mx_set_identity(&identity_mx);
	mx_scalar_multiply(&identity_mx, cos_theta);

	skew_symmetric_matrix(rotation_axis, &skew_mx);
	mx_scalar_multiply(&skew_mx, sin(theta));

	mx_clear(&axis_mx);
	axis_mx[0][0] = rotation_axis.x;
	axis_mx[1][0] = rotation_axis.y;
	axis_mx[2][0] = rotation_axis.z;

	mx_clear(&axis_transposed_mx);
	axis_transposed_mx[0][0] = rotation_axis.x;
	axis_transposed_mx[0][1] = rotation_axis.y;
	axis_transposed_mx[0][2] = rotation_axis.z;

	mxs_multiply(axis_mx, axis_transposed_mx, &axis_scaled_mx);
	mx_scalar_multiply(&axis_scaled_mx, (1.0 - cos_theta));

	mx_add(identity_mx, skew_mx, &mx_1);
	mx_add(mx_1, axis_scaled_mx, &mx_2);
	multiply_transform(_plane, mx_2);
}

void	parse_plane(char *line)
{
	t_p3d		origin;
	t_p3d		normal;
	t_rgb		color;
	t_object	*_plane;
	t_matrix	translation_mx;

	line = skip_field(line);
	origin = parse_point(line);
	line = skip_field(line);
	normal = parse_vector(line);
	line = skip_field(line);
	color = parse_color(line);
	_plane = create_plane(origin, normal, color);
	rotate_plane(_plane, normal);
	translation((t_v3d)origin, &translation_mx);
	multiply_transform(_plane, translation_mx);
}

void	parse_cylinder(char *line)
{
	t_create_cylinder	p;

	line = skip_field(line);
	p.origin = parse_point(line);
	line = skip_field(line);
	p.normal = parse_vector(line);
	line = skip_field(line);
	p.diameter = ft_atof(line);
	line = skip_field(line);
	p.height = ft_atof(line);
	line = skip_field(line);
	p.color = parse_color(line);
	p._cylinder = create_cylinder(p);
	translation((t_v3d)p.origin, &p.translation_mx);
	multiply_transform(p._cylinder, p.translation_mx);
}
