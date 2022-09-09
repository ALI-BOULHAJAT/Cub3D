/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_circle.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboulhaj <aboulhaj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 09:52:43 by aboulhaj          #+#    #+#             */
/*   Updated: 2022/09/09 18:42:49 by aboulhaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

double	ft_diff(double x, double y)
{
	return (y - x);
}

t_index	player_possition(t_data *data)
{
	t_index	index;

	index.x = data->player.init_y_player + data->player.player_x;
	index.y = data->player.init_x_player + data->player.player_y;
	index.x *= data->texture.zoom;
	index.y *= data->texture.zoom;
	return (index);
}

void	draw_fov(t_data *data)
{
	t_index	player;
	t_index	ray;
	int		index;

	index = 0;
	player = player_possition(data);
	data->ray.angle_ray = data->player.alpha - (30 * (M_PI / 180));
	while (index < WEIGHT)
	{
		facing_ray(data);
		horizontal_intersection(data);
		vertical_intersection(data);
		get_distance(data, &ray);
		draw_line(data, player, ray, FOV_COLOR);
		data->ray.angle_ray += ((60 * (M_PI / 180)) / WEIGHT);
		index++;
	}
}

void	draw_line(t_data *data, t_index first, t_index last, int color)
{
	double	i;
	double	step;

	i = 0;
	if (fabs(ft_diff(first.x, last.x)) > fabs(ft_diff(first.y, last.y)))
		step = fabs(ft_diff(first.x, last.x));
	else
		step = fabs(ft_diff(first.y, last.y));
	while (i <= step)
	{
		if (data->map[abs((int)first.y / data->texture.zoom)] \
		[abs((int)first.x / data->texture.zoom)] == '1')
			break ;
		ft_put_pixel(first.x, first.y, data, color);
		first.x += ft_diff(first.x, last.x) / step;
		first.y += ft_diff(first.y, last.y) / step;
		i += 0.1;
	}
}

void	get_distance(t_data *data, t_index *ray)
{
	double	h_distance;
	double	v_distance;
	t_index	player;

	h_distance = 0;
	v_distance = 0;
	player = player_possition(data);
	if (data->ray.found_h_wall)
		h_distance = distance_2_point(player, data->ray.horizontal_touch);
	if (data->ray.found_v_wall)
		v_distance = distance_2_point(player, data->ray.vertical_touch);
	if (h_distance > v_distance)
	{
		(*ray).x = data->ray.vertical_touch.x;
		(*ray).y = data->ray.vertical_touch.y;
	}
	else
	{
		(*ray).x = data->ray.horizontal_touch.x;
		(*ray).y = data->ray.horizontal_touch.y;
	}
}
