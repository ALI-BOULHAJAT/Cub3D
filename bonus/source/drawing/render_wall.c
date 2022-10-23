/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_wall.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenbajj <mbenbajj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/11 11:02:05 by aboulhaj          #+#    #+#             */
/*   Updated: 2022/10/23 01:13:14 by mbenbajj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d_bonus.h"

int	*get_texture_side(t_data *data, char check)
{
	if (check == 'D')
		return (data->texture.door.xpm_array);
	if (data->ray.horizontal_best == 1 && data->ray.ray_face.up)
		return (data->texture.north.xpm_array);
	if (data->ray.horizontal_best == 1 && data->ray.ray_face.down)
		return (data->texture.south.xpm_array);
	if (data->ray.horizontal_best == 0 && data->ray.ray_face.right)
		return (data->texture.east.xpm_array);
	else
		return (data->texture.west.xpm_array);
}

t_index_int	get_texture_size(t_data *data, char check)
{
	if (check == 'D')
		return (data->texture.door.tex_size);
	if (data->ray.horizontal_best == 1 && data->ray.ray_face.up)
		return (data->texture.north.tex_size);
	if (data->ray.horizontal_best == 1 && data->ray.ray_face.down)
		return (data->texture.south.tex_size);
	if (data->ray.horizontal_best == 0 && data->ray.ray_face.right)
		return (data->texture.east.tex_size);
	else
		return (data->texture.west.tex_size);
}

int	rendering_texcolor(t_data *data, int tex_x, t_index ray, char check, t_door *head)
{
	t_index		tex;
	t_index_int	texture_size;
	int			*side;
	double		height;
	int			check_best;

	if (check == 'D')
		check_best = head->horizontal_best;
	else
		check_best = data->ray.horizontal_best;
	side = get_texture_side(data, check);
	texture_size = get_texture_size(data, check);
	if (check == 'D')
		height = data->ray.door_height;
	else
		height = data->ray.wall_height;
	tex.x = tex_x + ((height / 2) - (HEIGHT / 2));
	if (tex.x < 0)
		tex.x = 0;
	tex.x *= (double)texture_size.y / height;
	tex.x = floor(tex.x);
	tex.x *= texture_size.x;
	tex.y = ray.x;
	if (check_best == 0)
		tex.y = ray.y;
	tex.y /= data->texture.zoom;
	tex.y -= floor(tex.y);
	tex.y *= texture_size.x;
	return (side[(int)tex.x + (int)tex.y]);
}

void	draw_my_wall(t_data *data, double wall_height, t_index ray, char check, t_door *head)
{
	t_index	last;
	t_index	first;
	int		color;

	first.x = (HEIGHT / 2) - (wall_height / 2);
	if (first.x < 0)
		first.x = 0;
	last.x = first.x + wall_height;
	if (last.x > HEIGHT)
		last.x = HEIGHT;
	while (first.x <= last.x)
	{
		color = rendering_texcolor(data, first.x, ray, check, head);
		if (check == 'D' && color == 0)
			;
		else
			ft_put_pixel(ray.id, first.x, data, color);
		first.x++;
	}
}

void	draw_wall(t_data *data, double ray_distance, t_index ray, char check, t_door *head)
{
	double	wall_hight;
	double	distance_pr_pl;

	distance_pr_pl = (WIDTH / 2) / tan(30 * (M_PI / 180));
	ray_distance = ray_distance * (cos(data->ray.angle_ray - data->player.alpha));
	wall_hight = (data->texture.zoom / (ray_distance)) * distance_pr_pl;
	if (check == 'W')
		data->ray.wall_height = wall_hight;
	else
		data->ray.door_height = wall_hight;
	if (wall_hight > HEIGHT)
		wall_hight = HEIGHT;
	draw_my_wall(data, wall_hight, ray, check, head);
}
