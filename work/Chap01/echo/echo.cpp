#include <iostream>

int main(int argc, char **argv)
{
    if (argc == 1)
    {
        std::cout << argv[0] << "\nNo command line arguments entered." << std::endl;
        // show example of how to use the program
        std::cout << "Usage: " << argv[0] << " <arg1> <arg2> ... <argN>" << std::endl;
        return 0;
    }

    for (size_t i = 1; i < argc; i++)
    {
        // print the index and the argument
        std::cout << i << ": " << argv[i] << std::endl;
    }

    return 0;
}
