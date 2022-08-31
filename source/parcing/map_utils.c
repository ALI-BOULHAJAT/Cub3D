/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboulhaj <aboulhaj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 19:32:01 by aboulhaj          #+#    #+#             */
/*   Updated: 2022/08/31 13:17:56 by aboulhaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

int	file_type(char *file, char *type)
{
	char	*text;

	text = ft_strrchr(file, '.');
	if (ft_strcmp(text, type))
		return (0);
	else
		return (1);
}

void	ft_free_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

void	map_size(t_data **data, char *file)
{
	int		fd;
	char	*line;
	int		count_line;

	count_line = 0;
	fd = open(file, O_RDONLY);
	if (fd > 0)
	{
		while (1)
		{
			line = get_next_line(fd);
			if (!line)
				break ;
			if (!empty_line(line))
				count_line++;
			free(line);
		}
		(*data)->texture.map_size = count_line - 6;
	}
	close (fd);
}

void	init_color(t_color *color)
{
	(*color).t = -1;
	(*color).r = -1;
	(*color).g = -1;
	(*color).b = -1;
}

void	init_struct(t_data **data)
{
	(*data)->error = NULL;
	(*data)->texture.east = NULL;
	(*data)->texture.north = NULL;
	(*data)->texture.south = NULL;
	(*data)->texture.west = NULL;
	(*data)->texture.check = 0;
	(*data)->texture.read_in_map = 0;
	(*data)->texture.n_player = 0;
	init_color(&((*data)->texture.floor));
	init_color(&((*data)->texture.ceilling));
}
