/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calcul_ray.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboulhaj <aboulhaj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 15:04:42 by aboulhaj          #+#    #+#             */
/*   Updated: 2022/09/08 19:06:38 by aboulhaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	while_horizontal(t_data *data, t_index inter, t_index step)
{
	double		tmp;
	double		zoom;

	zoom = data->texture.zoom;
	while (inter.y > 0 && (inter.y / zoom) < data->texture.map_size.x \
	&& inter.x > 0 && (inter.x / zoom) < data->texture.map_size.y)
	{
		tmp = inter.y;
		if (data->ray.ray_face.up)
			tmp--;
		if (char_in_str(LIMIT, \
		data->map[(int)(tmp / zoom)][(int)(inter.x / zoom)]))
		{
			data->ray.found_h_wall = 1;
			data->ray.horizontal_touch.x = inter.x;
			data->ray.horizontal_touch.y = inter.y;
			break ;
		}
		else
		{
			inter.x += step.x;
			inter.y += step.y;
		}
	}
}

void	while_vertical(t_data *data, t_index inter, t_index step)
{
	double		tmp;
	double		zoom;

	zoom = data->texture.zoom;
	while (inter.y > 0 && (inter.y / zoom) < data->texture.map_size.x \
	&& inter.x > 0 && (inter.x / zoom) < data->texture.map_size.y)
	{
		tmp = inter.x;
		if (data->ray.ray_face.left)
			tmp--;
		if (char_in_str(LIMIT, \
		data->map[(int)(inter.y / zoom)][(int)(tmp / zoom)]))
		{
			data->ray.found_v_wall = 1;
			data->ray.vertical_touch.x = inter.x;
			data->ray.vertical_touch.y = inter.y;
			break ;
		}
		else
		{
			inter.x += step.x;
			inter.y += step.y;
		}
	}
}

void	horizontal_intersection(t_data *data)
{
	t_index	player;
	t_index	h_inter;
	t_index	step;

	data->ray.found_h_wall = 0;
	player = player_possition(data);
	h_inter.y = data->texture.zoom * ((int)(player.y / data->texture.zoom));
	if (data->ray.ray_face.down)
		h_inter.y += data->texture.zoom;
	h_inter.x = player.x + ((h_inter.y - player.y) / tan(data->ray.angle_ray));
	step.y = data->texture.zoom;
	if (data->ray.ray_face.up)
		step.y *= -1;
	step.x = data->texture.zoom / tan(data->ray.angle_ray);
	if (data->ray.ray_face.left && step.x > 0)
		step.x *= -1;
	if (data->ray.ray_face.right && step.x < 0)
		step.x *= -1;
	while_horizontal(data, h_inter, step);
}

void	vertical_intersection(t_data *data)
{
	t_index	player;
	t_index	step;
	t_index	v_inter;

	data->ray.found_v_wall = 0;
	player = player_possition(data);
	v_inter.x = data->texture.zoom * ((int)(player.x / data->texture.zoom));
	if (data->ray.ray_face.right)
		v_inter.x += data->texture.zoom;
	v_inter.y = player.y + ((v_inter.x - player.x) * tan(data->ray.angle_ray));
	step.x = data->texture.zoom;
	if (data->ray.ray_face.left)
		step.x *= -1;
	step.y = data->texture.zoom * tan(data->ray.angle_ray);
	if (data->ray.ray_face.up && step.y > 0)
		step.y *= -1;
	if (data->ray.ray_face.down && step.y < 0)
		step.y *= -1;
	while_vertical(data, v_inter, step);
}

double	distance_2_point(t_index first, t_index last)
{
	return (sqrt(((last.x - first.x) * (last.x - first.x)) \
	+ ((last.y - first.y) * (last.y - first.y))));
}
