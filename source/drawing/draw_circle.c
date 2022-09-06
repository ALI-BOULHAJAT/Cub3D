/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_circle.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboulhaj <aboulhaj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 09:52:43 by aboulhaj          #+#    #+#             */
/*   Updated: 2022/09/06 15:06:30 by aboulhaj         ###   ########.fr       */
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

void	draw_vu(t_data *data)
{
	double	tab_x_y[2];
	double	tab_x1_y1[2];
	// double	x1;
	// double	y1;
	double	i;
	// int	y = 0;
	double	step;
	double	rayangle;
	double	last_angle;
	double	cpy_x_y[2];
	// int		check = 320;

	tab_x_y[0] = data->player.init_y_player + data->player.player_x;
	tab_x_y[1] = data->player.init_x_player + data->player.player_y;
	tab_x_y[0] *= data->texture.zoom;
	tab_x_y[1] *= data->texture.zoom;
	rayangle = data->player.alpha - (30 * M_PI / 180);
	last_angle = data->player.alpha + (30 * M_PI / 180);
	while(rayangle <= last_angle)
	{
		cpy_x_y[0] = tab_x_y[0];
		cpy_x_y[1] = tab_x_y[1];
		tab_x1_y1[0] = cpy_x_y[0] + (cos(rayangle) * data->texture.zoom);
		tab_x1_y1[1] = cpy_x_y[1] + (sin(rayangle) * data->texture.zoom);
		if (fabs(ft_diff(cpy_x_y[0], tab_x1_y1[0])) > fabs(ft_diff(cpy_x_y[1], tab_x1_y1[1])))
			step = fabs(ft_diff(cpy_x_y[0], tab_x1_y1[0]));
		else
			step = fabs(ft_diff(cpy_x_y[1], tab_x1_y1[1]));
		i = 0;
		while (i <= step)
		{
			if (ray_check_wall(data, cpy_x_y, tab_x1_y1, step))
				break ;
			my_new_window(cpy_x_y[0], cpy_x_y[1], data, 0x977950);
			cpy_x_y[0] += ft_diff(cpy_x_y[0], tab_x1_y1[0]) / step;
			cpy_x_y[1] += ft_diff(cpy_x_y[1], tab_x1_y1[1]) / step;
			i += 0.01;
		}
		rayangle += (60 * M_PI / 180)/320;
		// y++;
		// printf("here\n");
		// check--;
	}
	// printf("%d\n", y);
}
