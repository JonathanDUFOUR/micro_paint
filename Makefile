# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/27 21:32:25 by jodufour          #+#    #+#              #
#    Updated: 2021/09/27 22:44:12 by jodufour         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

######################################
#              COMMANDS              #
######################################
CC		=	clang -c -o
LINK	=	clang -o
MKDIR	=	mkdir -p
RM		=	rm -rf

######################################
#             EXECUTABLE             #
######################################
NAME	=	micro_paint

#######################################
#             DIRECTORIES             #
#######################################
SRC_DIR	=	srcs/
OBJ_DIR	=	objs/
INC_DIR	=	
PRV_DIR	=	private/

#######################################
#              LIBRARIES              #
#######################################

######################################
#            SOURCE FILES            #
######################################
SRC		=	\
			${addprefix ctx/,	\
				mp_ctx_clear.c	\
				mp_ctx_get.c	\
				mp_ctx_init.c	\
				mp_ctx_print.c	\
			}					\
			main.c				\
			mp_err_msg.c

######################################
#            OBJECT FILES            #
######################################
OBJ		=	${SRC:.c=.o}
OBJ		:=	${addprefix ${OBJ_DIR}, ${OBJ}}

DEP		=	${OBJ:.o=.d}

#######################################
#                FLAGS                #
#######################################
CFLAGS	=	-Wall -Wextra #-Werror
CFLAGS	+=	-MMD -MP
CFLAGS	+=	-I${PRV_DIR}

LDFLAGS	=	

ifeq (${DEBUG}, 1)
	CFLAGS	+=	-g
endif

#######################################
#                RULES                #
#######################################
${NAME}:	${OBJ}
	${LINK} $@ $^ ${LDFLAGS}

all:	${NAME}

-include ${DEP}

${OBJ_DIR}%.o:	${SRC_DIR}%.c
	@${MKDIR} ${@D}
	${CC} $@ ${CFLAGS} $<

clean:
	${RM} ${OBJ_DIR}

fclean:
	${RM} ${OBJ_DIR} ${NAME}

re:	fclean all

coffee:
	@echo         '                                              '
	@echo -e '\e[5m                   "   "                      \e[0m'
	@echo -e '\e[5m                  " " " "                     \e[0m'
	@echo -e '\e[5m                 " " " "                      \e[0m'
	@echo         '         _.-==="-"""""-"===-._                '
	@echo         '        |=___   "~"~"~"   ___=|=,.            '
	@echo         '        |    """======="""    |  \\           '
	@echo         '        |                     |   ||          '
	@echo         '        |                     |   ||          '
	@echo         '        |                     |   ||          '
	@echo         '        |                     |   ||          '
	@echo         '        |                     |  //           '
	@echo         '         \                   /=="`            '
	@echo         '          \                 /                 '
	@echo         '           `"--._______.--"`                  '
	@echo         '                                              '

norm:
	@norminette ${SRC_DIR} ${PRV_DIR} | grep 'Error' ; true

.PHONY:	all clean fclean re coffee norm
