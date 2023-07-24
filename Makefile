# Program name
NAME	:= cub3D

# GENERAL OPTIONS
# C Compiler
CC		:=	cc
# Compiler flags
CFLAGS	:=	-Wall -Wextra -Werror -g
# Removal tool
RM		:=	rm -rf


# PROGRAM
# Headers
HEADER_DIR	:=	includes
HEADER		+=
H_INCLUDE	:=	$(addprefix -I, $(HEADER_DIR))

# Source
SRC_DIR		:=	sources
SRC			:= main.c check_errors.c init_data.c calc_dda.c \
        check_map.c check_map_support.c validate_tex_path.c \
        validate_f_c_colors.c validate_f_c_colors_support.c \
        free_all.c moves.c draws.c utils.c texture.c utils_2.c

# Object
OBJ_DIR		:=	obj
OBJ			:=	$(SRC:%.c=$(OBJ_DIR)/%.o)
MLXFLAGS      = -lmlx -lXext -lX11 -lm

# LIBFT
LIBFT_DIR		:=	libs/libft

LIBFT_H_DIR		:=	$(LIBFT_DIR)/inc
LIBFT_H_INC		:=	-I$(LIBFT_H_DIR)

LIBFT_LIB		:=	$(LIBFT_DIR)/libft.a



# Inclusions:
INCLUDE		:=	$(H_INCLUDE) $(LIBFT_H_INC)

# vpath
vpath	%.h		$(HEADER_DIR)
vpath	%.c		$(SRC_DIR)

# -----------------------RULES------------------------------------------------ #
.PHONY: all norm vg clean fclean re

# Creates NAME
all: $(NAME)

# Compiles OBJ and LIBFT_LIB into the program NAME
$(NAME): $(LIBFT_LIB) $(OBJ)
	$(CC) $(CFLAGS) -o $@ $(OBJ) $(LIBFT_LIB) $(INCLUDE) $(MLXFLAGS)

# Compiles SRC into OBJ
$(OBJ): $(OBJ_DIR)/%.o: %.c $(HEADER) | $(OBJ_DIR)
	$(CC) $(CFLAGS) -o $@ -c $< $(INCLUDE)

# Directory making
$(OBJ_DIR):
	@mkdir -p $@

# Libft compiling
$(LIBFT_LIB):
	$(MAKE) -C $(LIBFT_DIR)

# Run program using valgrind
vg: $(SUPP_FILE)
	@$(MAKE)
	valgrind --suppressions=$< --leak-check=full --show-leak-kinds=all ./$(NAME)

# Norm: checks code for norm errors
norm:
	@norminette | grep "Error" | cat
	@$(MAKE) -C $(LIBFT_DIR) norm

# Clean: removes objects' and precompiled headers' directories
clean:
	@$(RM) $(OBJ_DIR) $(SUPP_FILE)
	@$(MAKE) -C $(LIBFT_DIR) clean

# Full clean: same as 'clean', but removes the generated libraries as well
fclean: clean
	$(RM) $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean

# Remake: full cleans and runs 'all' rule
re: fclean all