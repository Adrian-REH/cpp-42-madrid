# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: adherrer <adherrer@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/23 04:06:52 by adherrer          #+#    #+#              #
#    Updated: 2024/12/18 16:47:53 by adherrer         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = span
CC = g++
CFLAGS = -std=c++98 -Wall -Wextra -Werror -g -fprofile-arcs -ftest-coverage
SRCS = main.cpp Span.cpp
INCLUDE = 

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
	rm -f $(OBJS) *.gcda logs *.html *.css
	rm -f $(OBJS)
	@echo "Archivos .o eliminados."

# Limpiar todo, incluyendo el ejecutable
fclean: clean
	rm -rf *.gcov *.
	rm -f $(NAME)
	@echo "Ejecutable $(NAME) eliminado."

# Recompilar
re: fclean all

cov: fclean all
	./$(NAME)
	@for src in $(SRCS); do \
		echo "Processing $$src"; \
		dir=$$(dirname "$$src"); \
		gcov --object-directory=$$dir "$$src"; \
	done
	gcovr -r . --html --html-details -o coverage.html

.PHONY: all clean fclean re cov
 