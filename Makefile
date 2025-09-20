# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mtran-nh <mtran-nh@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/08/12 18:34:03 by mtran-nh          #+#    #+#              #
#    Updated: 2025/09/20 22:17:56 by mtran-nh         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
NAME_BONUS = checker

CC = cc 
CFLAGS = -Wall -Wextra -Werror

SRC_DIR = src/
BONUS_DIR = bonus_src/
LIBFT_DIR = Libft/
INCLUDES = -I include/ -I $(LIBFT_DIR)

SRC = 	$(SRC_DIR)input.c \
		$(SRC_DIR)main.c \
		$(SRC_DIR)sort.c \
		$(SRC_DIR)utils.c \
		$(SRC_DIR)push.c \
		$(SRC_DIR)reverse_rotate.c \
		$(SRC_DIR)rotate.c \
		$(SRC_DIR)swap.c \
		$(SRC_DIR)push_swap.c \
		$(SRC_DIR)helper.c \
		$(SRC_DIR)moves.c

BONUS_SRC = $(BONUS_DIR)main_bonus.c \
			$(BONUS_DIR)gnl.c \
			$(SRC_DIR)input.c \
			$(SRC_DIR)sort.c \
			$(SRC_DIR)utils.c \
			$(SRC_DIR)push.c \
			$(SRC_DIR)reverse_rotate.c \
			$(SRC_DIR)rotate.c \
			$(SRC_DIR)swap.c \
			$(SRC_DIR)push_swap.c \
			$(SRC_DIR)helper.c \
			$(SRC_DIR)moves.c

OBJS = $(SRC:.c=.o)
BONUS_OBJS = $(BONUS_SRC:.c=.o)

LIBFT = $(LIBFT_DIR)libft.a

all: $(NAME)

bonus: $(NAME) $(NAME_BONUS)

$(LIBFT):
	@$(MAKE) -C $(LIBFT_DIR)

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)

$(NAME_BONUS): $(BONUS_OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(BONUS_OBJS) $(LIBFT) -o $(NAME_BONUS)

$(SRC_DIR)%.o: $(SRC_DIR)%.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(BONUS_DIR)%.o: $(BONUS_DIR)%.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm -f $(OBJS) $(BONUS_OBJS)
	@$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME) $(NAME_BONUS)
	@$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all bonus clean fclean re
