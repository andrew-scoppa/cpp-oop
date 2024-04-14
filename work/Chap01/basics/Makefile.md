# Makefile Basics

### Description:
A Makefile is used to compile and link a C++ program. Here's a breakdown of what each part does:

1) CXX = g++: This line defines the C++ compiler to use. In this case, it's g++, which is a popular C++ compiler.

2) CXXFLAGS = -Wall -g: This line defines the flags to pass to the compiler. -Wall enables all warning messages, which can help catch potential issues in your code. -g includes debugging information in the compiled files, which can be useful if you need to debug your program.

3) TARGET = basics: This line defines the name of the executable file that will be created when the source code is compiled and linked. To change the name of the executable, you can invoke the make command with the TARGET variable set to the desired name, like this: make TARGET=myprogram.

4) SRCS = basics.cpp: This line defines the C++ source files to compile. In this case, there's just one file: basics.cpp. If you have multiple source files, you can list them all separated by spaces.

5) OBJS = $(SRCS:.cpp=.o): This line defines the object files that will be created when the source files are compiled. It uses a substitution reference to replace the .cpp extension with .o in each source file name.

6) all: $(TARGET): This is the default rule that's run when you type make with no arguments. It depends on the $(TARGET) rule, so it will cause that rule to be run.

7) $(TARGET): $(OBJS): This rule links the object files into the executable file. The command line that does this is $(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS), which calls the compiler with the flags, specifies the output file name with -o $(TARGET), and provides the object files.

8) .cpp.o:: This is a pattern rule that compiles each .cpp file into a corresponding .o file. The command line that does this is $(CXX) $(CXXFLAGS) -c $< -o $@, which calls the compiler with the flags, specifies that it should compile (not link) with -c, provides the source file name with $<, and specifies the output file name with -o $@.

9) clean:: This rule removes the compiled files. It's useful for cleaning up your workspace. The command line that does this is $(RM) $(TARGET) $(OBJS), which removes the executable and object files.

### Usage:

To compile and link the program, run make. This will create an executable file named basics.

To clean up the workspace, run make clean. This will remove the executable and object files.

