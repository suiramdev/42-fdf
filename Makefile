## ########################################################################## ##
##                                                                            ##
##                                                        :::      ::::::::   ##
##   Makefile                                           :+:      :+:    :+:   ##
##                                                    +:+ +:+         +:+     ##
##   By: mnouchet <mnouchet>                        +#+  +:+       +#+        ##
##                                                +#+#+#+#+#+   +#+           ##
##   Created: 2022/12/02 01:20:18 by mnouchet          #+#    #+#             ##
##   Updated: 2022/12/17 16:04:34 by marvin           ###   ########.fr       ##
##                                                                            ##
## ########################################################################## ##

NAME = fdf

SOURCES_DIR = srcs
SOURCES = main.c utils/memory.c utils/read.c utils/string.c \
		  renders/draw/pixel.c renders/color.c renders/map.c \
		  loaders/map.c

INCLUDES = -I./includes -I./libs
LIBRARIES = -L/usr/X11/lib -lX11 -lXext -L./libs -lmlx

OBJECTS = $(addprefix $(SOURCES_DIR)/, $(SOURCES:%.c=%.o))

CC = cc -Wall -Werror -Wextra

%.o: %.c
	@$(CC) $(INCLUDES) -c $< -o $@
	@echo "→ Compiling $<"

$(NAME): $(OBJECTS)
	@$(CC) $(INCLUDES) $(OBJECTS) $(LIBRARIES) -o $(NAME)
	@echo "\033[0;32m✓ READY"

clean:
	@rm -rf $(OBJECTS)
	@echo "→ Removing objects"

fclean: clean
	@rm -rf $(NAME)
	@echo "→ Removing binaries"

all: $(NAME)

re: fclean all

.PHONY = clean fclean all re
