/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_circle.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboulhaj <aboulhaj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 09:52:43 by aboulhaj          #+#    #+#             */
/*   Updated: 2022/09/07 20:25:59 by aboulhaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	draw_rad(t_data *data, int int_x, int int_y)
{
	double	x;
	double	y;

	y = data->player.init_x_player;
	x = data->player.init_y_player;
	x += data->player.player_x;
	y += data->player.player_y;
	x *= data->texture.zoom;
	y *= data->texture.zoom;
	my_new_window(x + int_x, y - int_y, data, 0xff0000);
	my_new_window(x - int_x, y - int_y, data, 0xff0000);
	my_new_window(x + int_x, y + int_y, data, 0xff0000);
	my_new_window(x - int_x, y + int_y, data, 0xff0000);
	my_new_window(x + int_y, y - int_x, data, 0xff0000);
	my_new_window(x - int_y, y - int_x, data, 0xff0000);
	my_new_window(x + int_y, y + int_x, data, 0xff0000);
	my_new_window(x - int_y, y + int_x, data, 0xff0000);
}

void	draw_circle(t_data *data)
{
	double	r;
	double	p;
	int		int_x;
	int		int_y;

	r = RAY;
	p = 1 - r;
	int_x = 0;
	int_y = r;
	while (int_x <= int_y)
	{
		if (p < 0)
			p = p + (4 * int_x) + 6;
		else
		{
			p = p + (4 * (int_x - int_y)) + 10;
			int_y -= 1;
		}
		int_x++;
		draw_rad(data, int_x, int_y);
	}
}

double	ft_diff(double x, double y)
{
	return (y - x);
}

// void	draw_vu(t_data *data)
// {
// 	double	tab_x_y[2];
// 	double	x1;
// 	double	y1;
// 	double	i;
// 	double	step;

// 	i = 0;
// 	tab_x_y[0] = data->player.init_y_player + data->player.player_x;
// 	tab_x_y[1] = data->player.init_x_player + data->player.player_y;
// 	tab_x_y[0] *= data->texture.zoom;
// 	tab_x_y[1] *= data->texture.zoom;
// 	x1 = tab_x_y[0] + (cos(data->player.alpha) * data->texture.zoom);
// 	y1 = tab_x_y[1] + (sin(data->player.alpha) * data->texture.zoom);
// 	if (fabs(ft_diff(tab_x_y[0], x1)) > fabs(ft_diff(tab_x_y[1], y1)))
// 		step = fabs(ft_diff(tab_x_y[0], x1));
// 	else
// 		step = fabs(ft_diff(tab_x_y[1], y1));
// 	while (i <= step)
// 	{
// 		if (data->map[abs((int)tab_x_y[1]/data->texture.zoom)][abs((int)tab_x_y[0]/data->texture.zoom)] == '1')
// 			break ;
// 		my_new_window(tab_x_y[0], tab_x_y[1], data, 0xff0000);
// 		tab_x_y[0] += ft_diff(tab_x_y[0], x1) / step;
// 		tab_x_y[1] += ft_diff(tab_x_y[1], y1) / step;
// 		i += 0.01;
// 	}
// }



int	ray_check_wall(t_data *data, double cpy_x_y[2], double tab_x1_y1[2], double step)
{
	double	inc_step_x;
	double	inc_step_y;
	double	x;
	double	y;

	x = fabs(cpy_x_y[1]/data->texture.zoom);
	y = fabs(cpy_x_y[0]/data->texture.zoom);
	inc_step_x = (ft_diff(cpy_x_y[0], tab_x1_y1[0]) / step) / data->texture.zoom;
	inc_step_y = (ft_diff(cpy_x_y[1], tab_x1_y1[1]) / step) / data->texture.zoom;
	if(data->map[(int)x][(int)y] == '2' && data->map[(int)(x + inc_step_x)][(int)(y + inc_step_y)] == '3')
		return (1);
	else if(data->map[(int)x][(int)y] == '3' && data->map[(int)(x + inc_step_x)][(int)(y + inc_step_y)] == '2')
		return (1);
	else if (char_in_str(WALL_SPAC, data->map[(int)x][(int)y]))
		return (1);
	else
		return (0);
}

void	draw_FOV(t_data *data)
{
	t_index	player;
	t_index	ray;
	// double	last_angle;
	int	index = LENGHT;

	player.x = (data->player.init_y_player + data->player.player_x) * data->texture.zoom;
	player.y = (data->player.init_x_player + data->player.player_y) * data->texture.zoom;
	data->ray.angle_ray = data->player.alpha - (30 * (M_PI / 180));
	while(index)
	{
		facing_ray(data);
		data->ray.angle_ray = normalizeangle(data->ray.angle_ray);
		horizontal_intersection(data);
		vertical_intersection(data);
		get_distance(data);
		if (data->ray.h_is_best == 1)
		{
			ray.x = data->ray.horizontal_touch.x;
			ray.y = data->ray.horizontal_touch.y;
		}
		else
		{
			ray.x = data->ray.vertical_touch.x;
			ray.y = data->ray.vertical_touch.y;
		}
		draw_line(data, player.x, ray.x, player.y, ray.y, 0x977950);
		data->ray.angle_ray += (60 * (M_PI / 180))/LENGHT;
		index--;
	}
}

void	draw_line(t_data *data, double int_x, double last_x, double int_y, double last_y, int color)
{
	double	i;
	double	step;

	i = 0;
	if (fabs(ft_diff(int_x, last_x)) > fabs(ft_diff(int_y, last_y)))
		step = fabs(ft_diff(int_x, last_x));
	else
		step = fabs(ft_diff(int_y, last_y));
	while (i <= step)
	{
		if (data->map[abs((int)int_y/data->texture.zoom)][abs((int)int_x/data->texture.zoom)] == '1')
			break ;
		my_new_window(int_x, int_y, data, color);
		int_x += ft_diff(int_x, last_x) / step;
		int_y += ft_diff(int_y, last_y) / step;
		i += 0.1;
	}
}
