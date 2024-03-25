#include <iostream>

int main(int argc, char **argv){
    if (argc == 1)
    {
        std::cout << argv[0] << "\nNo command line arguments entered." << std::endl;
        return 1;
    }

    // indexed 
    for (size_t i = 1; i < argc; i++)
    {
        std::cout << argv[i] << std::endl;
    }

    // walk pointer - argv is the address of the 1st element (a pointer to char)
    for (char**p =  argv; p < (argv + argc); ++p){
         std::cout << *p << std::endl;
    }
    std::cout << "end" << std::endl;
    return 0; 
}
