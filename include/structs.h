/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboulhaj <aboulhaj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 10:58:17 by aboulhaj          #+#    #+#             */
/*   Updated: 2022/08/30 17:03:21 by aboulhaj         ###   ########.fr       */
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

typedef struct s_texture
{
	char	*north;
	char	*south;
	char	*east;
	char	*west;
	int		check;
	t_color	floor;
	t_color	ceilling;

}	t_texture;

typedef struct s_data
{
	char		**map;
	t_texture	texture;
	char		*error;

}	t_data;

#endif