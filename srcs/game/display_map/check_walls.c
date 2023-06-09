/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_walls.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: averdon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 15:16:52 by averdon           #+#    #+#             */
/*   Updated: 2022/11/16 14:23:37 by averdon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/so_long.h"

int	check_right_top_corner(t_double_list *map, int x)
{
	if (x > 0 && map->next
		&& ((char *)(map->next->content))[x] == '1'
		&& ((char *)(map->next->content))[x - 1] != '1')
		return (1);
	return (0);
}

int	check_left_top_corner(t_double_list *map, int x)
{
	if (x < 9 && map->next
		&& ((char *)(map->next->content))[x] == '1'
		&& ((char *)(map->next->content))[x + 1] != '1')
		return (1);
	return (0);
}

int	check_right_bot_corner(t_double_list *map, int x)
{
	if (x > 0 && map->previous
		&& ((char *)(map->previous->content))[x] == '1'
		&& ((char *)(map->previous->content))[x - 1] != '1')
		return (1);
	return (0);
}

int	check_left_bot_corner(t_double_list *map, int x)
{
	if (x < 9 && map->previous
		&& ((char *)(map->previous->content))[x] == '1'
		&& ((char *)(map->previous->content))[x + 1] != '1')
		return (1);
	return (0);
}

int	check_crate(t_vars *vars, int x, int y)
{
	if (x + vars->player->x / 640 * 10 < vars->nb_columns - 1
		&& y + vars->player->y / 640 * 10 < vars->nb_rows - 1
		&& x + vars->player->x / 640 * 10 > 0
		&& y + vars->player->y / 640 * 10 > 0)
		return (1);
	return (0);
}
