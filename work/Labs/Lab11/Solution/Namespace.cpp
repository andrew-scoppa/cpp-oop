#include <iostream>

using namespace std;


namespace Tool
{
  class Mallet
  {
   public:
    void pound();
  };
  
  void Mallet::pound()
  {
    cout << "pound mallet\n"; 
  }
}


namespace Tool
{
  class Saw
  {
   public:
    void cut();
  };
  
  void Saw::cut()
  {
    cout << "cut with saw\n"; 
  }
}

namespace Tool
{
  class Plane
  {
   public:
    void trim();
  };

  void Plane::trim()
  {
    cout << "trim with plane\n"; 
  }
}


namespace Transport
{
  class Plane
  {
   public:
    void fly();
  };

  void Plane::fly()
  {
    cout << "fly plane\n"; 
  }
}

namespace Transport
{
  class Truck
  {
   public:
    void drive();
  };

  void Truck::drive()
  {
    cout << "drive truck\n"; 
  }
}

namespace Transport
{
  class Ship
  {
   public:
    void sail();
  };

  void Ship::sail()
  {
    cout << "sail ship\n"; 
  }
}


//using Transport::Plane;
//using Tool::Plane;

using namespace Transport;
using namespace Tool;

int main()
{
  /*
  Tool::Mallet m1;
  Tool::Saw    s1;
  Tool::Plane  p1;

  Transport::Plane p2;
  Transport::Truck t2;
  Transport::Ship  s2;
  */

  Mallet m1;
  Saw    s1;
  Tool::Plane  p1;

  Transport::Plane p2;
  Truck t2;
  Ship  s2;


  m1.pound();
  s1.cut();
  p1.trim();

  p2.fly();
  t2.drive();
  s2.sail();

  return 0;
}
