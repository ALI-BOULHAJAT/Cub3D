/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboulhaj <aboulhaj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 10:18:25 by aboulhaj          #+#    #+#             */
/*   Updated: 2022/09/02 18:43:32 by aboulhaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	draw_rectangle(t_data *data, int x, int y, int color)
{
	int	x1;
	int	y1;
	int	y_n;

	x *= data->texture.zoom;
	y *= data->texture.zoom;
	x1 = x + data->texture.zoom;
	y1 = y + data->texture.zoom;
	while (x <= x1)
	{
		y_n = y;
		while (y_n <= y1)
		{
			my_new_window(x, y_n, data, color);
			y_n++;
		}
		x++;
	}
}

void	draw_player(t_data *data, double x, double y)
{
	double	x1;
	double	y1;
	double	y_n;

	x += data->texture.player_x;
	y += data->texture.player_y;
	x *= data->texture.zoom;
	y *= data->texture.zoom;
	x += (data->texture.zoom / 2) - 2;
	y += (data->texture.zoom / 2) - 2;
	x1 = (x + 4);
	y1 = (y + 4);
	while (x <= x1)
	{
		y_n = y;
		while (y_n <= y1)
		{
			my_new_window((int)x, (int)y_n, data, 0x00bfff);
			y_n++;
		}
		x++;
	}
}

void	while_draw(t_data *data, int *x)
{
	int	y;
	int	color;

	y = 0;
	while (data->map[*x][y])
	{
		if (data->map[*x][y] == '1')
		{
			color = 0x555555;
		}
		else if (data->map[*x][y] == '0' || data->map[*x][y] == 'N')
		{
			color = 0xffffff;
		}
		else
			color = 0;
		draw_rectangle(data, y, *x, color);
		if (data->map[*x][y] == 'N')
		{
			data->texture.init_x_player = *x;
			data->texture.init_y_player = y;
		}
		y++;
	}
	(*x)++;
}

void	draw(t_data *data)
{
	int	x;

	x = 0;
	while (data->map[x])
		while_draw(data, &x);
	draw_player (data, (double)data->texture.init_y_player, \
	(double)data->texture.init_x_player);
}

void	drow_to_img(t_data *data)
{
	data->img->img = mlx_new_image(data->img->mlx, LENGHT, HIEGHT);
	data->img->addr = mlx_get_data_addr(data->img->img, &data->img->bit_img, \
	&data->img->d_size, &data->img->endian);
	draw(data);
	mlx_put_image_to_window(data->img->mlx, data->img->win, data->img->img, \
	0, 0);
}
