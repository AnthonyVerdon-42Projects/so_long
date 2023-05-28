/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_argument.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: averdon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 14:22:35 by averdon           #+#    #+#             */
/*   Updated: 2022/11/17 11:11:17 by averdon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	check_argument(int argc, char **argv)
{
	if (argc < 2)
	{
		ft_printf("Error\nno argument\n");
		exit (0);
	}
	if (argc > 2)
	{
		ft_printf("Error\ntoo much arguments\n");
		exit (0);
	}
	if (ft_strlen(argv[1]) == 4 || argv[1][ft_strlen(argv[1]) - 5] == '/'
		|| ft_strncmp(&argv[1][ft_strlen(argv[1]) - 4], ".ber", 4))
	{
		ft_printf("Error\nfilename invalid\n");
		exit (0);
	}
}
