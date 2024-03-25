#include <iostream>

using namespace std;

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
  s.year = 2020;

  cout << s.make << " " << s.model << " " << s.year << "\n";

  CAutomobile c;
// TODO
// Assign values to the make, model, and year of c then output the values.
// Try to compile...
 
  return 0;
}