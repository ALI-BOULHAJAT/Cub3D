/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboulhaj <aboulhaj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 10:18:25 by aboulhaj          #+#    #+#             */
/*   Updated: 2022/09/11 17:44:12 by aboulhaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d_bonus.h"

double	distance_2_point(t_index first, t_index last)
{
	return (sqrt (pow((last.x - first.x), 2) + pow((last.y - first.y), 2)));
}

void	draw_rectangle(t_data *data, t_index_int first, int color)
{
	t_index_int	last;
	int			tmp;

	first.x *= data->texture.zoom;
	first.y *= data->texture.zoom;
	first.x += data->player.mouve.y;
	first.y += data->player.mouve.x;
	last.x = first.x + data->texture.zoom;
	last.y = first.y + data->texture.zoom;
	while ((double)first.y <= last.y - 1)
	{
		tmp = first.x;
		while (tmp <= last.x - 1)
		{
			if (point_in_circle(data, first.y, tmp))
				ft_put_pixel(first.y, tmp, data, color);
			tmp++;
		}
		first.y++;
	}
}

void	draw_map_2d(t_data *data)
{
	t_index_int	index;

	index.x = 0;
	while (data->map[index.x])
	{
		index.y = 0;
		while (data->map[index.x][index.y])
		{
			if (data->map[index.x][index.y] == '1')
				draw_rectangle(data, index, 0x555555);
			else if (char_in_str(PLAY_EMPT, data->map[index.x][index.y]))
				draw_rectangle(data, index, 0xffffff);
			index.y++;
		}
		index.x++;
	}
}

void	draw(t_data *data)
{
	if (data->view.view_2d)
	{
		get_player_possition(data);
		draw_map_2d(data);
		draw_fov(data);
		draw_circle(data);
	}
}
	// draw_circle(data);

void	drow_to_img(t_data *data)
{
	t_img	*img;

	img = data->img;
	img->img = mlx_new_image(img->mlx, WEIGHT, HIEGHT);
	img->addr = mlx_get_data_addr(img->img, &img->bit_img, \
	&img->d_size, &img->endian);
	draw(data);
	mlx_put_image_to_window(img->mlx, img->win, img->img, 0, 0);
}

//draw_player(data, (double)data->player.init_y_player,
//(double)data->player.init_x_player); 