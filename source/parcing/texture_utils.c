/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboulhaj <aboulhaj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 18:14:33 by aboulhaj          #+#    #+#             */
/*   Updated: 2022/09/08 12:52:05 by aboulhaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	color_data(t_data *data, t_color *data_color, char *color, int type)
{
	char	**tab;
	int		index;

	index = 0;
	tab = ft_split(color, ',');
	while (tab[index])
		index++;
	if (index == 3)
	{
		if (type == F)
			(*data_color).t = FLOOR;
		else if (type == C)
			(*data_color).t = CEILLING;
		(*data_color).r = ft_atoi(tab[0]);
		(*data_color).g = ft_atoi(tab[1]);
		(*data_color).b = ft_atoi(tab[2]);
	}
	else if (!data->error)
		data->error = ft_strdup("error color no valid");
	if (((*data_color).r < 0 || (*data_color).g < 0
			|| (*data_color).b < 0 || (*data_color).r > 255
			|| (*data_color).g > 255 || (*data_color).b > 255) \
			&& !data->error)
		data->error = ft_strdup("error color no valid");
	ft_free_tab(tab);
}

void	storage_color(t_data *data, char *line, t_color *variable, int type)
{
	if ((*variable).r == -1)
		data->texture.check++;
	color_data(data, variable, line, type);
}

void	pre_storage_texture(t_data *data, char *line, char **variable)
{
	if (!*variable)
		data->texture.check++;
	(*variable) = ft_strdup(line);
}

void	texture_to_data(t_data *data, char *line, int size, int type)
{
	int	fd;

	line += size;
	while (*line == ' ')
		line += 1;
	line = ft_strtrim(line, "\n");
	fd = open(line, O_RDONLY);
	if (type == NO && fd > 0)
		pre_storage_texture(data, line, &data->texture.north);
	else if (type == SO && fd > 0)
		pre_storage_texture(data, line, &data->texture.south);
	else if (type == WE && fd > 0)
		pre_storage_texture(data, line, &data->texture.west);
	else if (type == EA && fd > 0)
		pre_storage_texture(data, line, &data->texture.east);
	else if (type == F)
		storage_color(data, line, &data->texture.floor, F);
	else if (type == C)
		storage_color(data, line, &data->texture.ceilling, C);
	else if (!data->error)
		data->error = ft_strdup("error texture not valide");
	free(line);
	close(fd);
}

void	texture_storage(t_data *data, char *line)
{
	while (*line == ' ')
		line += 1;
	if (!ft_strncmp(line, "NO ", 3))
		texture_to_data(data, line, 3, NO);
	else if (!ft_strncmp(line, "SO ", 3))
		texture_to_data(data, line, 3, SO);
	else if (!ft_strncmp(line, "WE ", 3))
		texture_to_data(data, line, 3, WE);
	else if (!ft_strncmp(line, "EA ", 3))
		texture_to_data(data, line, 3, EA);
	else if (!ft_strncmp(line, "F ", 2))
		texture_to_data(data, line, 2, F);
	else if (!ft_strncmp(line, "C ", 2))
		texture_to_data(data, line, 2, C);
	else if (!data->error)
		data->error = ft_strdup("error: texture no complete");
}
