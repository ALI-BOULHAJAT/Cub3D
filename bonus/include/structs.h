/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboulhaj <aboulhaj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 10:58:17 by aboulhaj          #+#    #+#             */
/*   Updated: 2022/09/12 14:02:52 by aboulhaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

# include "cub3d_bonus.h"

typedef struct s_index
{
	double	x;
	double	y;
}	t_index;

typedef struct s_index_int
{
	int	x;
	int	y;
}	t_index_int;

typedef struct s_face
{
	int	up;
	int	down;
	int	left;
	int	right;
}	t_face;

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
	t_index	mouve;
	char	face;
}	t_player;

typedef struct s_casting
{
	t_index				ray;
	double				distance;
	int					ray_id;
	struct s_casting	*next;
}	t_casting;

typedef struct s_texture
{
	char		*north;
	char		*south;
	char		*east;
	char		*west;
	int			check;
	t_index_int	map_size;
	int			is_empty_line;
	int			read_in_map;
	int			zoom;
	t_color		floor;
	t_color		ceilling;

}	t_texture;

typedef struct s_ray
{
	t_face	ray_face;
	int		found_h_wall;
	int		found_v_wall;
	int		v_is_best;
	int		h_is_best;
	t_index	vertical_touch;
	t_index	horizontal_touch;
	double	angle_ray;
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

typedef struct s_view
{
	int	view_2d;
	int	view_3d;
}	t_view;

typedef struct s_data
{
	t_texture	texture;
	t_casting	*casting;
	t_view		view;
	t_player	player;
	t_img		*img;
	char		**map;
	char		*error;
	t_hook		my_hook;
	t_ray		ray;

}	t_data;

#endif