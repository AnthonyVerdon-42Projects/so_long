/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structures.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: averdon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 15:46:33 by averdon           #+#    #+#             */
/*   Updated: 2023/05/28 15:17:31 by averdon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTURES_H

# define STRUCTURES_H

# include"libraries/srcs_double_list/ft_double_list.h"

typedef struct s_components
{
	int	start;
	int	exit;
	int	collectibles;
}	t_components;

typedef struct s_point
{
	int	x;
	int	y;
}	t_point;

typedef struct s_player {
	void	**sprite;
	int		x;
	int		y;
	t_point	*old_point;
	int		nb_collectibles;
	int		nb_move;
	int		frame;
	int		side;
}				t_player;

typedef struct s_tilemap {
	int				x;
	int				y;
	t_double_list	*map;
}	t_tilemap;

typedef struct s_vars {
	void			*mlx;
	void			*window;
	t_player		*player;
	t_double_list	*map;
	t_double_list	*map_chunk;
	t_double_list	*positions_enemies;
	void			**array_ptr_sprite;
	int				nb_columns;
	int				nb_rows;
	int				nb_collectibles;
	int				frame_enemy;
	int				game_finish;
	int				argc;
	char			**argv;
}	t_vars;

#endif
