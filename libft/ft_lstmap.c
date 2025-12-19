/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yannis <yannis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/19 11:47:55 by yannis            #+#    #+#             */
/*   Updated: 2025/12/19 18:42:35 by yannis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_node;
	t_list	*new_list;
	void	*new_content;

	if (!lst || !f || !del)
		return (NULL);
	new_list = NULL;
	while (lst)
	{
		new_content = f(lst->content);
		new_node = ft_lstnew(new_content);
		if (!new_node)
		{
			del(new_content);
			ft_lstclear(&new_list, del);
			return (NULL);
		}
		ft_lstadd_back(&new_list, new_node);
		lst = lst->next;
	}
	return (new_list);
}
/*
 ft_lstmap create a new list by changing 
 each node' content with a function f
 the original list shall not change since we are just creating 
 a copy modified by f
 for each node in the original list we transform content 
 using our f
 then we create a new node with the modified content
 afterward we add the new_node with the new_content to the new_list
 Should any allocation fail we free the failed modified content
 then free the entire neew list
 and finally return NULL, del will handle the clean up upon failure
*/