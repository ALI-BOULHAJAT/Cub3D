/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handling_key_data.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboulhaj <aboulhaj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 10:42:34 by aboulhaj          #+#    #+#             */
/*   Updated: 2022/09/05 11:07:10 by aboulhaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

int	ft_key_press(int key, t_data *data)
{
	if (key == 13)
		data->my_hook.key_w = 1;
	if (key == 2)
		data->my_hook.key_d = 1;
	if (key == 1)
		data->my_hook.key_s = 1;
	if (key == 0)
		data->my_hook.key_a = 1;
	if (key == 124)
		data->my_hook.key_east = 1;
	if (key == 123)
		data->my_hook.key_west = 1;
	if (key == 53)
	{
		mlx_destroy_window(data->img->mlx, data->img->win);
		exit(0);
	}
	return (0);
}

int	ft_key_release(int key, t_data *data)
{
	if (key == 13)
		data->my_hook.key_w = 0;
	if (key == 2)
		data->my_hook.key_d = 0;
	if (key == 1)
		data->my_hook.key_s = 0;
	if (key == 0)
		data->my_hook.key_a = 0;
	if (key == 124)
		data->my_hook.key_east = 0;
	if (key == 123)
		data->my_hook.key_west = 0;
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

void	ft_hook(t_data *data)
{
	mlx_hook(data->img->win, 2, 0, ft_key_press, data);
	mlx_hook(data->img->win, 3, 0, ft_key_release, data);
	mlx_loop_hook(data->img->mlx, ft_movekey, data);
	mlx_hook(data->img->win, 17, 0, ft_close_x, data);
	mlx_hook(data->img->win, 4, 0, ft_zoom, data);
	mlx_loop(data->img->mlx);
}
