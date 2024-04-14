/* Sample C++ language primer */

/*
#include is a way of including a standard or user-defined file in the program and is mostly written at the beginning of any C/C++ program. This directive is read by the preprocessor and orders it to insert the content of a user-defined or system header file into the following program.
*/
#include "basics.h" // contains the DEBUG and TARGET tokens
#include <string>
#include <iostream>

/*
A namespace helps prevent name conflicts in large projects.
You want to use the functionalities of a namespace throughout the code without repeatedly calling the namespace when it's required.
So, you declare the namespace at the beginning of the code.
Also, the syntax that's required for using cout is std::cout.
Adding the line "using namespace std;" can help you avoid writing "std::" before the standard functions.
*/
using std::cin, std::cout, std::endl, std::getline, std::string, std::stol;

/*
main() is a global function and is an entry point for a C++ program.
*/
int main()
{

    string resp;
    auto guessCount = 1;
    int guess;
    string message;

/*
The #if directive (and the #elif, #else, and #endif directives) controls compilation of portions of a source file.
*/
#ifdef DEBUG
#include <cstdio>
    char buffer[50];
    sprintf(buffer, "(DEGUG mode) The secret target is %d\n", TARGET);
    cout << buffer << endl;
#endif

    while (true)
    {
        /*
        cout prints a specific string as output. std::cout is part of a collection of data and operations of the std::ostream class.
        */
        cout << "Guess #" << guessCount++ << endl;
        cout << "Press <enter> to exit" << endl;

        /*
        The C++ getline() is a standard library function that is used to read a string or a line from an input stream. It is a part of the <string> header.
        */
        getline(cin, resp);
        if (resp.empty() || resp == "Q" || resp == "q")
        {
            cout << "User stopped game";
            return 0;
        }

        /*
        Convert string to a long. Stop reading string at the first character not recognized as part of a number. It is a part of the <string> header.
        */
        guess = stol(resp);
        if (guess == TARGET)
        {
            cout << "You won!!!";
            return 0;
        }
        message = guess > TARGET ? "over" : "under";
        cout << "you are " << message << " target value" << endl;
    }

    cout << "Game over!";
    return 0;
}