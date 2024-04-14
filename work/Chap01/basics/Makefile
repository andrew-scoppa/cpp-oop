# Define the C++ compiler to use
CXX = g++

# Define any compile-time flags
CXXFLAGS = -Wall -g

# Define the target file
TARGET = basics

# Define the C++ source files
SRCS = basics.cpp

# Define the C++ object files
OBJS = $(SRCS:.cpp=.o)

# The default rule, to compile everything.
all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

.cpp.o:
	$(CXX) $(CXXFLAGS) -c $<  -o $@

# Define a clean rule
clean:
	$(RM) $(TARGET) $(OBJS)
