# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mtran-nh <mtran-nh@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/08/12 18:34:03 by mtran-nh          #+#    #+#              #
#    Updated: 2025/09/11 13:29:45 by mtran-nh         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

CC = cc 
CFLAGS = -Wall -Wextra -Werror

SRC_DIR = src/
LIBFT_DIR = Libft/
INCLUDES = -I include/ -I $(LIBFT_DIR)

SRC = 	$(SRC_DIR)input.c \
		$(SRC_DIR)main.c \
		$(SRC_DIR)radix_sort.c \
		$(SRC_DIR)sort.c \
		$(SRC_DIR)utils.c \
		$(SRC_DIR)push.c \
		$(SRC_DIR)reverse_rotate.c \
		$(SRC_DIR)rotate.c \
		$(SRC_DIR)swap.c 

OBJS = $(SRC:.c=.o)
LIBFT = $(LIBFT_DIR)libft.a

all: $(NAME)

$(LIBFT):
	@$(MAKE) -C $(LIBFT_DIR)

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm -f $(OBJS)
	@$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME)
	@$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re
