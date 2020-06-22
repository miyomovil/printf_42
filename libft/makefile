# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: antomart <antomart@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/21 15:08:25 by antomart          #+#    #+#              #
#    Updated: 2020/06/22 13:48:06 by antomart         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	=	ft_atoi.c \
	  		ft_bzero.c \
			ft_calloc.c \
			ft_islower.c \
			ft_isupper.c \
			ft_isalnum.c \
			ft_isalpha.c \
			ft_isascii.c \
			ft_isdigit.c \
			ft_isprint.c \
			ft_isspace.c \
			ft_memset.c \
			ft_memchr.c \
			ft_memcmp.c \
			ft_memcpy.c \
			ft_memccpy.c \
			ft_memmove.c \
			ft_memalloc.c \
			ft_putchar_fd.c \
			ft_putendl_fd.c \
			ft_putnbr_fd.c \
			ft_putstr_fd.c \
			ft_strcpy.c \
			ft_strncpy.c \
			ft_strmapi.c \
			ft_split.c \
			ft_strcat.c \
			ft_strjoin.c \
			ft_itoa.c \
			ft_strdup.c \
			ft_strchr.c \
			ft_strrchr.c \
			ft_strtrim.c \
			ft_strnstr.c \
			ft_strnew.c \
			ft_strlen.c \
			ft_strlcat.c \
			ft_strlcpy.c \
			ft_strncmp.c \
			ft_substr_1.c \
			ft_tolower.c \
			ft_toupper.c \
			ft_wordlen.c \
			ft_wordcount.c \
			ft_memdel.c \
			ft_negsign.c \
			ft_possign.c \
			ft_clear_lst.c \
			get_next_line_bonus.c \
			get_next_line_utils_bonus.c \
			ft_flag_check_min.c \
			ft_flag_check_prec.c \
			ft_flag_check_width.c \
			ft_flag_check_zer.c \
			ft_flag_switch.c \
			ft_get_atr.c \
			ft_init_flags.c \
			ft_print_char.c \
			ft_printf.c \
			ft_print_int.c \
			ft_print_low_hex.c \
			ft_print_nbr2.c \
			ft_print_opt.c \
			ft_print_perc.c \
			ft_print_point.c \
			ft_print_str.c \
			ft_print_uint.c \
			ft_print_up_hex.c \
			ft_wr_inc_pr_thgs.c \


SRCS_B	= 	ft_lstnew_bonus.c \
			ft_lstadd_front_bonus.c \
			ft_lstsize_bonus.c \
			ft_lstlast_bonus.c \
			ft_lstadd_back_bonus.c \
			ft_lstdelone_bonus.c \
			ft_lstclear_bonus.c \
			ft_lstiter_bonus.c \
			ft_lstmap_bonus.c \

OBJS	= ${SRCS:.c=.o}
OBJS_B	= ${SRCS_B:.c=.o}
NAME	= libft.a
CC		= cc
RM		= rm -f
CFLAGS	= -Wall -Werror -Wextra
.c.o:
		${CC} ${FLAGS} -c $< -o ${<:.c=.o}
${NAME}:	${OBJS}
			ar rc  ${NAME} ${OBJS}
			ranlib ${NAME}
bonus:		${OBJS} ${OBJS_B}
			ar rc  ${NAME} ${OBJS} ${OBJS_B}
			ranlib ${NAME}
all:		${NAME}
clean:
			${RM} ${OBJS} ${OBJS_B}
fclean:		clean
			${RM} ${NAME}
re:			fclean all
.PHONY:		bonus all clean fclean re

