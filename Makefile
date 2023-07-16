NAME				=	cub3d

OBJ_DIR				=	./obj
OBJS				=	$(SRCS:%.c=$(OBJ_DIR)/%.o)

HEADER_PATH			=	./includes
HEADER_FILES		=	cub3d.h

SRCS				=	$(SOURCES)

CC					=	cc

SOURCES				=	main.c check_errors.c init_data.c calc_dda.c check_map.c check_map_support.c validate_tex_path.c validate_f_c_colors.c validate_f_c_colors_support.c free_all.c moves.c draws.c utils.c

IFLAGS				=	-I $(HEADER_PATH)
CFLAGS				=	-Wall -Wextra -Werror -g

MLX 				= 	./libs/libmlx.a
LIBFT				=   ./libs/libft.a
MLXFLAGS 			= 	-Imlx -Lmlx -lXext -lX11 -lm
DIRS 				=	. sources
VPATH				=	$(addprefix ./sources/, $(DIRS))
VPATH				+=	$(HEADER_PATH)


all: $(NAME)

$(NAME): $(OBJ_DIR) $(OBJS)
	$(CC) $(CFLAGS) $(IFLAGS) -o $@ $(OBJS) $(MLX) $(MLXFLAGS) $(LIBFT)

$(OBJ_DIR)/%.o: %.c $(HEADER_FILES) Makefile | $(OBJ_DIR)
	@$(CC) $(CFLAGS) $(IFLAGS) -c $< -o $@

$(OBJ_DIR):
	mkdir -p $@

clean:
	rm -rf obj

fclean: clean
	rm -rf $(NAME)

re:	fclean all