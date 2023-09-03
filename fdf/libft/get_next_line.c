/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwle <junghwle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 19:55:54 by junghwle          #+#    #+#             */
/*   Updated: 2023/08/21 18:51:21 by junghwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

ssize_t	ft_buffchr(t_buff *buff, int c)
{
	char	*s;
	ssize_t	i;

	s = buff->b;
	i = buff->lasti;
	while (s[i] != '\0')
	{
		if (s[i] == (char)c)
			return (i);
		i++;
	}
	buff->lasti = i;
	return (-1);
}

char	*ft_flushbuffer(t_buff *buff, ssize_t bpos)
{
	char	*ret;
	ssize_t	i;

	if (bpos < 0)
		return (NULL);
	ret = (char *)malloc(sizeof(char) * (bpos + 2));
	if (ret != NULL)
	{
		i = -1;
		while (++i < bpos + 1)
			ret[i] = buff->b[i];
		ret[i] = '\0';
		i = 0;
		while (buff->b[i + bpos + 1] != '\0')
		{
			buff->b[i] = buff->b[i + bpos + 1];
			i++;
		}
		buff->b[i] = '\0';
		buff->curlen -= bpos + 1;
		buff->lasti = 0;
	}
	return (ret);
}

int	ft_writebuffer(t_buff *buff)
{
	char	*tmp;
	ssize_t	count;

	if (buff->curlen + BUFFER_SIZE + 1 > buff->maxlen)
	{
		tmp = (char *)ft_realloc \
				(buff->b, buff->maxlen, buff->maxlen * 2);
		free(buff->b);
		buff->b = tmp;
		buff->maxlen *= 2;
		if (buff->b == NULL)
			return (-1);
	}
	count = read(buff->fd, &(buff->b[buff->curlen]), BUFFER_SIZE);
	if (count < 0)
		return (-1);
	buff->curlen += count;
	buff->b[buff->curlen] = '\0';
	return (count);
}

char	*ft_read_file(t_buff *buff)
{
	ssize_t	count;
	ssize_t	bpos;
	char	*ret;

	ret = NULL;
	count = 1;
	bpos = ft_buffchr(buff, '\n');
	ret = ft_flushbuffer(buff, bpos);
	while (count > 0 && ret == NULL)
	{
		count = ft_writebuffer(buff);
		if (buff->b == NULL)
			return (NULL);
		bpos = ft_buffchr(buff, '\n');
		ret = ft_flushbuffer(buff, bpos);
	}
	if (count == -1)
		return (NULL);
	if (ret == NULL)
		ret = ft_flushbuffer(buff, buff->curlen - 1);
	return (ret);
}

char	*get_next_line(int fd)
{
	static t_buff	*blist;
	t_buff			*buff;
	char			*ret;

	if (fd < 0 && BUFFER_SIZE <= 0)
		return (NULL);
	buff = ft_setbuffer(&blist, fd);
	if (buff == NULL)
		return (NULL);
	ret = ft_read_file(buff);
	if (ret == NULL)
		ft_freebuffer(&blist, fd);
	return (ret);
}
