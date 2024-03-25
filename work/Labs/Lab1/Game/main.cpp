#define DEBUG

#include <iostream>
#include <ctime>
using namespace std;

int main()
{
    const int MAX_ATTEMPTS = 5;

    srand(time(nullptr));

    int guess;
    int min = 1, max = 20;
    int guessCount = 0;
    int target = rand() % max + 1;

#ifdef DEBUG
    cout << "(DEBUG) Target: " << target << endl;
#endif

/*
Add code to implement an interactive guessing game.
Suggestions: 
1) buid and play the solution to get a sense as to the expected results.
2) use a "do..while" loop to not exceed MAX_ATTEMPTS.
*/

    cout << "Maximum attempts reached." << endl;
    cout << "The target number is " << target << endl;
    return 1;

}