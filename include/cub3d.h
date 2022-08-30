/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboulhaj <aboulhaj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 10:32:35 by aboulhaj          #+#    #+#             */
/*   Updated: 2022/08/30 19:38:30 by aboulhaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdio.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>

# include "structs.h"
# include "../libft/libft.h"
# include "utils.h"
# include "macros.h"

# define FLOOR  0
# define CEILLING 0

/////////////// PARCING ///////////////////////

void	read_map(t_data *data, char **av);
void	color_data(t_data **data, t_color *data_color, char *color, int type);
void	texture_to_data(t_data **data, char *line, int size, int type);
void	texture_storage(t_data **data, char *line);
int		file_type(char *file, char *type);
void	ft_free_tab(char **tab);

#endif