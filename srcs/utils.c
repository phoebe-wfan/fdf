/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wfan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 18:13:26 by wfan              #+#    #+#             */
/*   Updated: 2023/09/15 18:13:28 by wfan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

float	absolute(float nbr)
{
	if (nbr < 0)
		return (-nbr);
	else
		return (nbr);
}

float	max(float a, float b)
{
	if (a > b)
		return (a);
	else
		return (b);
}

float	min(float a, float b)
{
	if (a < b)
		return (a);
	else
		return (b);
}

size_t	ft_split_count(const char *s, char c)
{
	size_t	i;
	size_t	prev;
	size_t	next;
	size_t	size;
	size_t	counter;

	i = 0;
	prev = i;
	next = i;
	counter = 0;
	while (1)
	{
		if (s[i] == c || s[i] == '\0')
			next = i;
		size = next - prev;
		if (size > 1 || (size == 1 && s[i - 1] != c))
			counter++;
		if (s[i] == '\0')
			break ;
		prev = next;
		i++;
	}
	return (counter);
}
