# Variables
CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -g -std=c++98
TARGET = harl
SRCS = main.cpp Harl.cpp
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
