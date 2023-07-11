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
# define START_OF_MAP 6
# define SUCCESS 0
# define ERROR -1
# define ESC 65307


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
	int hit_side;
	t_vector dist_to_side;
	t_vector step;
	double perp_dist;
	double line_height;
	int start_line;
	int end_line;
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
int		error_msg(char *msg);
void	init_data(t_data *data);
void	init_map(t_map *map);
void	init_mlx(t_mlx *mlx);
double 	discover_multiplier(int pixel);
int		draw(t_data *data);
void 	dist_to_side(t_data *data);
void	perform_dda(t_data *data, t_ray *ray);
int	desenhar(t_data *d);
void calc_line_heigh(t_ray *ray);


int		check_map(t_map *map);
int		create_map(t_map *map);
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

int		ft_str_is_digit(char *str);
int		ft_strlen_matrix(char **str);
int 	how_many_commas(char *line);
int 	num_between_commas(char *line);

#endif