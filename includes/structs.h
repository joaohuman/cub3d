/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsantana <lsantana@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 23:47:30 by lsantana          #+#    #+#             */
/*   Updated: 2023/07/23 23:47:33 by lsantana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

typedef struct s_text
{
	int			size;
	double		step;
	double		pos;
	int			x;
	int			y;
}				t_text;

typedef struct s_img
{
	void		*img;
	char		*addr;
	int			bits_per_pixel;
	int			line_lenght;
	int			endian;
}				t_img;

typedef struct s_mlx
{
	void		*mlx;
	void		*win;
	void		*img;
	char		*addr;
	int			bits_per_pixel;
	int			line_lenght;
	int			endian;
	t_img		*no;
	t_img		*so;
	t_img		*we;
	t_img		*ea;
	int			set;
}				t_mlx;

typedef struct s_vector
{
	double		x;
	double		y;
}				t_vector;

typedef struct s_struct
{
	int			x;
	int			y;
}				t_struct;

typedef struct s_map
{
	char		**lines;
	char		**map;
	int			fd;
	int			x;
	int			y;
	char		*no;
	char		*so;
	char		*we;
	char		*ea;
	int			floor;
	int			ceil;
	t_vector	pos;
}				t_map;

typedef struct s_player
{
	t_vector	pos;
	t_vector	dir;
	t_vector	plane;
	t_vector	move;
	int			rotate;
	double		ang;
}				t_player;

typedef struct s_ray
{
	double		multiplier;
	t_vector	dir;
	t_vector	cam_pix;
	t_vector	delta_dist;
	t_struct	map;
	int			hit_side;
	t_vector	dist_to_side;
	t_vector	step;
	double		perp_dist;
	double		line_height;
	int			start_line;
	int			end_line;
	double		wall_x;
}				t_ray;

typedef struct s_data
{
	t_mlx		mlx;
	t_map		*map;
	t_player	player;
	t_ray		ray;
	t_text		text;
}				t_data;

#endif