/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yannis <yannis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/19 09:56:02 by yannis            #+#    #+#             */
/*   Updated: 2025/12/19 18:35:26 by yannis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (!lst || !new)
		return ;
	new->next = *lst;
	*lst = new;
}
/*
 ft_lstadd_front add a node at the begining of the lst
 it takes a double ptr because we modify
  where the head (first nod of the linked list) point
 first we make new->next point to the cureent head
 then we updat the head so it point to a new node
 example: [new] -> [old_head] -> [B] -> NULL
*/