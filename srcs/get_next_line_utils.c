/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wfan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 17:14:09 by wfan              #+#    #+#             */
/*   Updated: 2022/12/23 15:49:14 by wfan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

size_t	ft_strlen_1(char *str)
{
	size_t	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

size_t	ft_strlen_2(char *str)
{
	size_t	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] != '\n' && str[i])
		i++;
	if (str[i] == '\n')
		i++;
	return (i);
}

size_t	ft_strlcpy_2(char *dst, char *src, size_t dstsize)
{
	size_t	i;

	i = 0;
	if (!src)
		return (0);
	if (dstsize == 0)
		return (ft_strlen_1(src));
	while (src[i] && i < (dstsize - 1))
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (ft_strlen_1(src));
}

char	*ft_strjoin_2(char *line, char *buffer)
{
	char	*s;

	if (!line)
	{
		line = malloc(1);
		if (!line)
			return (NULL);
		line[0] = 0;
	}
	if (!line || !buffer)
		return (NULL);
	s = (char *)malloc(ft_strlen_1(line) + ft_strlen_1(buffer) + 1);
	if (!s)
	{
		free(line);
		return (NULL);
	}
	ft_strlcpy_2(s, line, ft_strlen_1(line) + 1);
	ft_strlcpy_2(s + ft_strlen_1(line), buffer, ft_strlen_1(buffer) + 1);
	free(line);
	return (s);
}
