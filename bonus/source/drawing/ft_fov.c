/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fov.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenbajj <mbenbajj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 09:52:43 by aboulhaj          #+#    #+#             */
/*   Updated: 2022/10/23 02:04:40 by mbenbajj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d_bonus.h"

void	draw_background(t_data *data, int f_color, int c_color)
{
	int	x;
	int	y;

	y = 0;
	while (y <= HEIGHT)
	{
		x = 0;
		while (x <= WIDTH)
		{
			if (y < (HEIGHT / 2))
				ft_put_pixel(x, y, data, f_color);
			else
				ft_put_pixel(x, y, data, c_color);
			x++;
		}
		y++;
	}
}

t_index	player_possition(t_data *data, char zoom, char mouve)
{
	t_index	index;

	index.x = data->player.init_y_player + data->player.player_x;
	index.y = data->player.init_x_player + data->player.player_y;
	if (zoom == 'Y')
	{
		index.x *= data->texture.zoom;
		index.y *= data->texture.zoom;
	}
	if (mouve == 'Y')
	{
		index.x += data->player.mouve.x;
		index.y += data->player.mouve.y;
	}
	return (index);
}

void	draw_3d(t_data *data)
{

	t_index		player;
	t_index		wall;
	t_index		door;
	int			index;
	t_distance	ray_distance;

	index = 0;
	player = player_possition(data, 'Y', 'Y');
	data->ray.angle_ray = data->player.alpha - (30 * (M_PI / 180));
	draw_background(data, color_converter(&data->texture.floor), \
	color_converter(&data->texture.ceilling));
	while (index < WIDTH)
	{
		data->lst_door = (t_door *)ft_calloc(1, sizeof(t_door));
		data->ray.door.found_h = 0;
		data->ray.door.found_v = 0;
		facing_ray(data);
		horizontal_intersection(data);
		vertical_intersection(data);
		ray_distance = get_distance(data, &wall, &door);
		wall.id = index;
		door.id = index;
		t_door	*head = NULL;
		
		draw_wall(data, ray_distance.wall, wall, 'W', head);
		
		//	*****

		head = data->lst_door;
		while (head->next)
		{
			if ((head->found_h || head->found_v) && (head->distance < ray_distance.wall))
			{
				if (head->found_h)
				{
					door.x = head->horizontal_touch.x;
					door.y = head->horizontal_touch.y;
					draw_wall(data,	head->distance, door, 'D', head);
				}
				else
				{
					// printf("-> %f  -> %f \n", head->vertical_touch.x, head->vertical_touch.y);
					door.x = head->vertical_touch.x;
					door.y = head->vertical_touch.y;
					draw_wall(data, head->distance, door, 'D', head);
				}
			}
			head = head->next;
		}
		//	*****
		
		// if ((data->ray.door.found_h || data->ray.door.found_v) && (ray_distance.door < ray_distance.wall))
		// 	draw_wall(data, ray_distance.door, door, 'D');
		data->ray.angle_ray += ((60 * (M_PI / 180)) / WIDTH);
		index++;
		
		// t_door *head = data->lst_door;
		
		// while (head->next)
		// {
		// 	// puts("Face : 	Side	X	Y\n");
		// 	printf("H : %d	-	x : %f	,	y : %f\nV : %d	-	x : %f	,	y : %f\n", \
		// 			head->found_h, head->horizontal_touch.x, head->horizontal_touch.y, \
		// 			head->found_v, head->vertical_touch.x, head->vertical_touch.y);
		// 	head = head->next;
		// }
	}
}

void	draw_line(t_data *data, t_index first, t_index last, int color)
{
	double	i;
	double	step;

	i = 0;
	if (fabs(ft_diff(first.x, last.x)) > fabs(ft_diff(first.y, last.y)))
		step = fabs(ft_diff(first.x, last.x));
	else
		step = fabs(ft_diff(first.y, last.y));
	while (i < step)
	{
		if (point_in_circle(data, first.x, first.y))
			ft_put_pixel(first.x, first.y, data, color);
		first.x += ft_diff(first.x, last.x) / step;
		first.y += ft_diff(first.y, last.y) / step;
		i += 0.1;
	}
}

double	best_wall_distance(t_data *data, t_index *ray, t_index player)
{
	double	h_distance;
	double	v_distance;
	double	wall;

	h_distance = 0;
	v_distance = 0;
	if (data->ray.found_h_wall)
		h_distance = distance_2_point(player, data->ray.horizontal_touch);
	if (data->ray.found_v_wall)
		v_distance = distance_2_point(player, data->ray.vertical_touch);
	if (h_distance > v_distance)
	{
		(*ray).x = data->ray.vertical_touch.x;
		(*ray).y = data->ray.vertical_touch.y;
		data->ray.horizontal_best = 0;
		wall = v_distance;
	}
	else
	{
		(*ray).x = data->ray.horizontal_touch.x;
		(*ray).y = data->ray.horizontal_touch.y;
		data->ray.horizontal_best = 1;
		wall = h_distance;
	}
	return (wall);
}

double	best_door_distance(t_data *data, t_index *door, t_index player)
{
	double	h_distance;
	double	v_distance;
	double	door_distance;

	h_distance = 0;
	v_distance = 0;
	if (data->ray.door.found_h)
	{
		h_distance = distance_2_point(player, data->ray.door.horizontal_touch);
		(*door).x = data->ray.door.horizontal_touch.x;
		(*door).y = data->ray.door.horizontal_touch.y;
		data->ray.door.horizontal_best = 1;
		door_distance = h_distance;
	}
	else
	{
		v_distance = distance_2_point(player, data->ray.door.vertical_touch);
		(*door).x = data->ray.door.vertical_touch.x;
		(*door).y = data->ray.door.vertical_touch.y;
		data->ray.door.horizontal_best = 0;
		door_distance = v_distance;
	}
	return (door_distance);
}

void	door_distance(t_data *data, t_index player)
{
	t_door	*head;
	
	head = data->lst_door;
	while (head->next)
	{
		if (head->found_h)
		{
			head->distance = distance_2_point(player, head->horizontal_touch);
			head->horizontal_best = 1;
		}
		else if (head->found_v)
		{
			head->distance = distance_2_point(player, head->vertical_touch);
			head->horizontal_best = 0;
		}
		head = head->next;
	}
}


t_distance	get_distance(t_data *data, t_index *ray, t_index *door)
{
	t_distance	distance;
	t_index		player;

	(void)door;
	player = player_possition(data, 'Y', 'N');
	distance.wall = best_wall_distance(data, ray, player);
	// distance.door = best_door_distance(data, door, player);
	door_distance(data, player);
	return (distance);
}
