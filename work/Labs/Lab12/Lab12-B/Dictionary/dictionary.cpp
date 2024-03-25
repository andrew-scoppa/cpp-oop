// dictionary.cpp

#include <algorithm>
#include <map>
#include <iostream>
#include <string>

using namespace std;

int main()
{
	/*
    Declare an instance of a map container. 
    The type of both key and the value will be the STL string class.
    As a dictionary in alphabetic order, the comparison function object should be less

    Populate the dictionary with words of your choosing by using associative array property.
    */
	string word;

	cout << "Enter a word, quit to exit: ";
	cin >> word;
	while (word != "quit")
	{
    /*
    lookup the definition of any word (use std::map.find()).
    Display the definition if found, else display a "not found" message
    */
		cout << ": ";
		cin >> word;
	}
}
