/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_key.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboulhaj <aboulhaj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 19:45:58 by aboulhaj          #+#    #+#             */
/*   Updated: 2022/09/08 16:07:28 by aboulhaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

int	ft_check_wall(t_data *data, double x_plus, double y_plus)
{
	t_index	player;
	t_index	pre_point;

	player.x = data->player.init_x_player + data->player.player_y + x_plus;
	player.y = data->player.init_y_player + data->player.player_x + y_plus;
	pre_point.x = player.x - x_plus;
	pre_point.y = player.y - y_plus;
	if ((data->map[(int)pre_point.x][(int)pre_point.y]) == '2' \
	&& (data->map[(int)player.x][(int)player.y]) == '3')
		return (0);
	if ((data->map[(int)pre_point.x][(int)pre_point.y]) == '3' \
	&& (data->map[(int)player.x][(int)player.y]) == '2')
		return (0);
	if (char_in_str(LIMIT, data->map[(int)player.x][(int)player.y]))
		return (0);
	return (1);
}

void	facing_ray(t_data *data)
{
	double	angle;

	angle = data->ray.angle_ray;
	if (angle > 0 && angle < M_PI)
	{
		data->ray.ray_face.down = 1;
		data->ray.ray_face.up = 0;
	}
	else
	{
		data->ray.ray_face.down = 0;
		data->ray.ray_face.up = 1;
	}
	if (angle < (0.5 * M_PI) || angle > (1.5 * M_PI))
	{
		data->ray.ray_face.right = 1;
		data->ray.ray_face.left = 0;
	}
	else
	{
		data->ray.ray_face.right = 0;
		data->ray.ray_face.left = 1;
	}
	data->ray.angle_ray = normalizeangle(data->ray.angle_ray);
}

double	normalizeangle(double angle)
{
	angle = fmod(angle, (2 * M_PI));
	if (angle < 0)
		angle = angle + (2 * M_PI);
	return (angle);
}

void	movement_key(t_data *data, t_index step)
{
	if (data->my_hook.key_s == 1)
	{
		if (ft_check_wall(data, -step.y, -step.x))
		{
			data->player.player_x = data->player.player_x - step.x;
			data->player.player_y = data->player.player_y - step.y;
		}
	}
	if (data->my_hook.key_w == 1)
	{
		if (ft_check_wall(data, step.y, step.x))
		{
			data->player.player_x = data->player.player_x + step.x;
			data->player.player_y = data->player.player_y + step.y;
		}
	}
	if (data->my_hook.key_d == 1)
	{
		if (ft_check_wall(data, step.x, -step.y))
		{
			data->player.player_x = data->player.player_x - step.y;
			data->player.player_y = data->player.player_y + step.x;
		}
	}
}

void	check_key(t_data *data)
{
	t_index	step;

	step.x = STEP * cos(data->player.alpha);
	step.y = STEP * sin(data->player.alpha);
	movement_key(data, step);
	if (data->my_hook.key_a == 1)
	{
		if (ft_check_wall(data, -step.x, step.y))
		{
			data->player.player_x = data->player.player_x + step.y;
			data->player.player_y = data->player.player_y - step.x;
		}
	}
	if (data->my_hook.key_east == 1)
	{
		data->player.alpha += ALPHA;
		data->player.alpha = normalizeangle(data->player.alpha);
	}
	if (data->my_hook.key_west == 1)
	{
		data->player.alpha -= ALPHA;
		data->player.alpha = normalizeangle(data->player.alpha);
	}
}
