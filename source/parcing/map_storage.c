/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_storage.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboulhaj <aboulhaj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 10:50:06 by aboulhaj          #+#    #+#             */
/*   Updated: 2022/08/30 19:49:00 by aboulhaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

int	empty_line(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] != ' ' && line[i] != '\n')
			return (0);
		i++;
	}
	return (1);
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
	init_color(&((*data)->texture.floor));
	init_color(&((*data)->texture.ceilling));
}

void	while_loop(t_data **data, int fd)
{
	char	*line;
	int		index;

	index = 0;
	line = get_next_line(fd);
	while (line)
	{
		if (!empty_line(line))
		{
			if (index < 6 && !(*data)->error)
			{
				texture_storage(data, line);
				index++;
			}	
		}
		free(line);
		line = NULL;
		line = get_next_line(fd);
	}
}

void	read_map(t_data *data, char **av)
{
	int		fd;
	int		index;

	fd = open(av[1], O_RDONLY);
	init_struct(&data);
	index = 0;
	if (fd > 0 && file_type(av[1], ".cub"))
		while_loop(&data, fd);
	else
		data->error = ft_strdup("file not valid");
	close(fd);
}
