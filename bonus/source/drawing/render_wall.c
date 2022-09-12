/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_wall.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboulhaj <aboulhaj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/11 11:02:05 by aboulhaj          #+#    #+#             */
/*   Updated: 2022/09/12 17:55:29 by aboulhaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d_bonus.h"

void	draw_rectangle_wall(t_data *data, double wall_height, int ray_id)
{
	t_index	last;
	t_index	first;

	first.x = (HIEGHT / 2) - (wall_height / 2);
	if (first.x < 0)
		first.x = 0;
	last.x = first.x + wall_height;
	if (last.x > HIEGHT)
		last.x = HIEGHT;
	while (first.x <= last.x)
	{
		ft_put_pixel(ray_id, first.x, data, 0x6E7681);
		first.x++;
	}
}

void	draw_wall(t_data *data, double ray_distance, int ray_id)
{
	double	wall_hight;
	double	distance_pr_pl;

	distance_pr_pl = (WEIGHT / 2) / tan(30 * (M_PI / 180));
	wall_hight = (data->texture.zoom / (ray_distance)) * distance_pr_pl;
	draw_rectangle_wall(data, wall_hight, ray_id);
}

int	color_converter(t_color *color)
{
	return ((color->r << 16) | (color->g << 8) | color->b);
}
