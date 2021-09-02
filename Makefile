# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: twagner <twagner@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/01 15:32:48 by twagner           #+#    #+#              #
#    Updated: 2021/09/02 17:25:27 by twagner          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

################################################################################
#                                 COMMANDS                                     #
################################################################################
RM			= rm -f
CC			= gcc
AR			= ar rcs

################################################################################
#                                 SOURCES                                      #
################################################################################
SRCS		= srcs/mandatory/so_long.c \
			  srcs/commons/map_controler.c \
			  srcs/commons/map_utils.c \
			  srcs/commons/actions_utils.c \
			  srcs/commons/image_utils.c \
			  srcs/commons/utils.c \
			  srcs/mandatory/hooks.c \
			  srcs/mandatory/move.c

BSRCS		= srcs/bonus/so_long_bonus.c \
			  srcs/commons/map_controler.c \
			  srcs/commons/map_utils.c \
			  srcs/commons/actions_utils.c \
			  srcs/commons/image_utils.c \
			  srcs/commons/utils.c \
			  srcs/bonus/hooks_bonus.c \
			  srcs/bonus/move_bonus.c \
			  srcs/bonus/animations_bonus.c \
			  srcs/bonus/infobar_bonus.c \
			  srcs/bonus/drawing_bonus.c

OBJS		= $(SRCS:.c=.o)
BOBJS		= $(BSRCS:.c=.o)

################################################################################
#                           EXECUTABLES & LIBRARIES                            #
################################################################################
NAME		= so_long
LIB			= libft.a
LIBHEADER	= libft.h

################################################################################
#                                 DIRECTORIES                                  #
################################################################################
LIBDIR		= libft/
HEADERS		= includes/mandatory/

################################################################################
#                                     FLAGS                                    #
################################################################################
CFLAGS		= -Wall -Wextra -Werror
MLXFLAGS	= -lmlx -framework OpenGL -framework AppKit
LIBFLAGS	= -L. -lft
BFLAGS		=

ifeq ($(DEBUG), true)
	CFLAGS	+= -fsanitize=address -g3 -O0
endif

################################################################################
#                                    RULES                                     #
################################################################################
.c.o:
			$(CC) $(CFLAGS) $(BFLAGS) -c $< -o $(<:.c=.o) -I$(HEADERS) -I$(LIBDIR)

$(NAME):	$(LIB) $(OBJS)
			$(CC) $(CFLAGS) $(MLXFLAGS) $(LIBFLAGS) $(OBJS) -o $(NAME) -I$(HEADERS)

all:		$(NAME)

bonus:		HEADERS = includes/bonus/
bonus:		BFLAGS = -DBONUS
bonus:		$(LIB) $(BOBJS) #ne recompile pas les commons avec le bon .h > A gerer
			@touch bonus
			$(CC) $(CFLAGS) $(MLXFLAGS) $(LIBFLAGS) $(BOBJS) -o $(NAME) -I$(BHEADERS)

clean:
			$(RM) $(OBJS) $(BOBJS) $(LIB) bonus

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
