/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: averdon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 22:01:19 by averdon           #+#    #+#             */
/*   Updated: 2022/11/17 21:35:17 by averdon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	destroy_all_images(t_vars *vars)
{
	int	i;

	i = 0;
	while (i < 28)
	{
		mlx_destroy_image(vars->mlx, vars->array_ptr_sprite[i]);
		i++;
	}
	i = 0;
	while (i < 12)
	{
		mlx_destroy_image(vars->mlx, vars->player->sprite[i]);
		i++;
	}
}

void	destroy_and_free(t_vars *vars)
{
	t_double_list	*buffer;

	mlx_loop_end(vars->mlx);
	destroy_all_images(vars);
	mlx_destroy_window(vars->mlx, vars->window);
	mlx_destroy_display(vars->mlx);
	ft_double_lstclear(&vars->map, del);
	buffer = vars->map_chunk;
	while (vars->map_chunk)
	{
		ft_double_lstclear(&((t_tilemap *)(vars->map_chunk->content))->map,
			del);
		vars->map_chunk = vars->map_chunk->next;
	}
	ft_double_lstclear(&buffer, del);
	free(vars->player->sprite);
	free(vars->player->old_point);
	free(vars->player);
	free(vars->array_ptr_sprite);
	free(vars->mlx);
	free(vars);
}

int	calculate_columns(t_double_list *map)
{
	int	columns;

	columns = 0;
	while (((char *)(map->content))[columns])
			columns++;
	return (columns);
}

int	calculate_rows(t_double_list *map)
{
	int				rows;
	t_double_list	*buffer;

	rows = 0;
	buffer = map;
	while (buffer)
	{
		buffer = buffer->next;
		rows++;
	}
	return (rows);
}

int	calculate_collectibles(t_double_list **map)
{
	t_double_list	*buffer;
	int				i;
	int				nb_collectibles;

	buffer = *map;
	nb_collectibles = 0;
	while (buffer)
	{
		i = 0;
		while (((char *)(buffer->content))[i])
		{
			if (((char *)(buffer->content))[i] == 'C')
				nb_collectibles++;
			i++;
		}
		buffer = buffer->next;
	}
	return (nb_collectibles);
}
