CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++17

# Find all source files recursively inside src/
SRC = $(shell find -type f -name "*.cpp")
OBJ = $(SRC:.cpp=.o)

# Find all subdirectories inside include/ and add them to CXXFLAGS as -I flags
INCLUDE_DIRS = $(shell find include -type d)
INCLUDE_FLAGS = $(patsubst %, -I%, $(INCLUDE_DIRS))
CXXFLAGS += $(INCLUDE_FLAGS)  # Append include paths to CXXFLAGS

TARGET = raytracer

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJ)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(TARGET)

re: fclean all

.PHONY: all clean fclean re
