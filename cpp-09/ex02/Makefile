# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: adherrer <adherrer@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/23 04:06:52 by adherrer          #+#    #+#              #
#    Updated: 2025/01/12 16:51:19 by adherrer         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = PmergeMe
CC = c++
CFLAGS = -std=c++98 -Wall -Wextra -Werror -g -fprofile-arcs -ftest-coverage
SRCS = main.cpp split.cpp
INCLUDE = PmergeMe.hpp split.hpp 
TARGET ?= "2 2 5 223 3 1"

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
	rm -f $(OBJS) *.gcov *.gcda logs *.gcno *.html *.css 
	rm -f $(OBJS)
	@echo "Archivos .o eliminados."

# Limpiar todo, incluyendo el ejecutable
fclean: clean
	rm -f $(NAME)
	@echo "Ejecutable $(NAME) eliminado."

# Recompilar
re: fclean all

cov: fclean all
	./$(NAME) "$(TARGET)"
	@for src in $(SRCS); do \
		echo "Processing $$src"; \
		dir=$$(dirname "$$src"); \
		gcov --object-directory=$$dir "$$src"; \
	done
	gcovr -r . --html --html-details -o coverage.html
	open ./coverage.html


.PHONY: all clean fclean re cov
 