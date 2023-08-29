/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwle <junghwle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 20:38:45 by junghwle          #+#    #+#             */
/*   Updated: 2023/08/23 09:54:45 by junghwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_join(char **strarr)
{
	char	*str;
	int		len;
	int		i;

	i = 0;
	len = 1;
	while (strarr[i] != NULL)
		len += ft_strlen(strarr[i++]);
	str = (char *)malloc(sizeof(char) * len);
	if (str == NULL)
	{
		free(strarr);
		return (NULL);
	}
	str[0] = '\0';
	i = 0;
	while (strarr[i] != NULL)
		ft_strlcat(str, strarr[i++], len);
	free(strarr);
	return (str);
}

char	*ft_strjoin(int count, ...)
{
	va_list	ap;
	int		i;
	char	**strarr;

	va_start(ap, count);
	strarr = (char **)malloc(sizeof(char *) * (count + 1));
	if (strarr == NULL)
		return (NULL);
	i = 0;
	while (i < count)
		strarr[i++] = va_arg(ap, char *);
	strarr[i] = NULL;
	va_end(ap);
	return (ft_join(strarr));
}
