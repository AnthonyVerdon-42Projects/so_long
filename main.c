/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: averdon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 15:23:49 by averdon           #+#    #+#             */
/*   Updated: 2022/12/05 17:22:50 by averdon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_vars			*vars;
	t_double_list	*map;

	map = parsing(argc, argv);
	vars = ft_calloc(1, sizeof(t_vars));
	initialize_var(vars, map, argc, argv);
	randomize_enemies(vars);
	display_map(vars);
	display_background(vars);
	mlx_put_image_to_window(vars->mlx, vars->window,
		vars->player->sprite[vars->player->frame],
		vars->player->x % 640, vars->player->y % 640);
	mlx_put_image_to_window(vars->mlx, vars->window,
		vars->array_ptr_sprite[14], 660, 64);
	mlx_hook(vars->window, KeyPress, KeyPressMask, key_hook, vars);
	mlx_hook(vars->window, DestroyNotify, StructureNotifyMask,
		close_window, vars);
	mlx_loop_hook(vars->mlx, animation_and_movement, vars);
	mlx_loop(vars->mlx);
	return (0);
}
