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

typedef struct s_map {
	char	**lines;
	int		fd;
	char	*no;
	char	*so;
	char	*we;
	char	*ea;
	int		floor;
	int	 	ceil;
} t_map;

typedef struct s_data {
	t_mlx		*mlx;
	t_map		*map;
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

int		check_map(t_map *map);
int		create_map(t_map *map);
int		validate_map(t_map *map);

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