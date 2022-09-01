/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_window.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboulhaj <aboulhaj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 11:19:13 by aboulhaj          #+#    #+#             */
/*   Updated: 2022/09/01 17:45:34 by aboulhaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	ft_ckeck_key(int key, t_data **data)
{
	if (key == 53)
	{
		mlx_destroy_window((*data)->img->mlx, (*data)->img->win);
		exit(0);
	}
}

int	ft_movekey(int key, t_data **data)
{
	ft_ckeck_key(key, data);
	return (0);
}

int	ft_close_x(t_data *data)
{
	mlx_destroy_window(data->img->mlx, data->img->win);
	exit(0);
	return (0);
}

void	drawing(t_data *data)
{
	(void)data;
	data->img->mlx = mlx_init();
	data->img->win = mlx_new_window(data->img->mlx, LENGHT, HIEGHT, "Cub3D");
	mlx_hook(data->img->win, 17, 0, ft_close_x, data);
	mlx_hook(data->img->win, 2, 0, ft_movekey, &data);
	mlx_loop(data->img->mlx);
}
