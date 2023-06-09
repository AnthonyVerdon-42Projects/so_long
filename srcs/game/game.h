/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: averdon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 15:29:26 by averdon           #+#    #+#             */
/*   Updated: 2022/11/18 00:56:51 by averdon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_H

# define GAME_H

# include "enemies/enemies.h"
# include "keys/keys.h"
# include "display_map/display_map.h"
# include "set_up_game/set_up_game.h"

int				calculate_columns(t_double_list *map);
int				calculate_collectibles(t_double_list **map);
int				calculate_rows(t_double_list *map);
void			destroy_and_free(t_vars *vars);
int				animations(t_vars *vars);
int				animation_and_movement(t_vars *vars);

#endif
