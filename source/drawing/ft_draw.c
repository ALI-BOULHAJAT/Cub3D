/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboulhaj <aboulhaj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 10:18:25 by aboulhaj          #+#    #+#             */
/*   Updated: 2022/09/06 18:43:14 by aboulhaj         ###   ########.fr       */
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
	while ((double)x <= x1 - 1)
	{
		y_n = y;
		while (y_n <= y1 - 1)
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

	x += data->player.player_x;
	y += data->player.player_y;
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
			my_new_window(x, y_n, data, 0x00bfff);
			y_n++;
		}
		x++;
	}
}

void	while_draw(t_data *data, int *x)
{
	int	y;

	y = 0;
	while (data->map[*x][y])
	{
		if (data->map[*x][y] == '1')
			draw_rectangle(data, y, *x, 0x555555);
		else if (data->map[*x][y] == '0' || data->map[*x][y] == 'N' \
		|| data->map[*x][y] == '2' || data->map[*x][y] == '3' \
		|| data->map[*x][y] == 'E' || data->map[*x][y] == 'W' \
		|| data->map[*x][y] == 'S')
			draw_rectangle(data, y, *x, 0xffffff);
		if (data->map[*x][y] == 'N' || data->map[*x][y] == 'S' \
		|| data->map[*x][y] == 'E' || data->map[*x][y] == 'W')
		{
			data->player.face = data->map[*x][y];
			data->player.init_x_player = *x + 0.5;
			data->player.init_y_player = y + 0.5;
		}
		y++;
	}
	(*x)++;
}

void	draw(t_data *data)
{
	int	x;
	// double *tab;

	x = 0;
	while (data->map[x])
		while_draw(data, &x);
	draw_vu(data);
	first_x_intersection(data);
}
	// draw_circle(data);

void	drow_to_img(t_data *data)
{
	data->img->img = mlx_new_image(data->img->mlx, LENGHT, HIEGHT);
	data->img->addr = mlx_get_data_addr(data->img->img, &data->img->bit_img, \
	&data->img->d_size, &data->img->endian);
	draw(data);
	printf("%f\n", data->player.alpha);
	printf("x-> %f y->%f\n", data->player.init_y_player + data->player.player_x, data->player.init_x_player + data->player.player_y);
	printf("first x-> %f y-> %f\n", data->ray.first_x_intersection[0] / data->texture.zoom, data->ray.first_x_intersection[1] / data->texture.zoom);
	mlx_put_image_to_window(data->img->mlx, data->img->win, data->img->img, \
	0, 0);
}

//draw_player(data, (double)data->player.init_y_player,
//(double)data->player.init_x_player); 