/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_up_var.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: averdon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 00:05:09 by averdon           #+#    #+#             */
/*   Updated: 2022/11/18 00:05:37 by averdon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/so_long.h"

void	initialize_var(t_vars *vars, t_double_list *map, int argc, char **argv)
{
	t_point			*start;

	vars->map = map;
	vars->nb_columns = calculate_columns(vars->map);
	vars->nb_rows = calculate_rows(vars->map);
	vars->map_chunk = divise_map(vars);
	vars->mlx = mlx_init();
	vars->window = mlx_new_window(vars->mlx, 960, 640, "Game");
	vars->player = ft_calloc(1, sizeof(t_player));
	set_up_array_ptr_player(vars);
	start = find_start(&vars->map);
	vars->player->x = start->x * 64;
	vars->player->y = start->y * 64;
	vars->player->old_point = ft_calloc(1, sizeof(t_point));
	vars->player->nb_collectibles = 0;
	vars->player->nb_move = 0;
	vars->player->frame = 0;
	vars->player->side = 0;
	vars->game_finish = 0;
	vars->argc = argc;
	vars->argv = argv;
	free(start);
	set_up_array_ptr_tile(vars);
	vars->nb_collectibles = calculate_collectibles(&vars->map);
	vars->frame_enemy = 0;
}
