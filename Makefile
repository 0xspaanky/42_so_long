# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: smounafi <smounafi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/19 15:55:31 by smounafi          #+#    #+#              #
#    Updated: 2023/01/03 03:14:45 by smounafi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

CC = cc

CFLAGS = -Wall -Wextra -Werror

SRC = get_next_line_utils.c ft_split.c check_map.c errors.c ft_substr.c ft_itoa.c get_x_and_y.c get_map.c get_next_line.c so_long.c put_img.c flood_fill.c ft_printf.c ft_printf_fcns_II.c ft_printf_fcns.c close_win.c u_d_l_r_moves.c col_token.c up_down_helper.c left_right_helper.c put_img_helper.c

RM = rm -f

OBJ = $(SRC:.c=.o)

all: $(NAME)

bonus : all

$(NAME) : $(OBJ)
	$(CC) $(CFLAGS) $^ -lmlx -framework OpenGL -framework AppKit -o $@
clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all