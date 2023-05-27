/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsantana <lsantana@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 00:30:29 by lsantana          #+#    #+#             */
/*   Updated: 2022/10/16 17:58:22 by lsantana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static char	**ft_free_all(char **mat, int i);

static int	ft_check_size(char const *s, char c) ///oi meu nome é lucas // 'i' //
{                                           
	int	i;
	int	count;		

	i = 0;
	count = 0;
	while (s[i])
	{
		while (s[i] == c && s[i])
			i++;
		if (s[i])
		{
			while (s[i] != c && s[i])
				i++;
			count++;
		}
	}
	if (!s[i])
		count++;
	return (count);
}

static char	*word_count(char *s, char c, int *size)
{
	*size = 0;
	if (!*s)
		return (NULL);
	while (*s == c)
	{
		s++;
	}
	if (!s[0])
		return (NULL);
	while (s[*size] != c && s[*size])
	{
		*size += 1;
	}
	return (s);
}

static char	**make_matrix(char *s, char c, char **mat)
{
	int	size_word;
	int	posn_str;
	int	i;

	size_word = 0;
	posn_str = 0;
	s = word_count((char *)s, c, &size_word);
	while (s)
	{
		i = 0;
		mat[posn_str] = (char *)ft_calloc(sizeof(char), (size_word + 1));
		if (!mat[posn_str])
			return (ft_free_all(mat, posn_str - 1));
		while (size_word > 0)
		{
			mat[posn_str][i] = *s++;
			i++;
			size_word--;
		}
		posn_str++;
		s = word_count(s, c, &size_word);
	}
	mat[posn_str] = 0;
	return (mat);
}

static char	**ft_free_all(char **mat, int i)
{
	while (i >= 0)
	{
		free(mat[i]);
		i--;
	}
	free(mat);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	char	**mat;
	int		i;

	i = 0;
	mat = (char **)ft_calloc(sizeof(char *), ft_check_size(s, c));
	if (!mat)
		return (NULL);
	mat = make_matrix((char *)s, c, mat);
	return (mat);
}
