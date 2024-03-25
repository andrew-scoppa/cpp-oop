#include <iostream>

using namespace std;

class Animal
{
public:
  int m_weight;

  Animal(int weight);
  Animal();
  virtual ~Animal();
};

Animal::Animal(int weight)
    : m_weight(weight)
{
  cout << "Animal(weight=" << weight << ")\n";
}

Animal::Animal()
{
  cout << "Animal()\n";
}

Animal::~Animal()
{
  cout << "~Animal()\n";
}

class FlyingAnimal : public virtual Animal
{
public:
  int m_wingSpan;

  FlyingAnimal();
  FlyingAnimal(int weight, int wingSpan);
  virtual ~FlyingAnimal();
};

FlyingAnimal::FlyingAnimal()
    : m_wingSpan(0)
{
  cout << "FlyingAnimal()\n";
}

FlyingAnimal::FlyingAnimal(int weight, int wingSpan)
    : Animal(weight),
      m_wingSpan(wingSpan)
{
  cout << "FlyingAnimal(weight=" << weight << ", wingSpan=" << wingSpan << ")\n";
}

FlyingAnimal::~FlyingAnimal()
{
  cout << "~FlyingAnimal()\n";
}

class ZooAnimal : public virtual Animal
{
public:
  int m_minCageArea;

  ZooAnimal();
  ZooAnimal(int weight, int minCageArea);
  virtual ~ZooAnimal();
};

ZooAnimal::ZooAnimal()
    : m_minCageArea(0)
{
  cout << "ZooAnimal()\n";
}

ZooAnimal::ZooAnimal(int weight, int minCageArea)
    : Animal(weight), m_minCageArea(minCageArea)
{
  cout << "ZooAnimal(weight=" << weight << ", minCageArea=" << minCageArea << ")\n";
}

ZooAnimal::~ZooAnimal()
{
  cout << "~ZooAnimal()\n";
}

class Eagle : public ZooAnimal, public FlyingAnimal
{
public:
  Eagle();
  Eagle(int weight, int minCageArea, int wingSpan);
  ~Eagle();
};

Eagle::Eagle()
{
  cout << "Eagle()\n";
}

Eagle::Eagle(int weight, int minCageArea, int wingSpan)
    : Animal(weight),
      ZooAnimal(weight, minCageArea),
      FlyingAnimal(weight, wingSpan)
{
  cout << "Eagle(weight=" << weight
       << ", minCageArea=" << minCageArea
       << ", wingSpan=" << wingSpan << ")\n";
}

Eagle::~Eagle()
{
  cout << "~Eagle()\n";
}

int main()
{
  ZooAnimal z1;
  ZooAnimal z2(120, 100);

  FlyingAnimal f1;
  FlyingAnimal f2(200, 1);

  Eagle e1;
  Eagle e2(25, 500, 6);

  cin.get();
}
