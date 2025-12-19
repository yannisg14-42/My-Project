/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yannis <yannis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/19 11:41:21 by yannis            #+#    #+#             */
/*   Updated: 2025/12/19 18:35:54 by yannis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*temp;

	if (!lst || !del)
		return ;
	while (*lst)
	{
		temp = (*lst)->next;
		ft_lstdelone(*lst, del);
		(*lst) = temp;
	}
	*lst = NULL;
}
/*
 ft_lstclear delete the entire list from given node onward
 we loop through all the nodes freeing each one
 before deleting current node we have to save the 
 current pointer thus the use of temp
 otherwise we would loose access of the complete list
 and we set lst to NULL at the end to signal it is empty
*/