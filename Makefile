## ########################################################################## ##
##                                                                            ##
##                                                        :::      ::::::::   ##
##   Makefile                                           :+:      :+:    :+:   ##
##                                                    +:+ +:+         +:+     ##
##   By: mnouchet <mnouchet@student.42.fr>          +#+  +:+       +#+        ##
##                                                +#+#+#+#+#+   +#+           ##
##   Created: 2023/01/06 22:19:57 by mnouchet          #+#    #+#             ##
##   Updated: 2023/01/28 17:47:52 by marvin           ###   ########.fr       ##
##                                                                            ##
## ########################################################################## ##

NAME		:= fdf

## ########################################################################## ##
#   INGREDIENTS																  ##
## ########################################################################## ##
# LIBS			libraries to be used
# LIBS_TARGET	libraries to be built
# INCS			header file locations
#
# SRCS_DIR		source directory
# SRCS			source files
#
# BUILD_DIR		build directory
# OBJS			object files
#
# CC			compiler
# CFLAGS		compiler flags
# CPPFLAGS		preprocessor flags
# LDFLAGS		linker flags
# LDLIBS		libraries name

LIBS		:= ft mlx
LIBS_TARGET	:= libs/libft/libft.a	\
			   libs/mlx/mlx.a

INCS		:= includes				\
			   libs/libft/includes	\
			   libs/mlx

SRCS_DIR	:= srcs
SRCS		:= main.c				\
			   draws/line.c			\
			   draws/pixel.c		\
			   draws/node.c			\
			   hooks/renders.c		\
			   hooks/inputs.c		\
			   types/color.c		\
			   types/node.c			\
			   types/map.c

SRCS		:= $(SRCS:%=$(SRCS_DIR)/%)

BUILD_DIR	:= .build
OBJS		:= $(SRCS:$(SRCS_DIR)/%.c=$(BUILD_DIR)/%.o)

CC			:= cc
CFLAGS		:= -g3 -Wall -Wextra -Werror	
CPPFLAGS    := $(INCS:%=-I%)
LDFLAGS     := $(addprefix -L,$(dir $(LIBS_TARGET))) -L /opt/X11/lib
LDLIBS      := $(addprefix -l,$(LIBS)) -lX11 -lXext

## ########################################################################## ##
#   UTENSILS																  ##
## ########################################################################## ##
# RM			force remove
# MAKEFLAGS		make flags
# DIR_UP		duplicate directory tree

RM          := rm -f
MAKEFLAGS   += --silent --no-print-directory
DIR_DUP     = mkdir -p $(@D)

## ########################################################################## ##
#   RECIPES																	  ##
## ########################################################################## ##
# all			default goal
# $(NAME)		link .o -> archive
# %.o			compilation .c -> .o
# clean			remove .o
# fclean		remove .o + binary
# re			remake default goal

$(LIBS_TARGET):
	echo "→ Compiling $(@F)"
	$(MAKE) -C $(@D)

$(BUILD_DIR)/%.o: $(SRCS_DIR)/%.c
	echo "→ Compiling $<"
	$(DIR_DUP)
	$(CC) $(CFLAGS) $(CPPFLAGS) -c $< -o $@ 

all: $(NAME)

$(NAME): $(OBJS) $(LIBS_TARGET)
	$(CC) $(LDFLAGS) $(OBJS) $(LDLIBS) -o $(NAME)
	echo "\033[0;32m✓ $@ READY"

clean:
	echo "→ Removing objects"
	$(RM) $(OBJS)

fclean: clean
	echo "→ Removing binaries"
	$(RM) $(NAME)

re: fclean all

.PHONY: re
