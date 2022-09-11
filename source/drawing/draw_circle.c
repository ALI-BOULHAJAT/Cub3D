/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_circle.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboulhaj <aboulhaj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 11:28:52 by aboulhaj          #+#    #+#             */
/*   Updated: 2022/09/11 10:56:12 by aboulhaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	draw_rad(t_data *data, int int_x, int int_y)
{
	double	x;
	double	y;

	x = RAY + 5;
	y = RAY + 5;
	ft_put_pixel(x + int_x, y - int_y, data, 0xff0000);
	ft_put_pixel(x - int_x, y - int_y, data, 0xff0000);
	ft_put_pixel(x + int_x, y + int_y, data, 0xff0000);
	ft_put_pixel(x - int_x, y + int_y, data, 0xff0000);
	ft_put_pixel(x + int_y, y - int_x, data, 0xff0000);
	ft_put_pixel(x - int_y, y - int_x, data, 0xff0000);
	ft_put_pixel(x + int_y, y + int_x, data, 0xff0000);
	ft_put_pixel(x - int_y, y + int_x, data, 0xff0000);
}

void	draw_circle(t_data *data)
{
	double	r;
	double	p;
	int		int_x;
	int		int_y;

	r = RAY;
	p = 1 - r;
	int_x = 0;
	int_y = r;
	while (int_x <= int_y)
	{
		if (p < 0)
			p = p + (4 * int_x) + 6;
		else
		{
			p = p + (4 * (int_x - int_y)) + 10;
			int_y -= 1;
		}
		int_x++;
		draw_rad(data, int_x, int_y);
	}
}

int	point_in_circle(t_data *data, double y, double x)
{
	double	distance;
	t_index	player;
	t_index	point;

	point.x = x;
	point.y = y;
	player = player_possition(data, 'Y', 'Y');
	distance = distance_2_point(player, point);
	if (distance <= RAY)
		return (1);
	return (0);
}

void	get_player_possition(t_data *data)
{
	t_index_int	index;
	t_index		player;

	index.x = 0;
	while (data->map[index.x])
	{
		index.y = 0;
		while (data->map[index.x][index.y])
		{
			if (char_in_str(PLAYER, data->map[index.x][index.y]))
			{
				data->player.face = data->map[index.x][index.y];
				data->player.init_x_player = index.x + 0.5;
				data->player.init_y_player = index.y + 0.5;
				break ;
			}
			index.y++;
		}
		index.x++;
	}
	player = player_possition(data, 'Y', 'N');
	data->player.mouve.x = (RAY + 5) - player.x;
	data->player.mouve.y = (RAY + 5) - player.y;
}

int	ft_close_x(t_data *data)
{
	mlx_destroy_window(data->img->mlx, data->img->win);
	exit(0);
	return (0);
}
