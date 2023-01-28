NAME=	so_long
NAMEB = so_long_bonus

cc=	cc
CFLAGS=	-Wall -Wextra -Werror

AF=    check_map.c   \
so_long.c \
ft_split.c    \
get_next_line_utils.c	\
get_next_line.c \
move.c	\
ft_itoa.c	\
utils1.c	\
utils2.c	\
utils3.c	\
utils4.c	\
no_move.c	\
path.c

BONUS=    bonus/check_map_bonus.c   \
bonus/so_long_bonus.c \
bonus/ft_split_bonus.c    \
bonus/get_next_line_utils_bonus.c	\
bonus/get_next_line_bonus.c \
bonus/move_bonus.c	\
bonus/ft_itoa_bonus.c	\
bonus/utils1_bonus.c	\
bonus/utils2_bonus.c	\
bonus/utils3_bonus.c	\
bonus/utils4_bonus.c	\
bonus/utils5_bonus.c	\
bonus/no_move_bonus.c	\
bonus/path_bonus.c \
bonus/enmie.c \
bonus/move_enemie.c

OBJ=    $(AF:.c=.o)
OBJB=    $(BONUS:.c=.o)

all:    $(NAME)

$(NAME):    $(OBJ)
	$(cc) -lmlx -framework OpenGL -framework AppKit $(CFLAGS) $(OBJ) -o $(NAME)

bonus:    $(OBJB)
	$(cc) -lmlx -framework OpenGL -framework AppKit $(CFLAGS) $(OBJB) -o $(NAMEB)
clean:
	rm -f $(OBJ) $(OBJB)

fclean:    clean
	rm -f $(NAME) $(NAMEB)

re: fclean all
