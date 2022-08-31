/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_storage.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboulhaj <aboulhaj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 10:50:06 by aboulhaj          #+#    #+#             */
/*   Updated: 2022/08/31 15:45:52 by aboulhaj         ###   ########.fr       */
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

int	check_texture_done(t_data **data)
{
	t_texture	value;

	value = (*data)->texture;
	if ((!value.east || !value.north || !value.south \
	|| !value.west || value.ceilling.r == -1 || value.floor.r == -1) \
	&& !(*data)->error)
	{
		(*data)->error = ft_strdup("error: texture no complete");
		return (0);
	}
	else
		return (1);
}

void	pre_while(t_data **data, char *line, int *index, int *i_map)
{
	if (!empty_line(line) || (*data)->texture.read_in_map == 1)
	{
		if ((*index) < 6 && !(*data)->error)
		{
			texture_storage(data, line);
			(*index)++;
		}
		else if (check_texture_done(data) && !(*data)->error)
		{
			if (empty_line(line) && !(*data)->error)
				(*data)->error = ft_strdup("error : empty line in map");
			(*data)->texture.read_in_map = 1;
			(*data)->map[(*i_map)] = ft_strdup(line);
			(*i_map)++;
		}
	}
	(*data)->map[(*i_map)] = NULL;
	free(line);
	line = NULL;
}

void	while_loop(t_data **data, int fd)
{
	char	*line;
	int		index;
	int		i_map;

	index = 0;
	i_map = 0;
	(*data)->map = (char **)malloc(sizeof(char **) \
	* ((*data)->texture.map_size + 1));
	while (!(*data)->error)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		pre_while(data, line, &index, &i_map);
	}
}

void	read_map(t_data *data, char **av)
{
	int		fd;
	int		index;

	map_size(&data, av[1]);
	fd = open(av[1], O_RDONLY);
	init_struct(&data);
	index = 0;
	if (fd > 0 && file_type(av[1], ".cub"))
	{
		while_loop(&data, fd);
		close_map(&data);
	}
	else
		data->error = ft_strdup("file not valid");
	close(fd);
}
