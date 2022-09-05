/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_var.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboulhaj <aboulhaj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 10:51:32 by aboulhaj          #+#    #+#             */
/*   Updated: 2022/09/05 10:57:55 by aboulhaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	init_color(t_color *color)
{
	(*color).t = -1;
	(*color).r = -1;
	(*color).g = -1;
	(*color).b = -1;
}

void	int_key(t_data *data)
{
	data->my_hook.key_a = 0;
	data->my_hook.key_w = 0;
	data->my_hook.key_s = 0;
	data->my_hook.key_d = 0;
	data->my_hook.key_east = 0;
	data->my_hook.key_west = 0;
}

void	init_struct(t_data **data)
{
	(*data)->img = (t_img *)malloc(sizeof(t_img));
	(*data)->error = NULL;
	(*data)->texture.east = NULL;
	(*data)->texture.north = NULL;
	(*data)->texture.south = NULL;
	(*data)->texture.west = NULL;
	(*data)->texture.check = 0;
	(*data)->texture.read_in_map = 0;
	(*data)->player.n_player = 0;
	(*data)->texture.is_empty_line = 0;
	(*data)->img->d_size = 0;
	(*data)->img->endian = 0;
	(*data)->texture.zoom = 25;
	(*data)->player.player_x = 0;
	(*data)->player.player_y = 0;
	(*data)->player.to_east = 1;
	(*data)->player.to_north = 1;
	(*data)->player.to_south = 1;
	(*data)->player.to_west = 1;
	init_color(&((*data)->texture.floor));
	init_color(&((*data)->texture.ceilling));
	(*data)->player.alpha = 1;
	int_key(*data);
}
// (*data)->my_hook.key_south = 0;
// (*data)->my_hook.key_north = 0;