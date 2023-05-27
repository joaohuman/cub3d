/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsantana <lsantana@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 23:19:44 by lsantana          #+#    #+#             */
/*   Updated: 2022/10/16 17:57:33 by lsantana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	index;
	size_t	index_dst;
	size_t	len_src;
	size_t	len_dst;

	index = 0;
	len_src = ft_strlen(src);
	len_dst = ft_strlen(dst);
	index_dst = len_dst;
	if (len_dst < size - 1 && size > 0)
	{
		while (src[index] && len_dst + index < size - 1)
		{
			dst[index_dst] = src[index];
			index++;
			index_dst++;
		}
	}
	if (len_dst >= size)
		len_dst = size;
	dst[index_dst] = '\0';
	return (len_src + len_dst);
}
