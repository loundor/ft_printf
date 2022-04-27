NAME	= libftprintf.a
LIBFT_DIR	= ./libft
LIBFT		= $(LIBFT_DIR)/libft.a
CC		= gcc
FLAGS	= -Wall -Werror -Wextra
SRCS	= pf_append.c pf_check.c pf_d_i.c pf_h.c pf_c.c pf_p.c pf_s.c pf_size.c pf_ud.c pf_hash.c pf_o.c ft_printf.c
OBJS	= $(addprefix ./, ${SRCS:.c=.o})
HEADER	= -I./ -I$(LIBFT_DIR)

.c.o	:
			${CC} ${FLAGS} -c ${HEADER} $< -o ${<:.c=.o}

$(NAME)	:	${OBJS} $(LIBFT)
			ar -rcs ${NAME} ${OBJS}

$(LIBFT):
			make -C $(LIBFT_DIR)
			cp $(LIBFT) $(NAME)

all		: ${NAME}
bonus	: ${NAME}
clean	:
			make clean -C $(LIBFT_DIR)
			rm -f ${OBJS}

fclean	:	clean
			make fclean -C $(LIBFT_DIR)
			rm -f ${NAME}

re		:	fclean all

.PHONY	:	all clean fclean re ${NAME}
