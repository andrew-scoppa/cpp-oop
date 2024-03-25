#include <exception>
#include <iostream>
#include <stdexcept>
#include <string>

void handle_eptr(std::exception_ptr eptr) // passing by value is ok
{
    try
    {
        if (eptr)
            std::rethrow_exception(eptr);
    }
    catch (std::bad_exception const &)
    {
        std::cout << "Bad exception" << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cout << "Caught exception: '" << e.what() << "'\n";
    }
}

int main()
{
    std::exception_ptr eptr;

    try
    {
        std::string().at(1); // this generates a std::out_of_range
    }
    catch (...)
    {
        eptr = std::current_exception();
    }

    handle_eptr(eptr);

} // destructor for std::out_of_range called here, when the eptr is destructed