/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_key.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboulhaj <aboulhaj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 19:45:58 by aboulhaj          #+#    #+#             */
/*   Updated: 2022/09/06 19:24:25 by aboulhaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

int	ft_check_wall(t_data *data, double x_plus, double y_plus)
{
	double	x;
	double	y;
	double	pre_x;
	double	pre_y;

	x = data->player.init_x_player + data->player.player_y + x_plus;
	y = data->player.init_y_player + data->player.player_x + y_plus;
	pre_x = x - x_plus;
	pre_y = y - y_plus;
	if ((data->map[(int)pre_x][(int)pre_y]) == '2' \
	&& (data->map[(int)x][(int)y]) == '3')
		return (0);
	if ((data->map[(int)pre_x][(int)pre_y]) == '3' \
	&& (data->map[(int)x][(int)y]) == '2')
		return (0);
	if ((data->map[(int)x][(int)y]) == '1' \
	|| (data->map[(int)x][(int)y]) == ' ' \
	|| (data->map[(int)x][(int)y]) == '\n' \
	|| (data->map[(int)x][(int)y]) == '\0')
		return (0);
	return (1);
}

void	facing_ray(t_data *data)
{
	if (data->player.alpha > 0 && data->player.alpha < M_PI)
	{
		data->ray.ray_face_down = 1;
		data->ray.ray_face_up = 0;
	}
	else
	{
		data->ray.ray_face_down = 0;
		data->ray.ray_face_up = 1;
	}
	if(data->player.alpha < (0.5 * M_PI) || data->player.alpha > (1.5 * M_PI))
	{
		data->ray.ray_face_right = 1;
		data->ray.ray_face_left = 0;
	}
	else
	{
		data->ray.ray_face_right = 0;
		data->ray.ray_face_left = 1;
	}
}

void	movement_key(t_data *data)
{
	double	step_x;
	double	step_y;

	step_x = STEP * cos(data->player.alpha);
	step_y = STEP * sin(data->player.alpha);
	if (data->my_hook.key_s == 1)
	{
		if (ft_check_wall(data, -step_y, -step_x))
		{
			data->player.player_x = data->player.player_x - step_x;
			data->player.player_y = data->player.player_y - step_y;
		}
	}
	if (data->my_hook.key_w == 1)
	{
		if (ft_check_wall(data, step_y, step_x))
		{
			data->player.player_x = data->player.player_x + step_x;
			data->player.player_y = data->player.player_y + step_y;
		}
	}
	if (data->my_hook.key_east == 1)
	{
		data->player.alpha += ALPHA;
		data->player.alpha = fmod(data->player.alpha, (2 * M_PI));
		if (data->player.alpha < 0)
			data->player.alpha += (2 * M_PI);
		facing_ray(data);
	}
	if (data->my_hook.key_west == 1)
	{
		data->player.alpha -= ALPHA;
		data->player.alpha = fmod(data->player.alpha, (2 * M_PI));
		if (data->player.alpha < 0)
			data->player.alpha += (2 * M_PI);
		facing_ray(data);
	}
}

void	check_key(t_data *data)
{
	double	step_x;
	double	step_y;

	step_x = STEP * cos(data->player.alpha);
	step_y = STEP * sin(data->player.alpha);
	movement_key(data);
	if (data->my_hook.key_a == 1)
	{
		if (ft_check_wall(data, -step_x, step_y))
		{
			data->player.player_x = data->player.player_x + step_y;
			data->player.player_y = data->player.player_y - step_x;
		}
	}
	if (data->my_hook.key_d == 1)
	{
		if (ft_check_wall(data, step_x, -step_y))
		{
			data->player.player_x = data->player.player_x - step_y;
			data->player.player_y = data->player.player_y + step_x;
		}
	}
}