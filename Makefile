SRCS			= srcs/so_long.c \
				  srcs/map_controler.c

OBJS			= $(SRCS:.c=.o)

NAME			= so_long

LIB				= libft.a

LIBHEADER		= libft.h

LIBDIR			= libft/

HEADERS			= includes/

CFLAGS			= -Wall -Wextra -Werror

RM				= rm -f

CC				= gcc

AR				= ar rcs

.c.o:
				$(CC) $(CFLAGS) -c $< -o $(<:.c=.o) -I$(HEADERS) -I$(LIBDIR)

$(NAME):		$(LIB) $(OBJS)
				$(CC) $(CFLAGS) $(OBJS) -o $(NAME) -I$(HEADERS) -L. -lft

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
