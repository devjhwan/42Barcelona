/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwle <junghwle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 19:55:42 by junghwle          #+#    #+#             */
/*   Updated: 2023/08/21 18:51:35 by junghwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static t_buff	*ft_newbuffer(int fd)
{
	t_buff	*buff;

	buff = (t_buff *)malloc(sizeof(t_buff));
	if (buff == NULL)
		return (NULL);
	buff->b = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (buff->b == NULL)
	{
		free(buff);
		return (NULL);
	}
	buff->b[0] = '\0';
	buff->curlen = 0;
	buff->maxlen = BUFFER_SIZE + 1;
	buff->lasti = 0;
	buff->fd = fd;
	buff->next = NULL;
	return (buff);
}

t_buff	*ft_setbuffer(t_buff **blist, int fd)
{
	t_buff	*tmp;

	if (*blist == NULL)
	{
		*blist = ft_newbuffer(fd);
		return (*blist);
	}
	tmp = *blist;
	while (tmp->fd != fd && tmp->next != NULL)
		tmp = tmp->next;
	if (tmp->fd == fd)
		return (tmp);
	tmp->next = ft_newbuffer(fd);
	return (tmp->next);
}

void	*ft_freebuffer(t_buff **blist, int fd)
{
	t_buff	*prev;
	t_buff	*del;

	if (*blist == NULL)
		return (NULL);
	prev = NULL;
	del = *blist;
	if (del->fd == fd)
		*blist = del->next;
	else
	{
		while (del->fd != fd)
		{
			prev = del;
			del = del->next;
		}
		prev->next = del->next;
	}
	free(del->b);
	free(del);
	return (NULL);
}

void	*ft_realloc(void *p, size_t oldsize, size_t newsize)
{
	char	*s;
	char	*_p;
	size_t	i;

	if (p == NULL)
		return (NULL);
	s = (char *)malloc(sizeof(char) * newsize);
	if (s == NULL)
		return (NULL);
	_p = (char *)p;
	i = 0;
	while (i < oldsize)
	{
		s[i] = _p[i];
		i++;
	}
	return (s);
}
