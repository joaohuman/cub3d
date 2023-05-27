/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsantana <lsantana@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 02:07:51 by lsantana          #+#    #+#             */
/*   Updated: 2022/10/16 17:58:04 by lsantana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static int	ft_check_size(int n)
{
	int	i;

	i = 1;
	if (n < 0)
		i++;
	while (n / 10)
	{
		n /= 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	char	*new_str;
	int		i;

	i = ft_check_size(n);
	if (n <= -2147483648)
		return (ft_strdup("-2147483648"));
	new_str = (char *)malloc(sizeof(char) * ft_check_size(n) + 1);
	if (!new_str)
		return (NULL);
	if (n < 0)
	{
		new_str[0] = '-';
		n *= -1;
	}
	new_str[i] = 0;
	while (n > 9)
	{
		new_str[--i] = ((n % 10) + '0');
		n /= 10;
	}
	if (n <= 9)
		new_str[i - 1] = n + '0';
	return (new_str);
}
