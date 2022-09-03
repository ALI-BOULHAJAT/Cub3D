/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_key.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboulhaj <aboulhaj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 19:45:58 by aboulhaj          #+#    #+#             */
/*   Updated: 2022/09/03 19:47:16 by aboulhaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

int	ft_check_wall(t_data *data, double x_plus, double y_plus)
{
	double	x;
	double	y;

	if (x_plus < 0)
		x_plus += -0.1;
	if (y_plus < 0)
		y_plus += -0.1;
	x = data->player.init_x_player + data->player.player_y + x_plus;
	y = data->player.init_y_player + data->player.player_x + y_plus;
	if ((data->map[(int)x][(int)y]) == '1')
		return (0);
	return (1);
}

void	check_key(t_data *data, int key)
{
	if (key == 125)
	{
		if (ft_check_wall(data, 0.1, 0))
			data->player.player_y += 0.1;
	}
	if (key == 126)
	{
		if (ft_check_wall(data, -0.1, 0))
			data->player.player_y -= 0.1;
	}
	if (key == 123)
	{
		if (ft_check_wall(data, 0, -0.1))
			data->player.player_x -= 0.1;
	}
	if (key == 124)
	{
		if (ft_check_wall(data, 0, 0.1))
			data->player.player_x += 0.1;
	}
}
