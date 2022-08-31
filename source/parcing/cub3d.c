/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboulhaj <aboulhaj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 14:46:36 by aboulhaj          #+#    #+#             */
/*   Updated: 2022/08/31 15:45:35 by aboulhaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	print_data(t_data data)
{
	int		i;

	i = 0;
	printf("north ->%s\n", data.texture.north);
	printf("east ->%s\n", data.texture.east);
	printf("south ->%s\n", data.texture.south);
	printf("west ->%s\n", data.texture.west);
	printf("floor -> %d,%d,%d,%d\n", data.texture.floor.t, \
	data.texture.floor.r, data.texture.floor.g, data.texture.floor.b);
	printf("ceilling -> %d,%d,%d,%d\n", \
	data.texture.ceilling.t, data.texture.ceilling.r, \
	data.texture.ceilling.g, data.texture.ceilling.b);
	printf("\n\n");
	while (data.map[i])
	{
		printf("%s", data.map[i]);
		i++;
	}
}

int	main(int ac, char **av)
{
	t_data	data;

	if (ac != 2)
		return (1);
	else
		read_map(&data, av);
	if (data.error)
		printf("%s\n", data.error);
	else
		print_data(data);
	printf("\ndone\n");
	return (0);
}
	// system("leaks cub3d");
