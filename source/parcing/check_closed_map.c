/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_closed_map.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboulhaj <aboulhaj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 10:57:52 by aboulhaj          #+#    #+#             */
/*   Updated: 2022/09/05 10:39:01 by aboulhaj         ###   ########.fr       */
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

void	check_v_wall(char **map, int x, int y)
{
	if (map[x - 1][y] == '1' && map[x][y - 1] == '1' \
	&& map[x - 1][y - 1] == '0' && map[x][y] == '0')
	{
		map[x - 1][y - 1] = '2';
		map[x][y] = '3';
	}
	if (map[x + 1][y] == '1' && map[x][y - 1] == '1' \
	&& map[x + 1][y - 1] == '0' && map[x][y] == '0')
	{
		map[x + 1][y - 1] = '2';
		map[x][y] = '3';
	}
}

void	check_player(t_data **data, char **map, int x, int y)
{
	if ((*data)->player.n_player > 1 && !(*data)->error)
		(*data)->error = ft_strdup("error : multiple players");
	else if (char_in_str(PLAY_EMPT, map[x][y]))
	{
		if (check_circle(map, x, y) && !(*data)->error)
			(*data)->error = ft_strdup("error : map no closed");
		if (char_in_str(PLAYER, map[x][y]))
			(*data)->player.n_player++;
	}
	check_v_wall(map, x, y);
}

void	while_closed(t_data **data, char **map, int x, int *y)
{
	if (map[x][*y] == '\t')
		(*data)->error = ft_strdup("error white-space in the map");
	else if (char_in_str(PLAY_EMPT, map[x][*y]))
		check_player(data, map, x, *y);
	else if (char_in_str(WALL_SPAC, map[x][*y]))
		;
	else if (!(*data)->error)
		(*data)->error = ft_strdup("invalid caracter in map");
	(*y)++;
}

void	close_map(t_data **data)
{
	int		x;
	int		y;
	char	**map;

	map = (*data)->map;
	x = 0;
	while (!(*data)->error && map[x])
	{
		y = 0;
		while (map[x][y] && !(*data)->error)
			while_closed(data, map, x, &y);
		x++;
	}
	if ((*data)->player.n_player == 0 && !(*data)->error)
		(*data)->error = ft_strdup("error : no player");
}
