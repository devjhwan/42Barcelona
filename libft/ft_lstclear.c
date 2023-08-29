/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwle <junghwle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 14:42:11 by junghwle          #+#    #+#             */
/*   Updated: 2023/05/12 14:42:12 by junghwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*del_node;

	while (*lst)
	{
		del_node = *lst;
		*lst = (*lst)->next;
		ft_lstdelone(del_node, del);
	}
	*lst = NULL;
}
