# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: adherrer <adherrer@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/23 04:06:52 by adherrer          #+#    #+#              #
#    Updated: 2024/11/01 16:57:59 by adherrer         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -g -std=c++98
TARGET = ex03
SRCS = main.cpp \
	character/infra/Character.cpp  \
	materia/repository/AMateria.cpp  \
	materiaSource/infra/MateriaSource.cpp \
	materia/infra/Ice.cpp \
	materia/infra/Cure.cpp \
	materia/infra/Hold.cpp \
	materia/infra/Fire.cpp \
	materia/infra/Electric.cpp \
	utils/stolower.cpp \
	utils/realloc.cpp
OBJS = $(SRCS:.cpp=.o)

# Regla por defecto
all: $(TARGET)

# Compilar el ejecutable
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

# Regla para compilar los archivos .o
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Limpiar los archivos generados
clean:
	rm -f $(OBJS)

# Limpiar todo, incluyendo el ejecutable
fclean: clean
	rm -f $(TARGET)

# Recompilar
re: fclean all

.PHONY: all clean fclean re

