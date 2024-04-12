#include <iostream>

// add the 'using' statement to use only the 'string' class and 'cout'
using std::string;
using std::cout;

struct SAutomobile{
  string make;
  string model;
  int year;
};

class CAutomobile{
  string make;
  string model;
  int year;
};

int main() {
  SAutomobile s;
  s.make = "Land Rover";
  s.model = "Defender";
  s.year = 2024;

  cout << s.make << " " << s.model << " " << s.year << "\n";

  CAutomobile car;
// TODO
// Try to assign values to the make, model, and year of 'car' then output the values.


  return 0;
}