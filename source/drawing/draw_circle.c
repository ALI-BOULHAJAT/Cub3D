/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_circle.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboulhaj <aboulhaj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 11:28:52 by aboulhaj          #+#    #+#             */
/*   Updated: 2022/09/10 19:52:46 by aboulhaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	draw_rad(t_data *data, int int_x, int int_y)
{
	double	x;
	double	y;

	x = RAY + 5;
	y = RAY + 5;
	ft_put_pixel(x + int_x, y - int_y, data, 0xff0000);
	ft_put_pixel(x - int_x, y - int_y, data, 0xff0000);
	ft_put_pixel(x + int_x, y + int_y, data, 0xff0000);
	ft_put_pixel(x - int_x, y + int_y, data, 0xff0000);
	ft_put_pixel(x + int_y, y - int_x, data, 0xff0000);
	ft_put_pixel(x - int_y, y - int_x, data, 0xff0000);
	ft_put_pixel(x + int_y, y + int_x, data, 0xff0000);
	ft_put_pixel(x - int_y, y + int_x, data, 0xff0000);
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
