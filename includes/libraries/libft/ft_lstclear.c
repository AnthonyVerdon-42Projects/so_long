/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: averdon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 13:08:08 by averdon           #+#    #+#             */
/*   Updated: 2022/11/07 23:09:06 by averdon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*buffer;
	t_list	*next;

	if (!lst || !del)
		return ;
	buffer = *lst;
	while (buffer != NULL)
	{
		next = buffer->next;
		ft_lstdelone(buffer, del);
		buffer = next;
	}
	*lst = NULL;
}
