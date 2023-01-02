## ########################################################################## ##
##                                                                            ##
##                                                        :::      ::::::::   ##
##   Makefile                                           :+:      :+:    :+:   ##
##                                                    +:+ +:+         +:+     ##
##   By: mnouchet <mnouchet>                        +#+  +:+       +#+        ##
##                                                +#+#+#+#+#+   +#+           ##
##   Created: 2022/12/02 01:20:18 by mnouchet          #+#    #+#             ##
##   Updated: 2022/12/31 14:30:52 by marvin           ###   ########.fr       ##
##                                                                            ##
## ########################################################################## ##

NAME = fdf

SOURCES_DIR = srcs
SOURCES = main.c renders/draw/pixel.c renders/color.c renders/map.c loaders/map.c

OBJECTS = $(addprefix $(SOURCES_DIR)/, $(SOURCES:%.c=%.o))

CC = cc
CFLAGS = -g3 -Wall -Werror -Wextra -Iincludes

INCLUDES = -I./includes -I./libs/libft/includes -I./libs/mlx

LIBRARIES = -L/usr/X11/lib -lX11 -lXext -L./libs/libft -lft -L./libs/mlx -lmlx

%.o: %.c
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@
	@echo "→ Compiling $<"

libs:
	@$(MAKE) re -C ./libs/libft
	@$(MAKE) all -C ./libs/mlx
	@echo "→ Compiling libraries"

$(NAME): libs $(OBJECTS)
	@$(CC) $(CFLAGS) $(INCLUDES) $(LIBRARIES) $(OBJECTS) -o $(NAME)
	@echo "\033[0;32m✓ $(NAME) READY"

clean:
	@rm -rf $(OBJECTS)
	@echo "→ Removing objects"

fclean: clean
	@rm -rf $(NAME)
	@echo "→ Removing binaries"

all: $(NAME)

re: fclean all

.PHONY: libs clean fclean all re
