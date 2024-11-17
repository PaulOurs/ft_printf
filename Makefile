# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: paubello <paubello@student.42lyon.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/17 04:20:46 by paubello          #+#    #+#              #
#    Updated: 2024/11/17 06:51:08 by paubello         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS_DIR = ./srcs/
OBJS_DIR = ./objs/

SRCS = $(SRCS_DIR)ft_putchar.c \
		$(SRCS_DIR)ft_putstr.c \
		$(SRCS_DIR)ft_puthex.c \
		$(SRCS_DIR)ft_putnbr.c \
		$(SRCS_DIR)ft_putunbr.c \
		$(SRCS_DIR)ft_strlen.c \
		ft_printf.c \

OBJS = $(addprefix $(OBJS_DIR),$(notdir $(SRCS:.c=.o)))

NAME = libftprintf.a

CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -rf


$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

$(OBJS_DIR)%.o: $(SRCS_DIR)%.c
	@mkdir -p $(OBJS_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJS_DIR)%.o: %.c
	@mkdir -p $(OBJS_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

clean:
	$(RM) $(OBJS_DIR)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
