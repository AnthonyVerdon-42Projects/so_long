/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: averdon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 15:24:49 by averdon           #+#    #+#             */
/*   Updated: 2022/11/18 01:05:11 by averdon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include"structures.h"
# include "define.h"
# include"libraries/libft/libft.h"
# include"libraries/minilibx/mlx.h"
# include"../srcs/game/game.h"
# include "../srcs/parsing/parsing.h"
# include<X11/X.h>
# include<fcntl.h>
# include<time.h>

int				main(int argc, char **argv);
void			del(void *content);

#endif
