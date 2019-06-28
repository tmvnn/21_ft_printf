# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lbellona <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/24 16:32:39 by lbellona          #+#    #+#              #
#    Updated: 2019/01/23 20:56:54 by lbellona         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SOURCES = ft_printf.c\
		ft_atoi.c\
		ft_itoa.c\
		ft_memalloc.c\
		ft_memset.c\
		ft_strchr.c\
		ft_strcpy.c\
		ft_strdup.c\
		ft_strjoin.c\
		ft_strlen.c\
		ft_strnew.c\
		handle_int.c\
		parsers.c\
		pf_check_funcs.c\
		print_int.c

SRCSDIR     = srcs
SRCS = $(addprefix $(SRCSDIR)/, $(SOURCES))

NAME		= libftprintf.a
WWW			= -Wall -Wextra -Werror
INCLUDES	= -I includes/

OBJDIR		= objs
OFILES 		= $(SOURCES:.c=.o)
OBJS 		= $(addprefix $(OBJDIR)/, $(OFILES))

all: $(NAME)

$(OBJDIR)/%.o: $(SRCSDIR)/%.c
	@/bin/mkdir -p $(OBJDIR)
	@gcc -c $(WWW) $(INCLUDES) $< -o $@

$(NAME): $(OBJS)
	ar rc $(NAME) $(OBJS)
	ranlib $(NAME)

clean:
	/bin/rm -rf $(OBJDIR)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all