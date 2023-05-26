/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_good_walls.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: averdon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 15:21:10 by averdon           #+#    #+#             */
/*   Updated: 2022/11/17 16:56:04 by averdon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

void	display_good_wall_2(t_vars *vars, t_double_list *map, int x, int y)
{
	if (check_right_top_corner(map, x) == 1)
		mlx_put_image_to_window(vars->mlx, vars->window,
			vars->array_ptr_sprite[2], x * 64, y * 64);
	else if (check_right_bot_corner(map, x) == 1)
		mlx_put_image_to_window(vars->mlx, vars->window,
			vars->array_ptr_sprite[4], x * 64, y * 64);
	else
		mlx_put_image_to_window(vars->mlx, vars->window,
			vars->array_ptr_sprite[8], x * 64, y * 64);
}

void	display_good_wall(t_vars *vars, t_double_list *map, int x, int y)
{
	if (check_crate(vars, x, y))
		mlx_put_image_to_window(vars->mlx, vars->window,
			vars->array_ptr_sprite[13], x * 64, y * 64);
	else if (check_left_side(map, x) == 1)
		mlx_put_image_to_window(vars->mlx, vars->window,
			vars->array_ptr_sprite[3], x * 64, y * 64);
	else if (check_top_side(map, x) == 1)
		mlx_put_image_to_window(vars->mlx, vars->window,
			vars->array_ptr_sprite[1], x * 64, y * 64);
	else if (check_left_top_corner(map, x) == 1)
		mlx_put_image_to_window(vars->mlx, vars->window,
			vars->array_ptr_sprite[3], x * 64, y * 64);
	else if (check_left_bot_corner(map, x) == 1)
		mlx_put_image_to_window(vars->mlx, vars->window,
			vars->array_ptr_sprite[5], x * 64, y * 64);
	else if (check_right_side(map, x) == 1)
		mlx_put_image_to_window(vars->mlx, vars->window,
			vars->array_ptr_sprite[2], x * 64, y * 64);
	else if (check_bot_side(map, x) == 1)
		mlx_put_image_to_window(vars->mlx, vars->window,
			vars->array_ptr_sprite[1], x * 64, y * 64);
	else
		display_good_wall_2(vars, map, x, y);
}
