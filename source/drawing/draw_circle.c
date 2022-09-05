/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_circle.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboulhaj <aboulhaj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 09:52:43 by aboulhaj          #+#    #+#             */
/*   Updated: 2022/09/05 10:34:31 by aboulhaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	draw_rad(t_data *data, int int_x, int int_y)
{
	double	x;
	double	y;

	y = data->player.init_x_player;
	x = data->player.init_y_player;
	x += data->player.player_x;
	y += data->player.player_y;
	x *= data->texture.zoom;
	y *= data->texture.zoom;
	my_new_window(x + int_x, y - int_y, data, 0xff0000);
	my_new_window(x - int_x, y - int_y, data, 0xff0000);
	my_new_window(x + int_x, y + int_y, data, 0xff0000);
	my_new_window(x - int_x, y + int_y, data, 0xff0000);
	my_new_window(x + int_y, y - int_x, data, 0xff0000);
	my_new_window(x - int_y, y - int_x, data, 0xff0000);
	my_new_window(x + int_y, y + int_x, data, 0xff0000);
	my_new_window(x - int_y, y + int_x, data, 0xff0000);
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

void	draw_vu(t_data *data)
{
	double	x;
	double	y;
	double	x1;
	double	y1;
	int		i;

	x = ((data->player.init_y_player * data->texture.zoom \
	+ data->player.player_x * data->texture.zoom));
	y = data->player.init_x_player * data->texture.zoom \
	+ data->player.player_y * data->texture.zoom;
	x1 = x + (data->texture.zoom / 2);
	y1 = y + (data->texture.zoom / 2);
	i = 5;
	while (i)
	{
		my_new_window(x, y, data, 0);
		x = x + ((data->texture.zoom / 2) * cos(data->player.alpha));
		y = y + ((data->texture.zoom / 2) * sin(data->player.alpha));
		i--;
	}
}
