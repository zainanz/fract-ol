# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: zali <zali@student.42lisboa.com>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/22 14:08:09 by zali              #+#    #+#              #
#    Updated: 2025/05/22 14:16:40 by zali             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Werror -Wextra
MINILIBX_LINK = -L. -lmlx_Linux -lXext -lX11
MATH_LINK = -lm
NAME = fractol
HEADER = fractol.h
SRC = main.c color.c render.c math_utils.c str_utils.c init.c event_init.c
OBJ = ${SRC:.c=.o}
MINILIB = minilibx-linux
CLONE_REPO = https://github.com/42paris/minilibx-linux.git 
LIB = libmlx_Linux.a
RUN_MAKE = ./minilibx-linux/${LIB} 

all: ${NAME}

${NAME}: ${OBJ} ${LIB}
	${CC} ${CFLAGS} ${OBJ} ${MATH_LINK} ${MINILIBX_LINK} -o ${NAME}

quick: make_lib ${NAME}
 
${MINILIB}: 
	git clone ${CLONE_REPO}

${LIB}: ${RUN_MAKE}
	cp ./${MINILIB}/${LIB} .

${RUN_MAKE}:
	make all -C ./minilibx-linux/

make_lib: ${MINILIB} ${LIB}

%.o: %.c ${HEADER}
	${CC} ${CFLAGS} -c $< -o $@

clean: 
	rm -f ${OBJ} ${NAME}
fclean:
	rm -f ${OBJ} ${NAME} ${LIB}

re: fclean ${NAME}
