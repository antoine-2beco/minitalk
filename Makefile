# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ade-beco <ade-beco@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/07 15:13:16 by ade-beco          #+#    #+#              #
#    Updated: 2024/04/10 14:34:07 by ade-beco         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CLIENT			=		client
SERVER			=		server

CLIENT_B		=		client_bonus
SERVER_B		=		server_bonus

LIBFT			=		libft.a
LIBFT_PATH		=		./libft/

SRC_PATH		=		./src/
SRCS_CLIENT		=		client.c
SRCS_D_CLIENT	=		$(addprefix $(SRC_PATH), $(SRCS_CLIENT))
SRCS_CLIENT_B	=		client_bonus.c
SRCS_D_CLIENT_B	=		$(addprefix $(SRC_PATH), $(SRCS_CLIENT_B))
SRCS_SERVER		=		server.c
SRCS_D_SERVER	=		$(addprefix $(SRC_PATH), $(SRCS_SERVER))
SRCS_SERVER_B	=		server_bonus.c
SRCS_D_SERVER_B	=		$(addprefix $(SRC_PATH), $(SRCS_SERVER_B))

OBJECTS_CLIENT	=		$(SRCS_D_CLIENT:.c=.o)
OBJECTS_CLIENT_B=		$(SRCS_D_CLIENT_B:.c=.o)
OBJECTS_SERVER	=		$(SRCS_D_SERVER:.c=.o)
OBJECTS_SERVER_B=		$(SRCS_D_SERVER_B:.c=.o)

INC_CLIENT		=		-I includes/$(CLIENT).h -I $(LIBFT_PATH)$(LIBFT).h
INC_CLIENT_B	=		-I includes/$(CLIENT_B).h -I $(LIBFT_PATH)$(LIBFT).h
INC_SERVER		=		-I includes/$(SERVER).h -I $(LIBFT_PATH)$(LIBFT).h
INC_SERVER_B	=		-I includes/$(SERVER_B).h -I $(LIBFT_PATH)$(LIBFT).h
CFLAGS			=		-Wall -Wextra -Werror

all: 		$(OBJECTS_CLIENT) $(CLIENT) $(OBJECTS_SERVER) $(SERVER)

bonus: 		$(OBJECTS_CLIENT_B) $(CLIENT_B) $(OBJECTS_SERVER_B) $(SERVER_B)

%.o:		%.c
					@cc -Wall -Wextra -Werror -c $< -o $(<:c=o)

$(CLIENT):		$(OBJECTS_CLIENT)
					@make -C $(LIBFT_PATH)
					@cp $(LIBFT_PATH)$(LIBFT) $(CLIENT)
					@echo "Compiling and Creating Minitalk Client..."
					@ar -rcs $(CLIENT) $(OBJECTS_CLIENT)
					@cc $(CLIENT) $(CFLAGS) $(INC_CLIENT) -o $(CLIENT)
					@echo "OK !"

$(SERVER):		$(OBJECTS_SERVER)
					@make -C $(LIBFT_PATH)
					@cp $(LIBFT_PATH)$(LIBFT) $(SERVER)
					@echo "Compiling and Creating Minitalk Server..."
					@ar -rcs $(SERVER) $(OBJECTS_SERVER)
					@cc $(SERVER) $(CFLAGS) $(INC_SERVER) -o $(SERVER)
					@echo "OK !"

$(CLIENT_B):	$(OBJECTS_CLIENT_B)
					@make -C $(LIBFT_PATH)
					@cp $(LIBFT_PATH)$(LIBFT) $(CLIENT_B)
					@echo "Compiling and Creating Minitalk Client Bonus..."
					@ar -rcs $(CLIENT_B) $(OBJECTS_CLIENT_B)
					@cc $(CLIENT_B) $(CFLAGS) $(INC_CLIENT_B) -o $(CLIENT_B)
					@echo "OK !"

$(SERVER_B):	$(OBJECTS_SERVER_B)
					@make -C $(LIBFT_PATH)
					@cp $(LIBFT_PATH)$(LIBFT) $(SERVER_B)
					@echo "Compiling and Creating Minitalk Server Bonus..."
					@ar -rcs $(SERVER_B) $(OBJECTS_SERVER_B)
					@cc $(SERVER_B) $(CFLAGS) $(INC_SERVER_B) -o $(SERVER_B)
					@echo "OK !"

clean:
					@make clean -C $(LIBFT_PATH)
					@echo "Cleaning Minitalk Objects..."
					@rm -f $(OBJECTS_CLIENT)
					@rm -f $(OBJECTS_CLIENT_B)
					@rm -f $(OBJECTS_SERVER)
					@rm -f $(OBJECTS_SERVER_B)
					@echo "OK !"

fclean:			clean
					@echo "Cleaning Libft..."
					@rm -f $(LIBFT_PATH)$(LIBFT)
					@echo "OK !"
					@echo "Cleaning Minitalk..."
					@rm -f $(CLIENT)
					@rm -f $(CLIENT_B)
					@rm -f $(SERVER)
					@rm -f $(SERVER_B)
					@echo "OK !"

re:			fclean all

.PHONY:		all clean fclean re bonus
