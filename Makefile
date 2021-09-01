# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: twagner <twagner@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/01 15:32:48 by twagner           #+#    #+#              #
#    Updated: 2021/09/01 16:16:49 by twagner          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

######################################
#              COMMANDS              #
######################################
RM			= rm -f
CC			= gcc
AR			= ar rcs

######################################
#              SOURCES               #
######################################
SRCS		= srcs/mandatory/so_long.c \
			  srcs/commons/map/map_controler.c \
			  srcs/commons/map/map_utils.c \
			  srcs/commons/actions/actions_utils.c \
			  srcs/commons/sprites/sprites_utils.c \
			  srcs/commons/commons.c \
			  srcs/mandatory/loop/loop_utils.c \
			  srcs/mandatory/actions/move.c

BSRCS		= srcs/bonus/so_long_bonus.c \
			  srcs/commons/map/map_controler.c \
			  srcs/commons/map/map_utils.c \
			  srcs/commons/actions/actions_utils.c \
			  srcs/commons/sprites/sprites_utils.c \
			  srcs/commons/commons.c \
			  srcs/bonus/loop/loop_utils_bonus.c \
			  srcs/bonus/actions/move_bonus.c

OBJS		= $(SRCS:.c=.o)
BOBJS		= $(BSRCS:.c=.o)

#######################################
#       EXECUTABLES & LIBRARIES       #
#######################################
NAME		= so_long
LIB			= libft.a
LIBHEADER	= libft.h

#######################################
#             DIRECTORIES             #
#######################################
LIBDIR		= libft/
HEADERS		= includes/

######################################
#               FLAGS                #
######################################
CFLAGS		= -Wall -Wextra -Werror
MLXFLAGS	= -lmlx -framework OpenGL -framework AppKit
LIBFLAGS	= -L. -lft
BFLAGS		=

ifeq ($(DEBUG), true)
	CFLAGS	+= -fsanitize=address -g3 -O0
endif

#######################################
#                RULES                #
#######################################
.c.o:
			$(CC) $(CFLAGS) $(BFLAGS) -c $< -o $(<:.c=.o) -I$(HEADERS) -I$(LIBDIR)

$(NAME):	$(LIB) $(OBJS)
			$(CC) $(CFLAGS) $(MLXFLAGS) $(LIBFLAGS) $(OBJS) -o $(NAME) -I$(HEADERS)

all:		$(NAME)

bonus:		HEADERS = includes_bonus/
bonus:		BFLAGS = -DBONUS
bonus:		$(LIB) $(BOBJS)
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
