/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_wall.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboulhaj <aboulhaj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/11 11:02:05 by aboulhaj          #+#    #+#             */
/*   Updated: 2022/09/11 17:44:29 by aboulhaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../../include/cub3d_bonus.h"

void	draw_rectangle_wall(t_data *data, double wall_height, int ray_id)
{
	t_index	last;
	// int			tmp;
    t_index first;

    first.x = (HIEGHT / 2) - (wall_height / 2);
    first.y = ray_id * 1;
    last.x = first.x + wall_height;
    last.y = first.y + 1;
    // first.x *= data->texture.zoom;
	// first.y *= data->texture.zoom;
	// first.x += data->player.mouve.y;
	// first.y += data->player.mouve.x;
	// last.x = first.x + data->texture.zoom;
	// last.y = first.y + data->texture.zoom;
	// while ((double)first.y <= last.y - 1)
	// {
	// 	tmp = first.x;
        // printf("%f\n", wall_height);
		while (first.x <= last.x)
		{
			// printf("h\n");
			ft_put_pixel(ray_id, first.x, data, 0xCFDEFF);
			first.x++;
		}
		// first.y++;
	// }
}

void draw_wall(t_data *data, double ray_distance, int ray_id)
{
    double  wall_hight;
    double  distance_Pr_Pl;
    (void)ray_id;

    distance_Pr_Pl = (WEIGHT / 2) / tan(30 * (M_PI / 180));
    wall_hight = (data->texture.zoom / ray_distance) * distance_Pr_Pl;
    // printf("%f\n", distance_Pr_Pl);
    draw_rectangle_wall(data, wall_hight, ray_id);
    
}