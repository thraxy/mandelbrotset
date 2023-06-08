# compiler
CXX := g++

# compiler flags
CXXFLAGS := -std=c++11 -Wall -Wextra

# library flags
LDFLAGS := -framework OpenGL -framework GLUT

# include directory
INCLUDES := -I.

# source files
SRCS := src/main/main.cpp

# object files
OBJS := $(SRCS:.cpp=.o)

# target exectuable
TARGET := project1

# default target
all: $(TARGET)

# rule to build the exec
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) $(LDFLAGS) $(INCLUDES) -o $@ $^

# rule to build object files from source files
%.o: %.cpp
	$(CXX) $(CXXFLAGS) $(INCLUDES) -c $< -o $@

# clean rule
clean:
	rm -f $(OBJS) $(TARGET)