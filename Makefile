# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/27 21:32:25 by jodufour          #+#    #+#              #
#    Updated: 2022/05/20 00:55:08 by jodufour         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

######################################
#              COMMANDS              #
######################################
CC		=	clang
LINK	=	clang
MKDIR	=	mkdir -p
RM		=	rm -rf

######################################
#             EXECUTABLE             #
######################################
NAME	=	micro_paint.out

#######################################
#             DIRECTORIES             #
#######################################
SRC_DIR	=	srcs/
OBJ_DIR	=	objs/
PRV_DIR	=	private/

######################################
#            SOURCE FILES            #
######################################
SRC		=	\
			${addprefix ctx/,						\
				${addprefix zone/,					\
					mp_ctx_zone_fill_rect_empty.c	\
					mp_ctx_zone_fill_rect_full.c	\
					mp_ctx_zone_fill.c				\
					mp_ctx_zone_print.c				\
				}									\
				mp_ctx_clear.c						\
				mp_ctx_get.c						\
				mp_ctx_init.c						\
			}										\
			${addprefix utils/,						\
				mp_isdigit.c						\
				mp_isspace.c						\
				mp_line_len.c						\
				mp_memdel.c							\
				mp_skip_float.c						\
				mp_skip_integer.c					\
				mp_skip_spaces.c					\
				mp_strchr.c							\
				mp_strjoin.c						\
				mp_strlen.c							\
			}										\
			main.c									\
			mp_err_msg.c							\
			mp_file_content_check.c					\
			mp_file_content_get.c

######################################
#            OBJECT FILES            #
######################################
OBJ		=	${SRC:.c=.o}
OBJ		:=	${addprefix ${OBJ_DIR}, ${OBJ}}

DEP		=	${OBJ:.o=.d}

#######################################
#                FLAGS                #
#######################################
CFLAGS	=	-c
CFLAGS	+=	-Wall -Wextra -Werror
CFLAGS	+=	-MMD -MP
CFLAGS	+=	-I${PRV_DIR}

LDFLAGS	=	

ifeq (${DEBUG}, 1)
	CFLAGS	+=	-g
endif

#######################################
#                RULES                #
#######################################
.PHONY:	all clean fclean re fre

${NAME}: ${OBJ}
	${LINK} $^ ${LDFLAGS} ${OUTPUT_OPTION}

all: ${NAME}

-include ${DEP}

${OBJ_DIR}%.o: ${SRC_DIR}%.c
	@${MKDIR} ${@D}
	${CC} $< ${CFLAGS} ${OUTPUT_OPTION}

clean:
	${RM} ${OBJ_DIR}

fclean:
	${RM} ${OBJ_DIR} ${NAME}

re: clean all

fre: fclean all

-include ${HOME}/Templates/mk_files/coffee.mk
-include ${HOME}/Templates/mk_files/norm.mk
