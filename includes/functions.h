/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsantana <lsantana@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 23:48:06 by lsantana          #+#    #+#             */
/*   Updated: 2023/07/23 23:48:07 by lsantana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FUNCTIONS_H
# define FUNCTIONS_H

# include "./structs.h"

int		check_errors(int argc, char *argv[]);
int		check_extension(char *arg, char *extension);
int		check_file(char *file_name);

void	init_window(t_mlx *f);
void	my_mlx_pixel_put(t_mlx *data, int x, int y, int color);
int		error_msg(char *msg);
void	init_data(t_data *data);
void	init_map(t_map *map);
void	init_mlx(t_mlx *mlx);
double	discover_multiplier(int pixel);
int		draw(t_data *data);
void	dist_to_side(t_data *data);
void	perform_dda(t_data *data, t_ray *ray);
int		desenhar(t_data *d);
void	calc_line_heigh(t_ray *ray, t_player *player);
int		rotate(double *x, double *y, double angle);
int		key_no_pressed(int key, t_data *d);
int		key_pressed_down(int key, t_data *d);
int		ft_close(t_data *s);
void	disc_player_pos(char **map, t_player *player);
void	draw_image(t_data *data, int i);
void	draw_minimapa(t_data *data);
void	draw_square(t_mlx *mlx, int x, int y, int color);
int		check_collision(t_data *d, double x, double y);
void	ft_get_play_ang(char c, t_player *p);
int		ft_mlx_pixel_get(t_img *mlx, int x, int y);
int		get_direction(t_data *d);
int		ft_set_texture(t_data *d);
t_img	*ft_mlx_texture_get(void *mlx, char *file);
int		check_collision(t_data *d, double x, double y);
void	rotate_player(t_data *d);
void	pixel_added(t_data *d);

int		check_map(t_map *map, t_player *p);
int		create_map(t_map *m, t_player *p);
int		validate_chars(t_map *map);
int		validate_map(t_map *map);

int		just_one_player(char *players_allowed, char c, int flag);
int		validate_single_player(t_map *map);
int		check_around_char(int i, int j, t_map *map);
int		validate_map_borders(t_map *map);

int		validate_tex_path(t_map *map);
int		assign_tex_path(char **tex, char *path);
int		is_valid_path(t_map *map);
int		all_tex_path_hav_been_set(t_map *map);

int		validate_floor_ceil_colors(t_map *map);
int		assign_color(char c, char *line, t_map *map);
int		validate_and_assign(char **rgb_split, int *rgb, int i);
int		define_color(char c, t_map *map, int *rgb);

void	free_all(t_data *data);
void	free_matrix(char **matrix);
int		free_check_map(t_data *data);

int		ft_str_is_digit(char *str);
int		ft_strlen_matrix(char **str);
int		how_many_commas(char *line);
int		num_between_commas(char *line);

#endif