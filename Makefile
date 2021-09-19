# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: twagner <twagner@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/01 15:32:48 by twagner           #+#    #+#              #
#    Updated: 2021/09/19 21:32:28 by twagner          ###   ########.fr        #
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
SRCS		= srcs/commons/map_controler.c \
			  srcs/commons/map.c \
			  srcs/commons/utils.c \
			  srcs/commons/drawing.c \
			  srcs/mandatory/so_long.c \
			  srcs/mandatory/param.c \
			  srcs/mandatory/hooks.c \
			  srcs/mandatory/move.c \

BSRCS		= srcs/commons/map_controler.c \
			  srcs/commons/map.c \
			  srcs/commons/utils.c \
			  srcs/commons/drawing.c \
			  srcs/bonus/so_long_bonus.c \
			  srcs/bonus/param_bonus.c \
			  srcs/bonus/hooks_bonus.c \
			  srcs/bonus/mobs_bonus.c \
			  srcs/bonus/move_bonus.c \
			  srcs/bonus/move_utils_bonus.c \
			  srcs/bonus/infoscore_bonus.c \
			  srcs/bonus/endgame_bonus.c \
			  srcs/bonus/image_bonus.c

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
ADDFLAGS	:=

ifeq ($(OS), Linux)
	LMLXFLAGS	:= -L. -lmlx_Linux -L/usr/lib -lXext -lX11 -lm -lz
	ADDFLAGS	:= -DLINUX -DX11
	ifneq ($(SPEED),)
		ADDFLAGS	+= -DSPEED=$(SPEED)
	else
		ADDFLAGS	+= -DSPEED=15
	endif
else
	LMLXFLAGS	:= -lmlx -framework OpenGL -framework AppKit
	ADDFLAGS	:= -DMAC
	ifneq ($(SPEED),)
		ADDFLAGS	+= -DSPEED=$(SPEED)
	else
		ADDFLAGS	+= -DSPEED=3
	endif
endif

ifeq ($(DEBUG), true)
	CFLAGS	+= -fsanitize=address -g3 -O0
endif

ifeq ($(HALLOWEEN), true)
	ADDFLAGS	+= -DHALLOWEEN
endif

################################################################################
#                                    RULES                                     #
################################################################################
.c.o:
			@$(CC) $(CFLAGS) $(ADDFLAGS) -c $< -o $(<:.c=.o) -I$(HEADERS) \
				-I$(LFTDIR) -I$(LMLXDIR)

$(NAME):	$(LMLX) $(LFT) $(OBJS)
			@printf  "$(BLUE)Creating $(RESET) $(YELLOW)[$(NAME)]$(RESET)" 
			@$(CC) $(CFLAGS) $(OBJS) -o $(NAME) -I$(HEADERS) -I$(LFTDIR) -I$(LMLXDIR) $(LMLXFLAGS) $(LFTFLAGS)
			@echo " : $(GREEN)OK !$(RESET)"

all:		$(NAME)

bonus:		HEADERS = includes/bonus/
bonus:		ADDFLAGS += -DBONUS
bonus:		$(LMLX) $(LFT) $(BOBJS)
			@printf "$(BLUE)Creating $(RESET) $(YELLOW)[$(NAME) (bonus)]$(RESET)" 
			@touch bonus
			@$(CC) $(CFLAGS) $(BOBJS) -o $(NAME) -I$(HEADERS) -I$(LFTDIR) -I$(LMLXDIR) $(LMLXFLAGS) $(LFTFLAGS)
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
