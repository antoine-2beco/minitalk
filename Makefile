# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ade-beco <ade-beco@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/07 15:13:16 by ade-beco          #+#    #+#              #
#    Updated: 2024/04/09 11:29:13 by ade-beco         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CLIENT			=		client
SERVER			=		server

LIBFT			=		libft.a
LIBFT_PATH		=		./libft/

SRC_PATH		=		./src/
SRCS_CLIENT		=		client.c
SRCS_D_CLIENT	=		$(addprefix $(SRC_PATH), $(SRCS_CLIENT))
SRCS_SERVER		=		server.c
SRCS_D_SERVER	=		$(addprefix $(SRC_PATH), $(SRCS_SERVER))

OBJECTS_CLIENT	=		$(SRCS_D_CLIENT:.c=.o)
OBJECTS_SERVER	=		$(SRCS_D_SERVER:.c=.o)

INC_CLIENT		=		-I includes/$(CLIENT).h -I $(LIBFT_PATH)$(LIBFT).h
INC_SERVER		=		-I includes/$(SERVER).h -I $(LIBFT_PATH)$(LIBFT).h
CFLAGS			=		-Wall -Wextra -Werror

all: 		$(OBJECTS_CLIENT) $(CLIENT)

%.o:		%.c
					@cc -Wall -Wextra -Werror -Imlx -c $< -o $(<:c=o)

$(CLIENT):	$(OBJECTS_CLIENT)
					@echo "Compiling Libft..."
					@make bonus -C $(LIBFT_PATH)
					@cp $(LIBFT_PATH)$(LIBFT) $(CLIENT)
					@echo "OK !"
					@echo "Compiling and Creating Minitalk Client..."
					@ar -rcs $(CLIENT) $(OBJECTS_CLIENT)
					@cc $(CLIENT) $(CFLAGS) $(INC_CLIENT) -o $(CLIENT)
					@echo "OK !"

$(SERVER):	$(OBJECTS_SERVER)
					@echo "Compiling Libft..."
					@make bonus -C $(LIBFT_PATH)
					@cp $(LIBFT_PATH)$(LIBFT) $(SERVER)
					@echo "OK !"
					@echo "Compiling and Creating Minitalk Server..."
					@ar -rcs $(SERVER) $(OBJECTS_SERVER)
					@cc $(SERVER) $(CFLAGS) $(INC_SERVER) -o $(SERVER)
					@echo "OK !"

clean:
					@make clean -C $(LIBFT_PATH)
					@echo "Cleaning Minitalk Objects..."
					@rm -f $(OBJECTS_CLIENT)
					@rm -f $(OBJECTS_SERVER)
					@echo "OK !"

fclean:			clean
					@make fclean -C $(LIBFT_PATH)
					@echo "Cleaning Minitalk..."
					@rm -f $(CLIENT)
					@rm -f $(SERVER)
					@echo "OK !"

re:			fclean all

.PHONY:		all clean fclean re
