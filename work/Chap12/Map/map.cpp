// map.cpp

#include <algorithm>
#include <map>
#include <iostream>
#include <string>

using namespace std;

map<string, string , less<string>> AutoCorrect;

void InitializeAutoCorrectTable(void)
{	
	AutoCorrect["abouta"] = "about a";
	AutoCorrect["agian"] = "again";
	AutoCorrect["towrad"] = "toward";
}

string FindAutoCorrect(string word)
{
	bool bfound;


	bfound = AutoCorrect.find(word) != AutoCorrect.end();

	if (bfound)
		return AutoCorrect[word];
	else
		return word;
}

int main()
{
	InitializeAutoCorrectTable();

	string word;
	string result;
	
	word = "abouta";
	result = FindAutoCorrect(word);
	cout << result << endl;
	
	word = "towrad";
	result = FindAutoCorrect(word);
	cout << result << endl;
}
