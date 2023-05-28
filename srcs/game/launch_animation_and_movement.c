/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launch_animation_and_movement.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: averdon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 04:29:26 by averdon           #+#    #+#             */
/*   Updated: 2022/11/17 19:43:01 by averdon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

int	animations(t_vars *vars)
{
	static int	count;

	if (vars->game_finish)
		return (0);
	count += 1000;
	if (count < 200000)
		return (0);
	count = 0;
	mlx_put_image_to_window(vars->mlx, vars->window,
		vars->player->sprite[vars->player->frame + vars->player->side],
		vars->player->x % 640, vars->player->y % 640);
	vars->player->frame++;
	if (vars->player->frame == 6)
		vars->player->frame = 0;
	return (0);
}

int	animation_and_movement(t_vars *vars)
{
	if (vars->game_finish)
		return (0);
	usleep(1000);
	enemies_movement(vars);
	animations(vars);
	return (0);
}
