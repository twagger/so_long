SRCS		= srcs/so_long.c \
			  srcs/map/map_controler.c \
			  srcs/map/map_creator.c \
			  srcs/map/map_utils.c \
			  srcs/game/game_loop.c \
			  srcs/game/game_utils.c \
			  srcs/actions/move_up.c \
			  srcs/actions/actions_utils.c \
			  srcs/commons/commons.c

OBJS		= $(SRCS:.c=.o)

NAME		= so_long

LIB			= libft.a

LIBHEADER	= libft.h

LIBDIR		= libft/

HEADERS		= includes/

CFLAGS		= -Wall -Wextra -Werror -fsanitize=address -g3 -O0

RM			= rm -f

CC			= gcc

AR			= ar rcs

.c.o:
			$(CC) $(CFLAGS) -c $< -o $(<:.c=.o) -I$(HEADERS) -I$(LIBDIR)

$(NAME):	$(LIB) $(OBJS)
			$(CC) $(CFLAGS) $(OBJS) -o $(NAME) -I$(HEADERS) -L. -lft -lmlx -framework OpenGL -framework AppKit

all:		$(NAME)

clean:
			$(RM) $(OBJS) $(LIBDIR)$(LIB)

fclean:		clean
			$(RM) $(NAME)

re:			fclean all

$(LIB):	
			@echo ">> Compiling libft..."
			@make -s -C $(LIBDIR)
			@make clean -s -C $(LIBDIR)
			@echo ">> libft compiled!"
			@mv $(LIBDIR)$(LIB) .

.PHONY:		all clean fclean c.o re
