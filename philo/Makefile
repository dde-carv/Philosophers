# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dde-carv <dde-carv@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/08 10:17:48 by dde-carv          #+#    #+#              #
#    Updated: 2025/04/14 16:14:06 by dde-carv         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			=	philo

INC				=	inc/
SRC_DIR			=	src/
OBJ_DIR			=	obj/

CC				=	@cc
CFLAGS			=	-Wall -Werror -Wextra -g
RM				=	@rm -f

PHILO_DIR		=	$(SRC_DIR)main.c \
					$(SRC_DIR)big_brother.c \
					$(SRC_DIR)philo_init.c \
					$(SRC_DIR)philo_routine.c \
					$(SRC_DIR)philo_utils.c \
					$(SRC_DIR)philo_utils2.c \
					$(SRC_DIR)threads.c

SRCS			=	$(PHILO_DIR)

OBJS			=	$(patsubst $(SRC_DIR)%.c,$(OBJ_DIR)%.o,$(SRCS))

all:	$(NAME)

$(NAME):	$(OBJS)
		@echo "\033[1;32mMake .o and executable.\033[0m"
		@$(CC) $(CFLAGS) -I$(INC) $(OBJS) -o $(NAME)

$(OBJ_DIR)%.o:	$(SRC_DIR)%.c
		@mkdir -p $(@D)
		@$(CC) $(CFLAGS) -I$(INC) -c $< -o $@

clean:
		$(RM) -r $(OBJ_DIR)
		@echo "\033[1;31mClean .o files.\033[0m"

fclean:		clean
		$(RM) $(NAME)
		@echo "\033[1;31mClean executable.\033[0m"

re:			fclean all

.PHONY:		clean fclean re
