/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: averdon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 11:32:33 by averdon           #+#    #+#             */
/*   Updated: 2022/11/17 23:25:38 by averdon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

void	display_minimap(t_vars *vars)
{
	t_double_list	*buffer;

	buffer = vars->map_chunk;
	while (buffer)
	{
		if ((((t_tilemap *)(buffer->content))->x == vars->player->x / 640)
			&& (((t_tilemap *)(buffer->content))->y == vars->player->y / 640))
			mlx_put_image_to_window(vars->mlx, vars->window,
				vars->array_ptr_sprite[25],
				((t_tilemap *)(buffer->content))->x * 32 + 660,
				((t_tilemap *)(buffer->content))->y * 32 + 320);
		else
			mlx_put_image_to_window(vars->mlx, vars->window,
				vars->array_ptr_sprite[24],
				((t_tilemap *)(buffer->content))->x * 32 + 660,
				((t_tilemap *)(buffer->content))->y * 32 + 320);
		buffer = buffer->next;
	}
}

void	display_background(t_vars *vars)
{
	int				x;
	int				y;

	y = 0;
	while (y < 10)
	{
		x = 0;
		while (x < 5)
		{
			mlx_put_image_to_window(vars->mlx, vars->window,
				vars->array_ptr_sprite[8], 640 + x * 64, y * 64);
			x++;
		}
		y++;
	}
	display_minimap(vars);
}

void	display_good_tiles(t_vars *vars, t_double_list *map, int x, int y)
{
	if (((char *)(map->content))[x] == '0')
		mlx_put_image_to_window(vars->mlx, vars->window,
			vars->array_ptr_sprite[0], x * 64, y * 64);
	else if (((char *)(map->content))[x] == '1')
		display_good_wall(vars, map, x, y);
	else if (((char *)(map->content))[x] == 'C')
		mlx_put_image_to_window(vars->mlx, vars->window,
			vars->array_ptr_sprite[6], x * 64, y * 64);
	else if (((char *)(map->content))[x] == 'E')
	{
		if (vars->player->nb_collectibles != vars->nb_collectibles)
			mlx_put_image_to_window(vars->mlx, vars->window,
				vars->array_ptr_sprite[13], x * 64, y * 64);
		else
			mlx_put_image_to_window(vars->mlx, vars->window,
				vars->array_ptr_sprite[7], x * 64, y * 64);
	}
	else if (((char *)(map->content))[x] == 'M')
		mlx_put_image_to_window(vars->mlx, vars->window,
			vars->array_ptr_sprite[9 + vars->frame_enemy], x * 64, y * 64);
}

void	display_map(t_vars *vars)
{
	t_double_list	*buffer;
	t_double_list	*map;
	int				x;
	int				y;

	buffer = vars->map_chunk;
	while ((((t_tilemap *)(buffer->content))->x != vars->player->x / 640)
		|| (((t_tilemap *)(buffer->content))->y != vars->player->y / 640))
		buffer = buffer->next;
	y = 0;
	map = (t_double_list *)((t_tilemap *)(buffer->content))->map;
	while (map)
	{
		x = 0;
		while (x < 10)
		{
			display_good_tiles(vars, map, x, y);
			x++;
		}
		y++;
		map = map->next;
	}
	display_minimap(vars);
}
