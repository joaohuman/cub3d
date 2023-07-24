/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_f_c_colors_support.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsantana <lsantana@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 23:49:28 by lsantana          #+#    #+#             */
/*   Updated: 2023/07/23 23:49:29 by lsantana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	ft_str_is_digit(char *str)
{
	while (*str)
		if (ft_isdigit(*str++) == 0)
			return (0);
	return (1);
}

int	ft_strlen_matrix(char **str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	how_many_commas(char *line)
{
	int	i;
	int	comma;

	i = 0;
	comma = 0;
	while (line[i])
	{
		if (line[i] == ',')
			comma++;
		i++;
	}
	if (i == comma)
		return (-1);
	return (comma);
}

int	num_between_commas(char *line)
{
	int		len;
	int		i;
	char	**split_test;

	i = 0;
	len = 0;
	split_test = ft_split(line, ',');
	if (ft_strlen_matrix(split_test) != 3)
	{
		free_matrix(split_test);
		return (-1);
	}
	while (split_test[i])
	{
		len = ft_strlen(split_test[i]);
		if (len < 1 || len > 3)
		{
			free_matrix(split_test);
			return (-1);
		}
		i++;
	}
	free_matrix(split_test);
	return (0);
}
