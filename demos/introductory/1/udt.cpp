#include <iostream>

using namespace std;

class SAutomobile
{
public:
  string make;
  int year;

//setter
  void setModel(string model){
    m_model = model;
  }
//getter
  string getModel(){
    return this->m_model;
  }
private:
  string m_model = "tbd";
};


int main()
{
  SAutomobile s;
  s.make = "Land Rover";
  s.setModel("discovery");
  s.year = 2020;


  cout << s.make << " " << s.getModel() << " " << s.year << "\n";

  return 0;
}
