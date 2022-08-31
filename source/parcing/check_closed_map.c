/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_closed_map.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboulhaj <aboulhaj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 10:57:52 by aboulhaj          #+#    #+#             */
/*   Updated: 2022/08/31 15:56:58 by aboulhaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

int	char_in_str(char *str, char c)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (1);
		i++;
	}
	return (0);
}

void	check_player(t_data **data, char **map, int x, int y)
{
	if ((*data)->texture.n_player > 1 && !(*data)->error)
		(*data)->error = ft_strdup("error : multiple players");
	else if (char_in_str(PLAY_EMPT, map[x][y]))
	{
		if (check_circle(map, x, y) && !(*data)->error)
			(*data)->error = ft_strdup("error : map no closed");
		if (char_in_str(PLAYER, map[x][y]))
			(*data)->texture.n_player++;
	}
}

void	close_map(t_data **data)
{
	int		x;
	int		y;
	char	**map;

	map = (*data)->map;
	x = 0;
	while (map[x] && !(*data)->error)
	{
		y = 0;
		while (map[x][y] && !(*data)->error)
		{
			if ((*data)->texture.n_player > 1 \
				|| char_in_str(PLAY_EMPT, map[x][y]))
				check_player(data, map, x, y);
			else if (char_in_str(WALL_SPAC, map[x][y]))
				;
			else if (!(*data)->error)
				(*data)->error = ft_strdup("invalid caracter in map");
			y++;
		}
		x++;
	}
	if ((*data)->texture.n_player == 0 && !(*data)->error)
		(*data)->error = ft_strdup("error : no player");
}
