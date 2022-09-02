/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_window.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboulhaj <aboulhaj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 11:19:13 by aboulhaj          #+#    #+#             */
/*   Updated: 2022/09/02 19:05:05 by aboulhaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

int	ft_movekey(int key, t_data *data)
{
	if (key == 125)
		data->texture.player_y += 0.2;
	if (key == 126)
		data->texture.player_y -= 0.2;
	if (key == 123)
		data->texture.player_x -= 0.2;
	if (key == 124)
		data->texture.player_x += 0.2;
	if (key == 53)
	{
		mlx_destroy_window(data->img->mlx, data->img->win);
		exit(0);
	}
	mlx_clear_window(data->img->mlx, data->img->win);
	mlx_destroy_image(data->img->mlx, data->img->img);
	drow_to_img(data);
	return (0);
}

int	ft_close_x(t_data *data)
{
	mlx_destroy_window(data->img->mlx, data->img->win);
	exit(0);
	return (0);
}

int	ft_zoom(int mouse, int x, int y, t_data *data)
{
	x = 0;
	y = 0;
	if (mouse == 5)
		data->texture.zoom += 1;
	if (mouse == 4)
		data->texture.zoom -= 1;
	mlx_clear_window(data->img->mlx, data->img->win);
	mlx_destroy_image(data->img->mlx, data->img->img);
	drow_to_img(data);
	return (0);
}

void	drawing(t_data *data)
{
	(void)data;
	data->img->mlx = mlx_init();
	data->img->win = mlx_new_window(data->img->mlx, LENGHT, HIEGHT, "Cub3D");
	drow_to_img(data);
	mlx_hook(data->img->win, 2, 0, ft_movekey, data);
	mlx_hook(data->img->win, 17, 0, ft_close_x, data);
	mlx_hook(data->img->win, 4, 0, ft_zoom, data);
	mlx_loop(data->img->mlx);
}

void	my_new_window(int x, int y, t_data *data, int color)
{
	char	*adr;

	if ((x >= 0 && x < LENGHT) && (y >= 0 && y < HIEGHT))
	{
		adr = data->img->addr + (y * data->img->d_size) \
		+ (x * (data->img->bit_img / 8));
		*((unsigned int *)adr) = color;
	}
}
