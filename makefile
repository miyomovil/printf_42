SRCS	= ft_printf.c \
		  ft_print_char.c \
		  ft_print_int.c \
		  ft_print_low_hex.c \
		  ft_print_str.c \
		  ft_print_uint.c \
		  ft_print_up_hex.c \
		  ft_print_point.c \
		  ft_print_opt.c \
		  ft_init_flags.c \
		  ft_flag_switch.c \
		  ft_flag_check_width.c \
		  ft_flag_check_prec.c \
		  ft_flag_check_min.c \
		  ft_flag_check_zer.c \
		  ft_flag_check_min.c \
		  ft_get_atr.c \
		  ft_wr_inc_pr_thgs.c \
		  ft_print_perc.c \
		  ft_print_nbr2.c \
		  
OBJS	= ${SRCS:.c=.o}
NAME	= libftprintf.a
CC		= cc
RM		= rm -f
CFLAGS	= -Wall -Werror -Wextra
.c.o:
	${CC} ${FLAGS} -c $< -o ${<:.c=.o}
${NAME}:	${OBJS}
			make -C ./libft/
			cp libft/libft.a ${NAME}
			ar rc ${NAME} ${OBJS}
			ranlib ${NAME}
all:		${NAME}
clean:
			${RM} ${OBJS}
			make fclean -C libft
fclean:		clean
			${RM} ${NAME}
re:			fclean all
.PHONY:		all clean fclean re
