#include <iostream>

using namespace std;

/*
The length of a string is determined by the terminating null-character ('\0').
A C string is as long as the number of characters between the beginning of the string and the terminating null character (without including the terminating null character itself).
Returns the length of the string.
*/
size_t slen(const char *p)
{
    const char *it;
    it = p;
    while (*it != '\0')
        ++it;
    return it - p;
}

/*
Appends a copy of the source string to the destination string.
The terminating null character in destination is overwritten by the first character of source,
and a null-character is included at the end of the new string formed by the concatenation of both in destination.
Returns pointer to destination.
*/
char *scat(char *dest, const char *src)
{
    const char *it;
    char *pdest = dest;
    it = src;
    while (*it != '\0')
    {
        *(pdest++) = *it;
        ++it;
    }
    *pdest = '\0';
    return dest;
}

int main()
{
    const char *ar[] = {"Hello", " ", "World!"};
    int len = 0;
    for (int i = 0; i < sizeof(ar) / sizeof(char *); i++)
    {
        len += slen(ar[i]);
    }

    char *begin = new char[len + 1];

    char *next = begin;
    for (int i = 0; i < sizeof(ar) / sizeof(char *); ++i)
    {
       scat(next, ar[i]);
       next += slen(next);
    }

    cout << begin << endl;
    delete []begin;

    return 0;
}
