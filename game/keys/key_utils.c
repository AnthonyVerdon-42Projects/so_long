/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: averdon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 00:33:22 by averdon           #+#    #+#             */
/*   Updated: 2022/11/18 00:35:36 by averdon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

int	check_echap(t_vars *vars)
{
	close_window(vars);
	return (0);
}

void	check_after_game(int keycode, t_vars *vars)
{
	int				argc;
	char			**argv;

	if (keycode == ENTER)
	{
		argc = vars->argc;
		argv = vars->argv;
		destroy_and_free(vars);
		main(argc, argv);
	}
	else if (keycode == ECHAP)
		close_window(vars);
}

void	advance_x_and_y(int *y, int *x, t_vars *vars, t_double_list **buffer)
{
	while ((*y) < (vars->player->y / 64))
	{
		(*y)++;
		*buffer = (*buffer)->next;
	}
	while ((*x) < vars->player->x / 64)
		(*x)++;
}

int	key_to_move(int keycode)
{
	if (keycode == 'w' || keycode == 'a' || keycode == 's' || keycode == 'd'
		|| keycode == 65361 || keycode == 65362 || keycode == 65363
		|| keycode == 65364)
		return (1);
	return (0);
}

void	check_collectibles_to_exit(t_vars *vars)
{
	if (vars->player->nb_collectibles == vars->nb_collectibles)
	{
		mlx_put_image_to_window(vars->mlx, vars->window,
			vars->array_ptr_sprite[26], 173, 105);
		vars->game_finish = 1;
		ft_printf("you win\n");
	}
}
