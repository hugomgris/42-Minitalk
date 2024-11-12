# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hmunoz-g <hmunoz-g@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/29 11:12:41 by hmunoz-g          #+#    #+#              #
#    Updated: 2024/11/11 12:45:35 by hmunoz-g         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Colors
DEF_COLOR = \033[0;39m
YELLOW = \033[0;93m
CYAN = \033[0;96m
GREEN = \033[0;92m
BLUE = \033[0;94m
RED = \033[0;91m

NAME = minitalk
CC = cc
FLAGS = -Werror -Wall -Wextra -g
LIBFTDIR = libft/
PRINTFDIR = libft/ft_printf/
RM = rm -f

SRCS = client.c server.c
BONUS_SRCS = bonus/client_bonus.c bonus/server_bonus.c

OBJS = $(SRCS:.c=.o)
BONUS_OBJS = $(BONUS_SRCS:.c=.o)

all: $(LIBFTDIR)libft.a $(PRINTFDIR)libftprintf.a $(NAME)

%.o: %.c Makefile minitalk.h libft/libft.h libft/ft_printf/ft_printf.h
	$(CC) $(FLAGS) -Ilibft -Ilibft/ft_printf -c $< -o $@
	@echo "$(YELLOW)Compiling: $< $(DEF_COLOR)"

$(NAME): server client

server: Makefile minitalk.h server.o $(LIBFTDIR)libft.a $(PRINTFDIR)libftprintf.a
	@echo "$(GREEN)Compiling server!$(DEF_COLOR)"
	$(CC) $(FLAGS) server.o $(LIBFTDIR)libft.a $(PRINTFDIR)libftprintf.a -o server
	@echo "$(GREEN)Server compiled!$(DEF_COLOR)"

client: Makefile minitalk.h client.o $(LIBFTDIR)libft.a $(PRINTFDIR)libftprintf.a
	@echo "$(GREEN)Compiling client!$(DEF_COLOR)"
	$(CC) $(FLAGS) client.o $(LIBFTDIR)libft.a $(PRINTFDIR)libftprintf.a -o client
	@echo "$(GREEN)Client compiled!$(DEF_COLOR)"

$(LIBFTDIR)libft.a:
	@echo "$(CYAN)Building libft.a!$(DEF_COLOR)"
	@$(MAKE) -C $(LIBFTDIR)

$(PRINTFDIR)libftprintf.a:
	@echo "$(CYAN)Building libftprintf.a!$(DEF_COLOR)"
	@$(MAKE) -C $(PRINTFDIR)

bonus: fclean $(BONUS_OBJS) $(LIBFTDIR)libft.a $(PRINTFDIR)libftprintf.a
	@echo "$(RED)Compiling client in BONUS MODE!$(DEF_COLOR)"
	$(CC) $(FLAGS) bonus/client_bonus.o -Llibft -lft -Llibft/ft_printf -lftprintf -o client
	@echo "$(RED)Compiling server in BONUS MODE!$(DEF_COLOR)"
	$(CC) $(FLAGS) bonus/server_bonus.o -Llibft -lft -Llibft/ft_printf -lftprintf -o server
	@echo "$(RED)BONUS COMPILED!$(DEF_COLOR)"

clean:
	@$(MAKE) clean -C $(LIBFTDIR)
	@$(MAKE) clean -C $(PRINTFDIR)
	@$(RM) $(OBJS)
	@echo "$(RED)Cleaned object files$(DEF_COLOR)"

fclean: clean
	@$(MAKE) fclean -C $(LIBFTDIR)
	@$(MAKE) fclean -C $(PRINTFDIR)
	@$(RM) server client
	@echo "$(RED)Cleaned all binaries$(DEF_COLOR)"

re: fclean all

.PHONY: all clean fclean re libft ft_printf bonus
