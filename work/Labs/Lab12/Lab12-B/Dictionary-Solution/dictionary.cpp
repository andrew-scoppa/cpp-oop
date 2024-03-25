// dictionary.cpp

#include <algorithm>
#include <map>
#include <iostream>
#include <string>

using namespace std;

int main()
{
	map<string, string, less<string> > dictionary;

	dictionary["hello"] = "an expression of greeting";
	dictionary["goodbye"] = "an expression of parting";
	dictionary["chad"] = "small pieces of paper produced when punching paper";

	string word;

	cout << "Enter a word, quit to exit: ";
	cin >> word;
	while (word != "quit")
	{
		if (dictionary.find(word) != dictionary.end())
			cout << "The definition of " << word << " is " << dictionary[word] << "." << endl;
		else
			cout << "No definition for " << word << " was found." << endl;
		cout << ": ";
		cin >> word;
	}
}
