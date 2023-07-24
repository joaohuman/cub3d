/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsantana <lsantana@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 23:49:02 by lsantana          #+#    #+#             */
/*   Updated: 2023/07/23 23:49:03 by lsantana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	main(int argc, char *argv[])
{
	t_data	data;

	if (check_errors(argc, argv))
		return (-1);
	init_data(&data);
	data.map->fd = open(argv[1], O_RDWR);
	if (check_map(data.map, &data.player))
		return (free_check_map(&data));
	init_mlx(&data.mlx);
	ft_set_texture(&data);
	mlx_loop_hook(data.mlx.mlx, draw, &data);
	mlx_hook(data.mlx.win, 02, 1L << 0, &key_pressed_down, &data);
	mlx_hook(data.mlx.win, 03, 1L << 1, &key_no_pressed, &data);
	mlx_hook(data.mlx.win, 17, 1L << 17, &ft_close, &data);
	mlx_loop(data.mlx.mlx);
	free_all(&data);
	return (0);
}
