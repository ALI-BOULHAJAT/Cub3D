/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboulhaj <aboulhaj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 14:46:36 by aboulhaj          #+#    #+#             */
/*   Updated: 2022/10/23 10:54:33 by aboulhaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d_bonus.h"

// void	print_data(t_data data)
// {
// 	int		i;

// 	i = 0;
// 	printf("north ->%s\n", data.texture.north);
// 	printf("east ->%s\n", data.texture.east);
// 	printf("south ->%s\n", data.texture.south);
// 	printf("west ->%s\n", data.texture.west);
// 	printf("floor -> %d,%d,%d,%d\n", data.texture.floor.t,
// 	data.texture.floor.r, data.texture.floor.g, data.texture.floor.b);
// 	printf("ceilling -> %d,%d,%d,%d\n",
// 	data.texture.ceilling.t, data.texture.ceilling.r,
// 	data.texture.ceilling.g, data.texture.ceilling.b);
// 	printf("\n\n");
// 	while (data.map[i])
// 	{
// 		printf("%s", data.map[i]);
// 		i++;
// 	}
// }

void	close_map(t_data *data)
{
	t_index_int	index;
	char		**map;

	map = data->map;
	index.x = 0;
	while (!data->error && map[index.x])
	{
		index.y = 0;
		while (map[index.x][index.y] && !data->error)
			while_closed(data, map, index.x, &index.y);
		index.x++;
	}
	init_face(data);
	if (data->player.n_player == 0 && !data->error)
		data->error = ft_strdup("error : no player");
}

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

int	main(int ac, char **av)
{
	t_data	data;

	if (ac != 2)
	{
		printf("\x1b[31m Error in arguments \033[0m\n");
		return (1);
	}
	else
		read_map(&data, av);
	if (data.error)
	{
		printf("\x1b[31m Error \033[0m\n");
		printf("\x1b[31m🚫 %s 🚫\033[0m\n", data.error);
	}
	else
	{
		draw_to_img(&data);
		ft_hook(&data);
	}
 
	return (0);
}
		// system("leaks cub3d");
		// printf("\ndone\n");
