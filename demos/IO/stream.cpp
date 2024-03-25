#include <iostream>
#include <ostream>
#include <fstream>

void logit(std::ostream &os, std::string message)
{
    os << "Log message..." << std::endl;
}

void logit(std::ofstream &os, std::string message)
{
    os << message << std::endl;
}

int main()
{
    logit(std::cerr, "Hello World!");

    std::ofstream ofs("outfile.txt", std::ios_base::app);
    logit(ofs, "Hello");
    logit(ofs, "Goodbye");
    ofs.close();
}
