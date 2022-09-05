/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboulhaj <aboulhaj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 19:32:01 by aboulhaj          #+#    #+#             */
/*   Updated: 2022/09/05 10:56:04 by aboulhaj         ###   ########.fr       */
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
		if (count_line == 0)
			(*data)->error = ft_strdup("Empty file");
		else if (count_line < 6)
			(*data)->error = ft_strdup("No map");
		else
			(*data)->texture.map_size = count_line - 6;
	}
	close (fd);
}
