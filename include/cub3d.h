/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboulhaj <aboulhaj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 10:32:35 by aboulhaj          #+#    #+#             */
/*   Updated: 2022/09/09 18:47:11 by aboulhaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdio.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>

# include "structs.h"
# include "../libft/libft.h"
# include "utils.h"
# include "macros.h"
# include <mlx.h>
# include <math.h>

# define FLOOR  0
# define CEILLING 0
# define WEIGHT 1200
# define HIEGHT 1600
# define STEP 0.1
# define ALPHA 0.1
# define RAY 5
# define FOV_ANGLE 60

# define FOV_COLOR 0x977950

// FOV_ANGLE 60 * M_PI / 180
/////////////// PARCING ///////////////////////

void	read_map(t_data *data, char **av);
void	color_data(t_data *data, t_color *data_color, char *color, int type);
void	texture_to_data(t_data *data, char *line, int size, int type);
void	texture_storage(t_data *data, char *line);
int		file_type(char *file, char *type);
void	ft_free_tab(char **tab);
void	map_size(t_data *data, char *file);
void	init_struct(t_data *data);
int		empty_line(char *line);
void	close_map(t_data *data);
int		check_circle(char **map, int x, int y);
void	init_face(t_data *data);
int		char_in_str(char *str, char c);

/////////////  DRAWING ///////////////////////

void	ft_hook(t_data *data);
int		ft_movekey(t_data *data);
void	drawing(t_data *data);
void	drow_to_img(t_data *data);
void	ft_put_pixel(int x, int y, t_data *data, int color);
void	draw_circle(t_data *data);
void	check_key(t_data *data);
void	draw_fov(t_data *data);
void	horizontal_intersection(t_data *data);
void	vertical_intersection(t_data *data);
void	draw_line(t_data *data, t_index first, t_index last, int color);
double	distance_2_point(t_index first, t_index last);
void	get_distance(t_data *data, t_index *ray);
double	normalizeangle(double angle);
void	facing_ray(t_data *data);
t_index	player_possition(t_data *data);
int		is_v_wall(t_data *data, double x, double y, t_index step);

#endif