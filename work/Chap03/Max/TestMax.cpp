// TestMax.cpp
//
//  Function to determine max. of 2 or 3 char's, int's or long's
//  along with test program.  Note need to do type casting in calling
//  function for char's.

#include <iostream>
#include <climits>

using namespace std;

// The actual value of LONG_MIN depends on the compiler architecture or library implementation
long Maxval(long, long, long x = LONG_MIN);

int main()
{

    cout << "max of 'a', 'i', 'z' is "
        << (char) Maxval('a', 'i', 'z') << '\n';

    cout << "max of 'a', 'i' is "
        << Maxval('a', 'i') << '\n';

    cout << "max of 123, 555, 789 is "
        << Maxval(123, 555, 789) << '\n';

    cout << "max of 123, 555 is "
        << Maxval(123, 555) << '\n';

    cout << "max of 123456, 555555, 777789 is "
        << Maxval(123456, 555555, 777789) << '\n';

    cout << "max of 123456, 555555 is "
        << Maxval(123456, 555555) << '\n';

	return 0;
}

long Maxval(long x, long y, long z)
{
    long tmax = (x > y ? x : y);
    if (z > tmax)
        tmax = z;
    return tmax;
}

