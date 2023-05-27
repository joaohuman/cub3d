/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsantana <lsantana@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 23:09:06 by lsantana          #+#    #+#             */
/*   Updated: 2022/10/16 17:58:43 by lsantana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static size_t	ft_find_start(const char *s1, const char *set)
{
	size_t	start;
	size_t	i;

	start = 0;
	i = 0;
	while (s1[start] && set[i])
	{
		while (s1[start] != set[i] && set[i])
			i++;
		if (s1[start] == set[i])
		{
			start++;
			i = 0;
		}
	}
	return (start);
}

static size_t	ft_find_end(const char *s1, const char *set, size_t end)
{
	size_t	i;

	i = 0;
	while (end > 0 && set[i])
	{
		while (set[i] && s1[end] != set[i])
			i++;
		if (s1[end] == set[i])
		{
			end--;
			i = 0;
		}
	}
	return (end);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	end;
	char	*new_str;
	size_t	start;

	end = ft_strlen(s1);
	start = ft_find_start(s1, set);
	end = ft_find_end(s1, set, end);
	new_str = ft_substr(s1, start, (end - start) + 1);
	if (!new_str)
		return (NULL);
	return (new_str);
}
