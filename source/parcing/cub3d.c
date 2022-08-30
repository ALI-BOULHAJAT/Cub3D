/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboulhaj <aboulhaj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 14:46:36 by aboulhaj          #+#    #+#             */
/*   Updated: 2022/08/30 19:34:14 by aboulhaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

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
	{
		printf("%d\n", data.texture.check);
		printf("north ->%s\n", data.texture.north);
		printf("east ->%s\n", data.texture.east);
		printf("south ->%s\n", data.texture.south);
		printf("west ->%s\n", data.texture.west);
		printf("floor -> %d,%d,%d,%d\n", data.texture.floor.t, \
		data.texture.floor.r, data.texture.floor.g, data.texture.floor.b);
		printf("ceilling -> %d,%d,%d,%d\n", \
		data.texture.ceilling.t, data.texture.ceilling.r, \
		data.texture.ceilling.g, data.texture.ceilling.b);
	}
	system("leaks cub3d");
	printf("\ndone\n");
	return (0);
}
