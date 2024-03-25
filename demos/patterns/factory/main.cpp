#include <iostream>
#include <string>

/*
 * IProduct implements the same interface so that the classes can refer
 * to the interface not the concrete product
 */
class IProduct
{
public:
 
  virtual std::string getName() const = 0;

  virtual ~IProduct() {}
};


class Bicycle : public IProduct
{
public:
  ~Bicycle() {}
  
  std::string getName() const
  {
    return "Bike";
  }

};


class Scooter : public IProduct
{
public:

  
  std::string getName() const
  {
    return "scooter";
  }

  ~Scooter() {}
};

/*
 * ICreator contains the interface for all of the methods
 * to manipulate products except for the factory method
 */
class ICreator
{
public:

  
  virtual IProduct* createBike() = 0;
  virtual IProduct* createScooter() = 0;
  
  virtual void removeProduct( IProduct *product ) = 0;
  
  virtual ~ICreator() {}
};

/*
 * Assembler implements factory method that is responsible for creating
 * one or more concrete products ie. it is class that has
 * the knowledge of how to create the products
 */
class Assembler : public ICreator
{
public:
  
  IProduct* createBike()
  {
    return new Bicycle();
  }
  
  IProduct* createScooter()
  {
    return new Scooter();
  }
  
  void removeProduct( IProduct *product )
  {
    delete product;
  }
  
  ~Assembler() {}
};


int main()
{
  ICreator *creator = new Assembler();
  
  IProduct *p1 = creator->createBike();
  std::cout << "IProduct: " << p1->getName() << std::endl;
  creator->removeProduct( p1 );
  
  IProduct *p2 = creator->createScooter();
  std::cout << "IProduct: " << p2->getName() << std::endl;
  creator->removeProduct( p2 );
  
  delete creator;
  return 0;
}
