#ifndef STRUCST_H
# define STRUCST_H

typedef struct s_mlx {
	void	*mlx;
	void	*win;
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_lenght;
	int		endian;
	int		set;
}	t_mlx;

typedef struct s_vector{
	double	x;
	double	y;
} t_vector;

typedef struct s_map {
	char	**lines;
	char	**map;
	int		fd;
	int		x;
	int		y;
	char	*no;
	char	*so;
	char	*we;
	char	*ea;
	int		floor;
	int	 	ceil;
	t_vector pos;
} t_map;

typedef struct s_player {
	t_vector	pos;
	t_vector	dir;
	t_vector	plane;
	t_vector	move;
	int			rotate;
} t_player;

typedef struct s_ray {
	double multiplier;
	t_vector dir;
	t_vector cam_pix;
	t_vector delta_dist;
	int hit_side;
	t_vector dist_to_side;
	t_vector step;
	double perp_dist;
	double line_height;
	int start_line;
	int end_line;
	double wall_x;
} t_ray;

typedef struct s_data {
	t_mlx		mlx;
	t_map		*map;
	t_player	player;
	t_ray		ray;
} t_data;

#endif