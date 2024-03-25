#include <iostream>
#include <string>

/*
 * IProduct
 * the final object that will be created using Builder
 */
class IProduct
{
public:
  void makeA( const std::string &part )
  {
    _partA = part;
  }
  void makeB( const std::string &part )
  {
    _partB = part;
  }
  void makeC( const std::string &part )
  {
    _partC = part;
  }
  std::string get() const
  {
    return (_partA + " " + _partB + " " + _partC);
  }
  // ...
  
private:
  std::string _partA;
  std::string _partB;
  std::string _partC;
  // ...
};

/*
 * Builder
 * abstract interface for creating products
 */
class Builder
{
public:

  
  IProduct get() const
  {
    return _product;
  }
  
  virtual void buildPartA() = 0;
  virtual void buildPartB() = 0;
  virtual void buildPartC() = 0;
  virtual ~Builder() {}
protected:
  IProduct _product;
};

/*
 * Concrete Builder X and Y
 * create real products and stores them in the composite structure
 */
class Automobile : public Builder
{
public:
  void buildPartA()
  {
    _product.makeA( "Engine" );
  }
  void buildPartB()
  {
    _product.makeB( "Body" );
  }
  void buildPartC()
  {
    _product.makeC( "Paint" );
  }
  // ...
};


/*
 * Director
 * responsible for managing the correct sequence of object creation
 */
class Director {
public:
  Director() : _builder() {}
  
  void set( Builder *b )
  {
    if ( _builder != nullptr)
    {
      delete _builder;
    }
    _builder = b;
  }
  
  IProduct get() const
  {
    return _builder->get();
  }
  
  void construct()
  {
    _builder->buildPartA();
    _builder->buildPartB();
    _builder->buildPartC();

  }
  ~Director()
  {
    if ( _builder != nullptr)
    {
      delete _builder;
    }
  }
 private:
  Builder *_builder;
};


int main()
{
  Director director;
  director.set( new Automobile );
  director.construct();
  
  IProduct car = director.get();
  std::cout << "Car parts: " << car.get() << std::endl;
  
  return 0;
}
