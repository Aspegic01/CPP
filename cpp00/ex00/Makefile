CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++11

SRC = megaphone.cpp
OBJ = $(SRC:.cpp=.o)
TARGET = megaphone

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $@ $^

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(TARGET)

re: fclean all

.PHONY: all clean fclean re
.SECONDARY:
