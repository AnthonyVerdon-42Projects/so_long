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

# include"sources/structures.h"
# include "sources/define.h"
# include"sources/libft/libft.h"
# include"sources/minilibx/mlx.h"
# include"game/game.h"
# include "parsing/parsing.h"
# include<X11/X.h>
# include<fcntl.h>
# include<time.h>

int				main(int argc, char **argv);
void			del(void *content);

#endif
