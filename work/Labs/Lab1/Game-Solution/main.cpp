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
    cout << "(DEBUG mode) Target: " << target << endl;
#endif

    do {
        cout << "Enter a number between " << min << " and " << max << ": ";
        cin >> guess;

        guessCount += 1;

        if (guess < min || guess > max)
        {
            cout << "Out of bounds!" << endl;
        }
        else if (guess < target)
        {
            cout << "too low" << endl;
            min = guess + 1;
        }
        else if (guess > target) {
            cout << "too high" << endl;
            max = guess - 1;
        }
        else {
            cout << "Congratulations!" << endl << " You won the game in " << guessCount << " tries!" << endl;
            return 0;
        }

    } while (guessCount < MAX_ATTEMPTS);

    cout << "Maximum attempts reached." << endl;
    cout << "The target number is " << target << endl;
    return 1;

}