SRCS	= ./Part1/ft_isalpha.c ./Part1/ft_isdigit.c ./Part1/ft_isalnum.c \
			./Part1/ft_isascii.c ./Part1/ft_isprint.c ./Part1/ft_strlen.c \
			./Part1/ft_memset.c ./Part1/ft_bzero.c ./Part1/ft_memcpy.c \
			./Part1/ft_memmove.c ./Part1/ft_toupper.c ./Part1/ft_tolower.c \
			./Part1/ft_strchr.c ./Part1/ft_strrchr.c ./Part1/ft_strncmp.c \
            ./Part1/ft_memchr.c ./Part1/ft_memcmp.c ./Part1/ft_strnstr.c \
			./Part1/ft_strlcpy.c ./Part1/ft_strlcat.c ./Part1/ft_strdup.c \
			./Part1/ft_calloc.c ./Part1/ft_atoi.c \
			./Part2/ft_substr.c ./Part2/ft_strjoin.c ./Part2/ft_strmapi.c \
			./Part2/ft_striteri.c ./Part2/ft_putchar_fd.c ./Part2/ft_putstr_fd.c\
			./Part2/ft_putendl_fd.c ./Part2/ft_putnbr_fd.c ./Part2/ft_strtrim.c \
			./Part2/ft_itoa.c ./Part2/ft_split.c ./Part2/get_next_line.c

OBJS	= $(SRCS:.c=.o)

SRCS_BONUS		= ./Bonus/ft_lstnew.c ./Bonus/ft_lstadd_front.c ./Bonus/ft_lstsize.c \
				./Bonus/ft_lstlast.c ./Bonus/ft_lstadd_back.c ./Bonus/ft_lstdelone.c \
				./Bonus/ft_lstclear.c ./Bonus/ft_lstiter.c ./Bonus/ft_lstmap.c

OBJS_BONUS	= $(SRCS_BONUS:.c=.o)

NAME	= libft.a
CC = cc
CFLAGS	+=	-Wall -Werror -Wextra

all: ${NAME}
	
${NAME}: ${OBJS} ${HEADER}
	ar rcs ${NAME} ${OBJS}

clean:
	rm -f ${OBJS} ${OBJS_BONUS}

fclean:	clean
	rm -f ${NAME}

re:	fclean all

bonus: ${OBJS_BONUS} ${HEADER}
	ar rcs ${NAME} ${OBJS_BONUS}

.PHONY:	all clean fclean re