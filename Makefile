# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: junghwle <junghwle@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/03 14:32:42 by junghwle          #+#    #+#              #
#    Updated: 2023/09/03 21:37:25 by junghwle         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=libft.a

SRCDIR=.
OBJDIR=objs
SRCS=
OBJS=$(patsubst %.c, $(OBJDIR)/%.o, $(SRCS))
DEPS=$(OBJS:.o=.d)

INCLUDE=-I.
CC=cc
CFLAGS=-Wall -Werror -Wextra
DEPFLAGS=-MMD
COMPILE.c=$(CC) $(DEPFLAGS) $(CFLAGS) $(INCLUDE) -c -o
EXTRAFLAGS=
LIBRARIES=

all: $(OBJDIR) $(NAME)

$(NAME): $(OBJS) Makefile
	$(CC) $(CFLAGS) $(EXTRAFLAGS) -o $@ $(OBJS) $(LIBRARIES)
	echo "()COMPILING $@"

$(OBJDIR)/%.o: $(SRCDIR)/%.c Makefile 
	$(COMPILE.c) $@ $<
	echo "()COMPILING $@"

$(OBJDIR): Makefile
	mkdir -p $@

clean:
	rm -rf $(OBJDIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

-include $(DEPS)

.PHONY: all clean fclean re
.SILENT:
