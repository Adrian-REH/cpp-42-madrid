# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: adherrer <adherrer@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/23 04:06:52 by adherrer          #+#    #+#              #
#    Updated: 2024/12/11 16:25:51 by adherrer         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = easyfind
CC = c++
CFLAGS = -std=c++98 -Wall -Wextra -Werror
SRCS = main.cpp
INCLUDE = easyfind.hpp easyfind.tpp

OBJS = ${SRCS:.cpp=.o}

# Regla por defecto

# Compilar el ejecutable
$(NAME): $(OBJS) $(INCLUDE)
			$(CC) -o $(NAME) $(CFLAGS) $(OBJS)
			
all: $(NAME)


# Regla para compilar los archivos .o
%.o:%.cpp $(INCLUDE)
		$(CC) $(CFLAGS) -c $< -o $@

# Limpiar los archivos generados
clean:
	rm -f $(OBJS)
	@echo "Archivos .o eliminados."

# Limpiar todo, incluyendo el ejecutable
fclean: clean
	rm -f $(NAME)
	@echo "Ejecutable $(NAME) eliminado."

# Recompilar
re: fclean all

.PHONY: all clean fclean re
