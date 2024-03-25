#include <iostream>

int main(int argc, char **argv){
    if (argc == 1)
    {
        std::cout << argv[0] << "\nNo command line arguments entered." << std::endl;
        return 1;
    }

    for (size_t i = 1; i < argc; i++)
    {
        std::cout << argv[i] << std::endl;
    }
    
    return 0; 
}
