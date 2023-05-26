/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions_key.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: averdon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 15:14:38 by averdon           #+#    #+#             */
/*   Updated: 2022/11/17 15:17:37 by averdon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

int	key_up(t_vars *vars, char actual_place)
{
	vars->player->nb_move++;
	if (actual_place == 'E')
		mlx_put_image_to_window(vars->mlx, vars->window,
			vars->array_ptr_sprite[7],
			vars->player->x % 640, vars->player->y % 640);
	else
		mlx_put_image_to_window(vars->mlx, vars->window,
			vars->array_ptr_sprite[0],
			vars->player->x % 640, vars->player->y % 640);
	vars->player->y -= 64;
	return (0);
}

int	key_down(t_vars *vars, char actual_place)
{
	vars->player->nb_move++;
	if (actual_place == 'E')
		mlx_put_image_to_window(vars->mlx, vars->window,
			vars->array_ptr_sprite[7],
			vars->player->x % 640, vars->player->y % 640);
	else
		mlx_put_image_to_window(vars->mlx, vars->window,
			vars->array_ptr_sprite[0],
			vars->player->x % 640, vars->player->y % 640);
	vars->player->y += 64;
	return (0);
}

int	key_left(t_vars *vars, char actual_place)
{
	vars->player->nb_move++;
	if (actual_place == 'E')
		mlx_put_image_to_window(vars->mlx, vars->window,
			vars->array_ptr_sprite[7],
			vars->player->x % 640, vars->player->y % 640);
	else
		mlx_put_image_to_window(vars->mlx, vars->window,
			vars->array_ptr_sprite[0],
			vars->player->x % 640, vars->player->y % 640);
	vars->player->x -= 64;
	vars->player->side = 6;
	return (0);
}

int	key_right(t_vars *vars, char actual_place)
{
	vars->player->nb_move++;
	if (actual_place == 'E')
		mlx_put_image_to_window(vars->mlx, vars->window,
			vars->array_ptr_sprite[7],
			vars->player->x % 640, vars->player->y % 640);
	else
		mlx_put_image_to_window(vars->mlx, vars->window,
			vars->array_ptr_sprite[0],
			vars->player->x % 640, vars->player->y % 640);
	vars->player->x += 64;
	vars->player->side = 0;
	return (0);
}
