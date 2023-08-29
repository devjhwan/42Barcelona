/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstpopfirst.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwle <junghwle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 16:28:06 by junghwle          #+#    #+#             */
/*   Updated: 2023/08/21 16:29:41 by junghwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstpopfirst(t_list **list)
{
	t_list	*pop;

	if (*list == NULL)
		return (NULL);
	pop = *list;
	*list = pop->next;
	pop->next = NULL;
	return (pop);
}
