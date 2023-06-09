/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyhook.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: averdon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 21:57:59 by averdon           #+#    #+#             */
/*   Updated: 2022/11/18 00:35:09 by averdon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/so_long.h"

void	item_collected(t_vars *vars, char *actual_place)
{
	t_double_list	*buffer_2;

	*actual_place = '0';
	ft_printf("you collected one collectible\n");
	vars->player->nb_collectibles++;
	buffer_2 = vars->map_chunk;
	while (vars->map_chunk)
	{
		ft_double_lstclear(&((t_tilemap *)(vars->map_chunk->content))->map,
			del);
		vars->map_chunk = vars->map_chunk->next;
	}
	ft_double_lstclear(&buffer_2, del);
	vars->map_chunk = divise_map(vars);
	if (vars->player->nb_collectibles == vars->nb_collectibles)
	{
		display_map(vars);
		mlx_put_image_to_window(vars->mlx, vars->window,
			vars->player->sprite[vars->player->frame + vars->player->side],
			vars->player->x % 640, vars->player->y % 640);
	}
}

void	check_action_on_map(t_vars *vars)
{
	t_double_list	*buffer;
	int				x;
	int				y;

	buffer = vars->map;
	y = 0;
	x = 0;
	while (y < (vars->player->y / 64))
	{
		y++;
		buffer = buffer->next;
	}
	while (x < vars->player->x / 64)
		x++;
	if (((char *)(buffer->content))[x] == 'C')
		item_collected(vars, &((char *)(buffer->content))[x]);
	else if (((char *)(buffer->content))[x] == 'E')
		check_collectibles_to_exit(vars);
}

void	display_nb_action(t_vars *vars)
{
	char	*str;
	int		i;

	i = 0;
	str = ft_itoa(vars->player->nb_move);
	if (ft_strlen(str) > 4)
	{
		free(str);
		str = ft_strdup("9999");
	}
	while (str[i])
	{
		mlx_put_image_to_window(vars->mlx, vars->window,
			vars->array_ptr_sprite[14 + str[i] - 48], 660 + i * 70, 64);
		i++;
	}
	free(str);
}

void	modify_display(t_vars *vars)
{
	if (vars->game_finish)
		return ;
	ft_printf("Number of move : %d\n", vars->player->nb_move);
	if (vars->player->old_point->x / 640 != (vars->player->x / 640))
		display_map(vars);
	if (vars->player->old_point->y / 640 != (vars->player->y / 640))
		display_map(vars);
	mlx_put_image_to_window(vars->mlx, vars->window,
		vars->player->sprite[vars->player->frame + vars->player->side],
		vars->player->x % 640, vars->player->y % 640);
	display_nb_action(vars);
}

int	key_hook(int keycode, t_vars *vars)
{
	t_double_list	*buffer;
	int				x;
	int				y;
	int				value_return;

	if (vars->game_finish)
	{
		check_after_game(keycode, vars);
		return (0);
	}
	buffer = vars->map;
	y = 0;
	x = 0;
	value_return = 0;
	vars->player->old_point->x = vars->player->x;
	vars->player->old_point->y = vars->player->y;
	advance_x_and_y(&y, &x, vars, &buffer);
	value_return = check_key(keycode, vars, buffer, x);
	if (value_return != 0)
		return (0);
	if (key_to_move(keycode) == 1)
		modify_display(vars);
	check_action_on_map(vars);
	return (0);
}
