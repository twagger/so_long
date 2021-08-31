SRCS			= srcs/so_long.c \
				  srcs/map/map_controler.c \
				  srcs/map/map_creator.c \
				  srcs/map/map_utils.c \
				  srcs/game/game_loop.c \
				  srcs/commons/commons.c

OBJS			= $(SRCS:.c=.o)

NAME			= so_long

LIB				= libft.a

LIBHEADER		= libft.h

LIBDIR			= libft/

HEADERS			= includes/

CFLAGS			= -Wall -Wextra -Werror -fsanitize=address -g3 -O0

RM				= rm -f

CC				= gcc

AR				= ar rcs

.c.o:
				$(CC) $(CFLAGS) -c $< -o $(<:.c=.o) -I$(HEADERS) -I$(LIBDIR)

$(NAME):		$(LIB) $(OBJS)
				$(CC) $(CFLAGS) $(OBJS) -o $(NAME) -I$(HEADERS) -L. -lft -lmlx -framework OpenGL -framework AppKit

all:			$(NAME)

clean:
				$(RM) $(OBJS) $(LIB)

fclean:			clean
				$(RM) $(NAME)

re:				fclean all

$(LIB):	
				make bonus -C $(LIBDIR)
				make clean -C $(LIBDIR)
				mv $(LIBDIR)$(LIB) .

.PHONY:			all clean fclean c.o re
