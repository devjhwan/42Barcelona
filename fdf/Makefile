# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: junghwle <junghwle@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/03 14:32:42 by junghwle          #+#    #+#              #
#    Updated: 2023/09/04 18:46:45 by junghwle         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=fdf

SRCDIR=source
OBJDIR=objs
SRCS=fdf.c free_mlx.c fdf_key_hook.c fdf_mouse_hook.c
OBJS=$(patsubst %.c, $(OBJDIR)/%.o, $(SRCS))
DEPS=$(OBJS:.o=.d)

INCLUDE=-Iinclude -Ilibft -Iminilibx_macos
CC=cc
CFLAGS=-Wall -Werror -Wextra
DEPFLAGS=-MMD
COMPILE.c=$(CC) $(DEPFLAGS) $(CFLAGS) $(INCLUDE) -c -o
EXTRA_FLAGS=-Lminilibx_macos -lmlx \
		   	-framework OpenGl -framework AppKit
LIBRARIES=libft/libft.a minilibx_macos/libmlx.a

all: $(OBJDIR) $(NAME)

$(NAME): $(OBJS) Makefile
	make -C libft
	make -C minilibx_macos
	$(CC) $(CFLAGS) $(EXTRA_FLAGS) -o $@ $(OBJS) $(LIBRARIES)
	echo "(FDF) COMPILING $@"

$(OBJDIR)/%.o: $(SRCDIR)/%.c Makefile 
	$(COMPILE.c) $@ $<
	echo "(FDF) COMPILING $@"

$(OBJDIR): Makefile
	mkdir -p $@

clean:
	make -C libft fclean
	make -C minilibx_macos clean
	rm -rf $(OBJDIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

-include $(DEPS)

.PHONY: all clean fclean re
.SILENT:
