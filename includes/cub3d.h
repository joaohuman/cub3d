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

typedef struct s_texture {
	char	*no;
	char	*so;
	char	*we;
	char	*ea;
	int		floor;
	int	 	ceil;
} t_texture;

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

typedef struct s_data {
	t_mlx		*mlx;
	t_texture	*text;
} t_data;

int		check_errors(int argc, char *argv[]);
int		check_extension(char *arg, char *extension);
int		check_file(char *file_name);
char	*get_next_line(int fd);
void	init_window(t_mlx *f);
void	my_mlx_pixel_put(t_mlx *data, int x, int y, int color);

#endif