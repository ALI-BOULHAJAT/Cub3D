/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_window.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboulhaj <aboulhaj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 11:19:13 by aboulhaj          #+#    #+#             */
/*   Updated: 2022/09/11 17:44:22 by aboulhaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d_bonus.h"

int	ft_movekey(t_data *data)
{
	check_key(data);
	mlx_clear_window(data->img->mlx, data->img->win);
	mlx_destroy_image(data->img->mlx, data->img->img);
	drow_to_img(data);
	return (0);
}

void	drawing(t_data *data)
{
	(void)data;
	data->img->mlx = mlx_init();
	data->img->win = mlx_new_window(data->img->mlx, WEIGHT, HIEGHT, "Cub3D");
	drow_to_img(data);
	ft_hook(data);
}

void	ft_put_pixel(int x, int y, t_data *data, int color)
{
	char	*adr;

	if ((x > 0 && x < WEIGHT) && (y > 0 && y < HIEGHT))
	{
		adr = data->img->addr + (y * data->img->d_size) \
		+ (x * (data->img->bit_img / 8));
		*((unsigned int *)adr) = color;
	}
}
