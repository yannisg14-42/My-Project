/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yannis <yannis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/19 09:48:55 by yannis            #+#    #+#             */
/*   Updated: 2025/12/19 17:57:58 by yannis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

t_list	*ft_lstnew(void *content)
{
	t_list	*new_node;

	new_node = malloc(sizeof(t_list));
	if (!new_node)
		return (NULL);
	new_node->content = content;
	new_node->next = NULL;
	return (new_node);
}
/*
 ft_lstnew create a new node for the linked list by allocating memory with malloc
 then we initiaze content to new_node and new set to a standalone node (NULL)
 then we return a pointer to new_node or NULL if malloc fails
 -> is an operator to access members of a struct through a pointer
 the long way to access content would be (*node).content 
 to dereference the pointer 
 (*node) to access member .content and (*node).next same to access next 
 .  for actual struct and -> for pointer to struct
*/