#include <iostream>

using namespace std;

class FlyingAnimal
{
public:
  int m_wingSpan;

  FlyingAnimal();
  FlyingAnimal(int wingSpan);
  virtual ~FlyingAnimal();
};

class ZooAnimal
{
public:
  int m_minCageArea;

  ZooAnimal();
  ZooAnimal(int minCageArea);
  virtual ~ZooAnimal();
};

class Eagle : public ZooAnimal, public FlyingAnimal
{
public:
  Eagle();
  Eagle(int minCageArea, int wingSpan);
  ~Eagle();
};

// member function implementations
// ...

int main()
{
  // tests
  // ...
}
