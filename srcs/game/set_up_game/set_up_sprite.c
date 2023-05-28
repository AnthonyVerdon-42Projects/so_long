/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_up_sprite.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: averdon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 00:01:29 by averdon           #+#    #+#             */
/*   Updated: 2023/05/28 14:57:32 by averdon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/so_long.h"

void	set_up_array_ptr_tile_3(t_vars *vars)
{
	int	width;
	int	height;

	vars->array_ptr_sprite[19] = mlx_xpm_file_to_image(vars->mlx,
			"assets/numbers/five.xpm", &width, &height);
	vars->array_ptr_sprite[20] = mlx_xpm_file_to_image(vars->mlx,
			"assets/numbers/six.xpm", &width, &height);
	vars->array_ptr_sprite[21] = mlx_xpm_file_to_image(vars->mlx,
			"assets/numbers/seven.xpm", &width, &height);
	vars->array_ptr_sprite[22] = mlx_xpm_file_to_image(vars->mlx,
			"assets/numbers/eight.xpm", &width, &height);
	vars->array_ptr_sprite[23] = mlx_xpm_file_to_image(vars->mlx,
			"assets/numbers/nine.xpm", &width, &height);
	vars->array_ptr_sprite[24] = mlx_xpm_file_to_image(vars->mlx,
			"assets/minimap/grey_dot.xpm", &width, &height);
	vars->array_ptr_sprite[25] = mlx_xpm_file_to_image(vars->mlx,
			"assets/minimap/red_dot.xpm", &width, &height);
	vars->array_ptr_sprite[26] = mlx_xpm_file_to_image(vars->mlx,
			"assets/screen_end/you_win.xpm", &width, &height);
	vars->array_ptr_sprite[27] = mlx_xpm_file_to_image(vars->mlx,
			"assets/screen_end/you_lose.xpm", &width, &height);
}

void	set_up_array_ptr_tile_2(t_vars *vars)
{
	int	width;
	int	height;

	vars->array_ptr_sprite[10] = mlx_xpm_file_to_image(vars->mlx,
			"assets/enemies/fly_anim_f1.xpm", &width, &height);
	vars->array_ptr_sprite[11] = mlx_xpm_file_to_image(vars->mlx,
			"assets/enemies/fly_anim_f2.xpm", &width, &height);
	vars->array_ptr_sprite[12] = mlx_xpm_file_to_image(vars->mlx,
			"assets/enemies/fly_anim_f3.xpm", &width, &height);
	vars->array_ptr_sprite[13] = mlx_xpm_file_to_image(vars->mlx,
			"assets/tilemap/crate.xpm", &width, &height);
	vars->array_ptr_sprite[14] = mlx_xpm_file_to_image(vars->mlx,
			"assets/numbers/zero.xpm", &width, &height);
	vars->array_ptr_sprite[15] = mlx_xpm_file_to_image(vars->mlx,
			"assets/numbers/one.xpm", &width, &height);
	vars->array_ptr_sprite[16] = mlx_xpm_file_to_image(vars->mlx,
			"assets/numbers/two.xpm", &width, &height);
	vars->array_ptr_sprite[17] = mlx_xpm_file_to_image(vars->mlx,
			"assets/numbers/three.xpm", &width, &height);
	vars->array_ptr_sprite[18] = mlx_xpm_file_to_image(vars->mlx,
			"assets/numbers/four.xpm", &width, &height);
	set_up_array_ptr_tile_3(vars);
}

void	set_up_array_ptr_tile(t_vars *vars)
{
	int	width;
	int	height;

	vars->array_ptr_sprite = ft_calloc(28, sizeof(void *));
	vars->array_ptr_sprite[0] = mlx_xpm_file_to_image(vars->mlx,
			"assets/tilemap/floor_1.xpm", &width, &height);
	vars->array_ptr_sprite[1] = mlx_xpm_file_to_image(vars->mlx,
			"assets/tilemap/wall_mid.xpm", &width, &height);
	vars->array_ptr_sprite[2] = mlx_xpm_file_to_image(vars->mlx,
			"assets/tilemap/wall_side_mid_right.xpm", &width, &height);
	vars->array_ptr_sprite[3] = mlx_xpm_file_to_image(vars->mlx,
			"assets/tilemap/wall_side_mid_left.xpm", &width, &height);
	vars->array_ptr_sprite[4] = mlx_xpm_file_to_image(vars->mlx,
			"assets/tilemap/wall_right_bot_corner.xpm", &width, &height);
	vars->array_ptr_sprite[5] = mlx_xpm_file_to_image(vars->mlx,
			"assets/tilemap/wall_left_bot_corner.xpm", &width, &height);
	vars->array_ptr_sprite[6] = mlx_xpm_file_to_image(vars->mlx,
			"assets/tilemap/chest_empty_open_anim_f0.xpm", &width, &height);
	vars->array_ptr_sprite[7] = mlx_xpm_file_to_image(vars->mlx,
			"assets/tilemap/floor_ladder.xpm", &width, &height);
	vars->array_ptr_sprite[8] = mlx_xpm_file_to_image(vars->mlx,
			"assets/tilemap/black.xpm", &width, &height);
	vars->array_ptr_sprite[9] = mlx_xpm_file_to_image(vars->mlx,
			"assets/enemies/fly_anim_f0.xpm", &width, &height);
	set_up_array_ptr_tile_2(vars);
}

void	set_up_array_ptr_player_2(t_vars *vars)
{
	int				width;
	int				height;

	vars->player->sprite[8] = mlx_xpm_file_to_image(vars->mlx,
			"assets/player/knight_idle_anim_f0_reverse.xpm", &width, &height);
	vars->player->sprite[9] = mlx_xpm_file_to_image(vars->mlx,
			"assets/player/knight_idle_anim_f2_reverse.xpm", &width, &height);
	vars->player->sprite[10] = mlx_xpm_file_to_image(vars->mlx,
			"assets/player/knight_idle_anim_f2_reverse.xpm", &width, &height);
	vars->player->sprite[11] = mlx_xpm_file_to_image(vars->mlx,
			"assets/player/knight_idle_anim_f2_reverse.xpm", &width, &height);
}

void	set_up_array_ptr_player(t_vars *vars)
{
	int				width;
	int				height;

	vars->player->sprite = ft_calloc(12, sizeof(void *));
	vars->player->sprite[0] = mlx_xpm_file_to_image(vars->mlx,
			"assets/player/knight_idle_anim_f0.xpm", &width, &height);
	vars->player->sprite[1] = mlx_xpm_file_to_image(vars->mlx,
			"assets/player/knight_idle_anim_f0.xpm", &width, &height);
	vars->player->sprite[2] = mlx_xpm_file_to_image(vars->mlx,
			"assets/player/knight_idle_anim_f0.xpm", &width, &height);
	vars->player->sprite[3] = mlx_xpm_file_to_image(vars->mlx,
			"assets/player/knight_idle_anim_f2.xpm", &width, &height);
	vars->player->sprite[4] = mlx_xpm_file_to_image(vars->mlx,
			"assets/player/knight_idle_anim_f2.xpm", &width, &height);
	vars->player->sprite[5] = mlx_xpm_file_to_image(vars->mlx,
			"assets/player/knight_idle_anim_f2.xpm", &width, &height);
	vars->player->sprite[6] = mlx_xpm_file_to_image(vars->mlx,
			"assets/player/knight_idle_anim_f0_reverse.xpm", &width, &height);
	vars->player->sprite[7] = mlx_xpm_file_to_image(vars->mlx,
			"assets/player/knight_idle_anim_f0_reverse.xpm", &width, &height);
	set_up_array_ptr_player_2(vars);
}
