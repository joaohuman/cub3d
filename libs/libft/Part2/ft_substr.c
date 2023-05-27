/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsantana <lsantana@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 20:28:04 by lsantana          #+#    #+#             */
/*   Updated: 2022/10/16 17:58:46 by lsantana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*dup;
	size_t	i;
	int		true_len;

	true_len = ft_strlen(s) - start;
	i = 0;
	if (start > ft_strlen(s))
		true_len = 0;
	else if (len < (size_t)true_len)
		true_len = len;
	dup = (char *)malloc(sizeof(char) * true_len + 1);
	if (!dup)
		return (NULL);
	while (s[i] && i < (size_t)true_len)
	{
		*(char *)(dup + i) = *(char *)(s + start);
		i++;
		start++;
	}
	dup[i] = '\0';
	return (dup);
}
