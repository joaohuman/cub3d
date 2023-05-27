/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsantana <lsantana@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 23:27:31 by lsantana          #+#    #+#             */
/*   Updated: 2022/10/16 17:57:24 by lsantana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	*ft_memset(void *str, int c, size_t count)
{
	size_t	i;

	i = 0;
	if (!str)
		return (NULL);
	while (i < count)
	{
		*(char *)(str + i) = (char)c;
		i++;
	}
	return (str);
}
