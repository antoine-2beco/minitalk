# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ade-beco <ade-beco@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/16 13:21:18 by ade-beco          #+#    #+#              #
#    Updated: 2024/03/18 14:11:29 by ade-beco         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	libft.a

SRCS		=	ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c ft_strlen.c ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c ft_strlcpy.c ft_strlcat.c ft_toupper.c ft_tolower.c ft_strchr.c ft_strrchr.c ft_strncmp.c ft_memchr.c ft_memcmp.c ft_strnstr.c ft_atoi.c ft_calloc.c ft_strdup.c ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c ft_striteri.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c

SRCS_BONUS	=	ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c

SRCS_PERS	=	ft_putstr.c ft_putchar.c ft_printf.c ft_printf_utils.c get_next_line.c ft_lstget.c ft_strappend.c

OBJS		=	$(SRCS:.c=.o) $(SRCS_BONUS:.c=.o) $(SRCS_PERS:.c=.o)

CC			=	cc

CFLAGS		=	-Wall -Wextra -Werror -g

LIBC		=	ar rcs

INC			=	-I ./includes

all:		$(OBJS) $(NAME)

%.o:		%.c
				@$(CC) $(CFLAGS) -c $(INC) $< -o $(<:c=o)

$(NAME):	$(OBJS)
				@echo "Creating Libft Executable..."
				@$(LIBC) $(NAME) $(OBJS)
				@echo "OK "
clean:
				@echo "Cleaning Libft Objects..."
				@rm -f $(OBJS)
				@echo "OK !"

fclean:		clean
				@echo "Cleaning Libft..."
				@rm -f $(NAME)
				@echo "OK !"

bonus:		$(OBJS)
				@echo "Creating Libft with Bonus Executable..."
				@$(LIBC) $(NAME) $(OBJS)
				@echo "OK !"

re:			fclean all

.PHONY:		all clean fclean re bonus