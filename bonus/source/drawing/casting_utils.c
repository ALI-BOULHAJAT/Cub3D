/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   casting_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenbajj <mbenbajj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 13:25:07 by mbenbajj          #+#    #+#             */
/*   Updated: 2022/10/23 01:00:33 by mbenbajj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d_bonus.h"

t_door	*lst_new(int found, t_index inter)
{
	t_door	*door;

	door = (t_door *)ft_calloc(1, sizeof(t_door));
	door->found_h = 0;
	door->found_v = 0;
	if (found == 1)
	{
		door->found_h = 1;
		door->horizontal_touch.x = inter.x;
		door->horizontal_touch.y = inter.y;
	}
	else if (found == 2)
	{
		door->found_v = 1;
		door->vertical_touch.x = inter.x;
		door->vertical_touch.y = inter.y;
	}
	door->next = NULL;
	return (door);
}

// void	lst_reinit(t_door **lst, )
// {
	
// }

void	add_front(t_door **lst, t_door *new)
{
	if (!new)
		return ;
	// if (!(*lst))
	// 	(*lst) = new;
	else
	{
		new->next = (*lst);
		(*lst) = new;
	}
}