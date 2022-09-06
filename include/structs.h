/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboulhaj <aboulhaj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 10:58:17 by aboulhaj          #+#    #+#             */
/*   Updated: 2022/09/06 18:57:04 by aboulhaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

# include "cub3d.h"

typedef struct s_color
{
	int	t;
	int	r;
	int	g;
	int	b;

}	t_color;

typedef struct s_img
{
	void	*img;
	char	*addr;
	int		bit_img;
	int		d_size;
	int		endian;
	void	*mlx;
	void	*win;

}	t_img;

typedef struct s_player
{
	int		n_player;
	double	init_x_player;
	double	init_y_player;
	double	player_x;
	double	player_y;
	int		to_north;
	int		to_south;
	int		to_east;
	int		to_west;
	double	alpha;
	char	face;
}	t_player;

typedef struct s_texture
{
	char	*north;
	char	*south;
	char	*east;
	char	*west;
	int		check;
	int		map_size;
	int		is_empty_line;
	int		read_in_map;
	int		zoom;
	t_color	floor;
	t_color	ceilling;

}	t_texture;

typedef struct s_ray
{
	int		ray_face_up;
	int		ray_face_down;
	int		ray_face_left;
	int		ray_face_right;
	double	first_x_intersection[2];
	double	x_intersection_step[2];
	double	first_y_intersection[2];
	double	y_intersection_step[2];
}	t_ray;

typedef struct s_hook
{
	int	key_north;
	int	key_south;
	int	key_east;
	int	key_west;
	int	key_w;
	int	key_d;
	int	key_s;
	int	key_a;
}	t_hook;

typedef struct s_data
{
	t_texture	texture;
	t_player	player;
	t_img		*img;
	char		**map;
	char		*error;
	t_hook		my_hook;
	t_ray		ray;

}	t_data;

#endif