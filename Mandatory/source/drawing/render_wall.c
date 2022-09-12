/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_wall.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboulhaj <aboulhaj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/11 11:02:05 by aboulhaj          #+#    #+#             */
/*   Updated: 2022/09/12 14:17:02 by aboulhaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	draw_rectangle_wall(t_data *data, double wall_height, int ray_id)
{
	t_index	last;
	t_index	first;

	first.x = (HIEGHT / 2) - (wall_height / 2);
	first.y = ray_id * 1;
	last.x = first.x + wall_height;
	last.y = first.y + 1;
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

void	drawing(t_data *data)
{
	(void)data;
	data->img->mlx = mlx_init();
	data->img->win = mlx_new_window(data->img->mlx, WEIGHT, HIEGHT, "Cub3D");
	drow_to_img(data);
	ft_hook(data);
}
