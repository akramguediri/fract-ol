# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aguediri <aguediri@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/26 00:53:39 by aguediri          #+#    #+#              #
#    Updated: 2023/07/31 00:37:07 by aguediri         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Compiler and flags
CC := gcc
CFLAGS := -Wall -Wextra -Werror
LDFLAGS := -lglfw -L"/Users/aguediri/.brew/opt/glfw/lib/" -framework Cocoa -framework OpenGL -framework IOKit #-fsanitize=address -g 

# Directories
SRCDIR := .
OBJDIR := obj
INCDIR := include
LIBDIR := MLX42/build

# Source files and object files
SRC := fractol.c julia.c mandelbrot.c ft_atof.c ft_extra.c
OBJ := $(patsubst %.c, $(OBJDIR)/%.o, $(SRC))

# Target executable
TARGET := fractol

# Default target
all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(LDFLAGS) -o $@ $^ -L$(LIBDIR) -lmlx42

$(OBJDIR)/%.o: $(SRCDIR)/%.c | $(OBJDIR)
	$(CC) $(CFLAGS) -I$(INCDIR) -c -o $@ $<

$(OBJDIR):
	mkdir -p $(OBJDIR)

clean:
	rm -rf $(OBJDIR)

fclean: clean
	rm -f $(TARGET)

re: fclean all

.PHONY: all clean fclean re
