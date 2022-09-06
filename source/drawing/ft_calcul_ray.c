/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calcul_ray.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboulhaj <aboulhaj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 15:04:42 by aboulhaj          #+#    #+#             */
/*   Updated: 2022/09/06 19:35:45 by aboulhaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void   first_x_intersection(t_data *data)
{
    // double  point[2];
    double  player[2];
    double  
    
    player[0] = data->player.init_y_player + data->player.player_x;
    player[1] = data->player.init_x_player + data->player.player_y;
    player[0] *= data->texture.zoom;
    player[1] *= data->texture.zoom;
    data->ray.first_x_intersection[1] = data->texture.zoom * (floor(player[1] / data->texture.zoom));
    if (data->ray.ray_face_down)
        data->ray.first_x_intersection[1] += data->texture.zoom;
    data->ray.first_x_intersection[0] = player[0] + ((player[1] - data->ray.first_x_intersection[1]) / tan(data->player.alpha));
    data->ray.x_intersection_step[1] = data->texture.zoom;
    if (data->ray.ray_face_up)
        data->ray.x_intersection_step[1] *= -1;
    data->ray.x_intersection_step[0] = data->texture.zoom / tan(data->player.alpha);
    if (data->ray.ray_face_left && data->ray.x_intersection_step > 0)
        data->ray.x_intersection_step[0] *= -1;
    if (data->ray.ray_face_right && data->ray.x_intersection_step < 0)
        data->ray.x_intersection_step[0] *= -1;
     
}

// void    first_y_intersection(t_data *data)
// {
//     double  player[2];

//     player[0] = 
// }

