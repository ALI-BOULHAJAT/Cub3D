/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboulhaj <aboulhaj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 14:46:36 by aboulhaj          #+#    #+#             */
/*   Updated: 2022/09/08 13:01:30 by aboulhaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

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
		drawing(&data);
	return (0);
}
		// print_data(data);
		// system("leaks cub3d");
		// printf("\ndone\n");
