# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: twagner <twagner@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/01 15:32:48 by twagner           #+#    #+#              #
#    Updated: 2021/09/11 13:52:30 by twagner          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

################################################################################
#                               PARAMS & COLORS                                #
################################################################################
OS			=  $(shell uname -s)

ifneq (,$(findstring xterm,${TERM}))
	BLACK        := $(shell tput -Txterm setaf 0)
	RED          := $(shell tput -Txterm setaf 1)
	GREEN        := $(shell tput -Txterm setaf 2)
	YELLOW       := $(shell tput -Txterm setaf 3)
	LIGHTPURPLE  := $(shell tput -Txterm setaf 4)
	PURPLE       := $(shell tput -Txterm setaf 5)
	BLUE         := $(shell tput -Txterm setaf 6)
	WHITE        := $(shell tput -Txterm setaf 7)
	RESET		 := $(shell tput -Txterm sgr0)
else
	BLACK        := ""
	RED          := ""
	GREEN        := ""
	YELLOW       := ""
	LIGHTPURPLE  := ""
	PURPLE       := ""
	BLUE         := ""
	WHITE        := ""
	RESET        := ""
endif

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
			  srcs/commons/map.c \
			  srcs/commons/utils.c \
			  srcs/mandatory/hooks.c \
			  srcs/mandatory/move.c \
			  srcs/commons/param.c \
			  srcs/commons/drawing.c

BSRCS		= srcs/bonus/so_long_bonus.c \
			  srcs/commons/map_controler.c \
			  srcs/commons/map.c \
			  srcs/commons/image_utils.c \
			  srcs/commons/utils.c \
			  srcs/bonus/hooks_bonus.c \
			  srcs/bonus/move_bonus.c \
			  srcs/bonus/animations_bonus.c \
			  srcs/bonus/infobar_bonus.c \
			  srcs/commons/drawing.c

OBJS		= $(SRCS:.c=.o)
BOBJS		= $(BSRCS:.c=.o)

################################################################################
#                           EXECUTABLES & LIBRARIES                            #
################################################################################
NAME		= so_long
LFT			= libft.a

ifeq ($(OS), Linux)
	LMLX	= libmlx_Linux.a
else
	LMLX	= 
endif

################################################################################
#                                 DIRECTORIES                                  #
################################################################################
LFTDIR		= libft/
LMLXDIR		= minilibx-linux/
HEADERS		= includes/mandatory/

################################################################################
#                                     FLAGS                                    #
################################################################################
CFLAGS		:= -Wall -Wextra -Werror
LFTFLAGS	:= -L. -lft
BFLAGS		:=

ifeq ($(OS), Linux)
	LMLXFLAGS	:= -L. -lmlx_Linux -L/usr/lib -lXext -lX11 -lm -lz -DLINUX
else
	LMLXFLAGS	:= -lmlx -framework OpenGL -framework AppKit
endif

ifeq ($(DEBUG), true)
	CFLAGS	+= -fsanitize=address -g3 -O0
endif

################################################################################
#                                    RULES                                     #
################################################################################
.c.o:
			@$(CC) $(CFLAGS) $(BFLAGS) -c $< -o $(<:.c=.o) -I$(HEADERS) \
				-I$(LFTDIR) -I$(LMLXDIR)

$(NAME):	$(LMLX) $(LFT) $(OBJS)
			@printf  "$(BLUE)Creating $(RESET) $(YELLOW)[$(NAME)]$(RESET)" 
			@$(CC) $(CFLAGS) $(LMLXFLAGS) $(LFTFLAGS) $(OBJS) -o $(NAME) \
				-I$(HEADERS) -I$(LFTDIR) -I$(LMLXDIR)
			@echo " : $(GREEN)OK !$(RESET)"

all:		$(NAME)

bonus:		HEADERS = includes/bonus/
bonus:		BFLAGS = -DBONUS
bonus:		$(LMLX) $(LFT) $(BOBJS)
			@printf "$(BLUE)Creating $(RESET) $(YELLOW)[$(NAME) (bonus)]$(RESET)" 
			@touch bonus
			@$(CC) $(CFLAGS) $(LMLXFLAGS) $(LFTFLAGS) $(BOBJS) -o $(NAME) \
				-I$(HEADERS) -I$(LFTDIR) -I$(LMLXDIR)
			@echo " : $(GREEN)OK !$(RESET)"

clean:
			@printf "$(BLUE)Cleaning $(RESET) $(YELLOW)[objects & libraries]$(RESET)"
			@$(RM) $(OBJS) $(BOBJS) $(LFT) $(LMLX) bonus
			@echo " : $(GREEN)OK !$(RESET)"

fclean:		clean
			@printf "$(BLUE)Cleaning $(RESET) $(YELLOW)[executable(s)]$(RESET)"
			@$(RM) $(NAME)
			@echo " : $(GREEN)OK !$(RESET)"

re:			fclean all

$(LFT):	
			@printf "$(BLUE)Compiling$(RESET) $(YELLOW)[$(LFT)]$(RESET)"
			@make -s -C $(LFTDIR)
			@make clean -s -C $(LFTDIR)
			@mv $(LFTDIR)$(LFT) .
			@echo " : $(GREEN)OK !$(RESET)"

$(LMLX):		
			@printf "$(BLUE)Compiling$(RESET) $(YELLOW)[$(LMLX)]$(RESET)"
			@make -s -C $(LMLXDIR)
			@mv $(LMLXDIR)$(LMLX) .
			@make clean -s -C $(LMLXDIR)
			@echo " : $(GREEN)OK !$(RESET)"

.PHONY:		all clean fclean c.o re
