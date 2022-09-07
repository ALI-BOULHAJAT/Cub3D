/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calcul_ray.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboulhaj <aboulhaj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 15:04:42 by aboulhaj          #+#    #+#             */
/*   Updated: 2022/09/07 19:31:02 by aboulhaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void   horizontal_intersection(t_data *data)
{
    t_index player;
    t_index horizontal_intersection;
    t_index step;
    double  test;
    
    data->ray.found_h_wall = 0;
    player.x = (data->player.init_y_player + data->player.player_x) * data->texture.zoom;
    player.y = (data->player.init_x_player + data->player.player_y) * data->texture.zoom;

    /////// find y cordinate of horizantal
    horizontal_intersection.y = data->texture.zoom * ((int)(player.y / data->texture.zoom));
    if (data->ray.ray_face.down)
        horizontal_intersection.y += data->texture.zoom;
    /////// find x cordinate of horizantal
    horizontal_intersection.x = player.x + ((horizontal_intersection.y - player.y) / tan(data->ray.angle_ray));
    step.y = data->texture.zoom;
    if (data->ray.ray_face.up)
        step.y *= -1;
    step.x = data->texture.zoom / tan(data->ray.angle_ray);
    if (data->ray.ray_face.left && step.x > 0)
        step.x *= -1;
    if (data->ray.ray_face.right && step.x < 0)
        step.x *= -1;
    while(horizontal_intersection.y > 0 && (horizontal_intersection.y / data->texture.zoom) <= 15 && horizontal_intersection.x > 0 && (horizontal_intersection.x / data->texture.zoom) <= 35)
    {
        test = horizontal_intersection.y;
        if (data->ray.ray_face.up)
            test--;
        if (data->map[(int)(test / data->texture.zoom)][(int)(horizontal_intersection.x / data->texture.zoom)] == '1')
        {
            data->ray.found_h_wall = 1;
            data->ray.horizontal_touch.x = horizontal_intersection.x;
            data->ray.horizontal_touch.y = horizontal_intersection.y;
            break ;
        }
        else
        {
            horizontal_intersection.x += step.x;
            horizontal_intersection.y += step.y;
        }
    }
}

void    vertical_intersection(t_data *data)
{
    t_index player;
    t_index step;
    t_index vertical_intersection;
    double  test;

    data->ray.found_v_wall = 0;
    player.x = (data->player.init_y_player + data->player.player_x) * data->texture.zoom;
    player.y = (data->player.init_x_player + data->player.player_y) * data->texture.zoom;
    vertical_intersection.x = data->texture.zoom * ((int)(player.x / data->texture.zoom));
    if (data->ray.ray_face.right)
        vertical_intersection.x += data->texture.zoom;
    vertical_intersection.y = player.y + ((vertical_intersection.x - player.x) * tan(data->ray.angle_ray));
    step.x = data->texture.zoom;
    if (data->ray.ray_face.left)
        step.x *= -1;
    step.y = data->texture.zoom * tan(data->ray.angle_ray);
    if (data->ray.ray_face.up && step.y > 0)
        step.y *= -1;
    if (data->ray.ray_face.down && step.y < 0)
        step.y *= -1;
    while(vertical_intersection.y > 0 && (vertical_intersection.y / data->texture.zoom) <= 15 \
    && vertical_intersection.x > 0 && (vertical_intersection.x / data->texture.zoom) <= 35)
    {
        test = vertical_intersection.x;
        if (data->ray.ray_face.left)
            test--;
        if (data->map[(int)(vertical_intersection.y / data->texture.zoom)][(int)(test / data->texture.zoom)] == '1')
        {
            data->ray.found_v_wall = 1;
            data->ray.vertical_touch.x = vertical_intersection.x;
            data->ray.vertical_touch.y = vertical_intersection.y;
            break ;
        }
        else
        {
            vertical_intersection.x += step.x;
            vertical_intersection.y += step.y;
        }
    }
}

double  distance_2_point(double x, double x1, double y, double y1)
{
    return (sqrt(((x1 - x) * (x1 - x)) + ((y1 - y) * (y1 - y))));
}

void    get_distance(t_data *data)
{
    double  h_distance = 0;
    double  v_distance = 0;
    t_index player;

    player.x = (data->player.init_y_player + data->player.player_x) * data->texture.zoom;
    player.y = (data->player.init_x_player + data->player.player_y) * data->texture.zoom;
    if (data->ray.found_h_wall)
        h_distance = distance_2_point(player.x, data->ray.horizontal_touch.x, player.y, data->ray.horizontal_touch.y);
    if (data->ray.found_v_wall)
        v_distance = distance_2_point(player.x, data->ray.vertical_touch.x, player.y, data->ray.vertical_touch.y);
    if (h_distance < v_distance)
    {
        data->ray.h_is_best = 1;
        data->ray.v_is_best = 0;
    }
    else
    {
        data->ray.v_is_best = 1;
        data->ray.h_is_best = 0;
    }
}