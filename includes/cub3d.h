#ifndef CUB3D_H
# define CUB3D_H

# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <math.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <unistd.h>
# include <mlx.h>
# include <libft.h>
# include <stdbool.h>

# define WIDTH 640
# define HEIGHT 480
# define SPRITE_SIZE 64
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
} t_player;

typedef struct s_ray {
	double multiplier;
	t_vector dir;
	t_vector cam_pix;
	t_vector delta_dist;
	bool hit_side;
	t_vector dist_to_side;
	t_vector step;
} t_ray;


typedef struct s_data {
	t_mlx		mlx;
	t_map		*map;
	t_player	player;
	t_ray		ray;
} t_data;

int		check_errors(int argc, char *argv[]);
int		check_extension(char *arg, char *extension);
int		check_file(char *file_name);
void	init_window(t_mlx *f);
void	my_mlx_pixel_put(t_mlx *data, int x, int y, int color);
void	init_data(t_data *data);
void	init_map(t_map *map);
void	init_mlx(t_mlx *mlx);
double 	discover_multiplier(int pixel);
void 	draw(t_data *data);
void 	dist_to_side(t_data *data);
void	perform_dda(t_data *data, t_ray *ray);



#endif