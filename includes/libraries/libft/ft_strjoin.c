/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: averdon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 09:37:17 by averdon           #+#    #+#             */
/*   Updated: 2022/11/04 04:46:52 by averdon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		len_s1;
	int		len_s2;
	char	*new_s;

	if (!s1 || !s2)
		return (NULL);
	len_s1 = 0;
	len_s2 = 0;
	while (s1[len_s1])
		len_s1++;
	while (s2[len_s2])
		len_s2++;
	new_s = malloc(len_s1 + len_s2 + 1);
	if (!new_s)
		return (NULL);
	len_s1 = -1;
	len_s2 = -1;
	while (s1[++len_s1])
		new_s[len_s1] = s1[len_s1];
	while (s2[++len_s2])
		new_s[len_s1 + len_s2] = s2[len_s2];
	new_s[len_s1 + len_s2] = '\0';
	return (new_s);
}
