#include <fstream>
#include <iostream>
#include <string>

/*
This function reads a file and prints its contents to the console. it uses a function-try-block to catch exceptions.
*/
void readFile(const std::string& filename) try {
    std::ifstream file(filename);
    if (!file.is_open()) {
        throw std::runtime_error("Could not open file");
    }

    std::string line;
    while (std::getline(file, line)) {
        std::cout << line << '\n';
    }
} catch (const std::exception& e) {
    std::cerr << "An error occurred: " << e.what() << '\n';
}