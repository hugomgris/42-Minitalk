# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hmunoz-g <hmunoz-g@student.42barcelon      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/16 16:17:09 by hmunoz-g          #+#    #+#              #
#    Updated: 2024/10/16 18:08:38 by hmunoz-g         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Colors
DEF_COLOR = \033[0;39m
YELLOW = \033[0;93m
CYAN = \033[0;96m
GREEN = \033[0;92m
BLUE = \033[0;94m
RED = \033[0;91m

NAME = libftprintf.a
CC = cc
FLAGS = -Werror -Wall -Wextra -g
LIBFTDIR = ../
RM = rm -f

LIBFT_OBJS = $(addprefix $(LIBFTDIR), \
	ft_itoa.o \
	ft_strchr.o \
	ft_strdup.o \
	ft_strjoin.o \
	ft_strmapi.o \
	ft_strnstr.o \
	ft_strchr.o \
	ft_strrchr.o \
	ft_substr.o \
	ft_split.o \
	ft_atoi.o \
	ft_isalnum.o \
	ft_isalpha.o \
	ft_isascii.o \
	ft_isdigit.o \
	ft_isprint.o \
	ft_isspace.o \
	ft_isvalidsign.o \
	ft_memcmp.o \
	ft_tolower.o \
	ft_toupper.o \
	ft_strncmp.o \
	ft_strlcat.o \
	ft_strlcpy.o \
	ft_strlen.o \
	ft_bzero.o \
	ft_calloc.o \
	ft_memchr.o \
	ft_memcpy.o \
	ft_memmove.o \
	ft_memset.o \
	ft_putchar_fd.o \
	ft_putendl_fd.o \
	ft_putnbr_fd.o \
	ft_putstr_fd.o \
	ft_striteri.o \
	ft_strtrim.o \
	ft_free.o \
	get_next_line.o)

SRCS = srcs/ft_printf.c srcs/ft_starter.c srcs/managers/ft_com_managers.c \
       srcs/managers/ft_itoa_printf.c srcs/managers/ft_itoa_printf_u.c \
       srcs/managers/ft_itoa_printf_x.c srcs/managers/ft_putstr_fd_print.c \
       srcs/managers/ft_putchar_fd_print.c srcs/managers/ft_putnbase_fd.c \
       srcs/parser/ft_condition_checker.c srcs/parser/ft_flag_checker.c \
       srcs/parser/ft_parser.c srcs/printers/ft_printf_c.c \
       srcs/printers/ft_printf_di.c srcs/printers/ft_printf_p.c \
       srcs/printers/ft_printf_s.c srcs/printers/ft_printf_u.c \
       srcs/printers/ft_printf_x.c

BONUS_SRCS = srcs/ft_printf.c srcs/ft_starter.c srcs/managers/ft_com_managers.c \
       srcs/managers/ft_itoa_printf.c srcs/managers/ft_itoa_printf_u.c \
       srcs/managers/ft_itoa_printf_x.c srcs/managers/ft_putstr_fd_print.c \
       srcs/managers/ft_putchar_fd_print.c srcs/managers/ft_putnbase_fd.c \
       srcs/parser/ft_condition_checker.c srcs/parser/ft_flag_checker.c \
       srcs/parser/ft_parser.c srcs/bonus/ft_printf_c_bonus.c \
             srcs/bonus/ft_printf_di_bonus.c srcs/bonus/ft_printf_di_functions_bonus.c \
             srcs/bonus/ft_printf_p_bonus.c srcs/bonus/ft_printf_p_functions_bonus.c \
             srcs/bonus/ft_printf_s_bonus.c srcs/bonus/ft_printf_s_functions_bonus.c \
             srcs/bonus/ft_printf_u_bonus.c srcs/bonus/ft_printf_u_functions_bonus.c \
             srcs/bonus/ft_printf_x_bonus.c srcs/bonus/ft_printf_x_functions_bonus.c

OBJS = $(SRCS:.c=.o)
BONUS_OBJS = $(BONUS_SRCS:.c=.o)

%.o: %.c Makefile includes/ft_printf.h
	$(CC) $(FLAGS) -I. -c $< -o $@
	@echo "$(YELLOW)Compiling: $< $(DEF_COLOR)"

all: $(NAME)

$(NAME): $(OBJS) ${LIBFT_OBJS}
	ar rcs $(NAME) $(OBJS) ${LIBFT_OBJS}

bonus: fclean $(BONUS_OBJS) ${LIBFT_OBJS}
	@echo "${CYAN}ft_printf.a is being built in ${RED}BONUS MODE${CYAN}!${DEF_COLOR}"
	ar rcs $(NAME) $(BONUS_OBJS) ${LIBFT_OBJS}

clean:
	$(RM) $(OBJS) $(BONUS_OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus
