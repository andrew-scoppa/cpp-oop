#include <iostream>

using namespace std;

class Device
{
private:
  int _id;

protected:
  Device(int id) : _id(id) { 
    cout << "Constructing device " << id << endl;
   }
  int GetId() const { return _id; }

public:
  virtual ~Device()
  {
    cout << "Detroying Device" << endl;
  }
};

class IRechargable
{
public:
  IRechargable(){
        cout << "Constructing rechargeable interface." << endl;
  }
  virtual void Recharge() const = 0;
  virtual ~IRechargable()
  {
    cout << "Detroying IRechargable" << endl;
  }
};

class CellPhone : public virtual Device, public virtual IRechargable
{
public:
  CellPhone(int id) : Device::Device(id){
    cout << "Constructing cell phone " << id << endl;
  };
  void Recharge() const
  {
    cout << "Recharging cell phone " << GetId() << endl;
  }
  ~CellPhone()
  {
    cout << "Detroying CellPhone" << endl;
  }
};

class Tablet : public virtual Device, public virtual IRechargable
{
public:
  Tablet(int id) : Device::Device(id){
    cout << "Constructing tablet " << id << endl;
  };
  void Recharge() const
  {
    cout << "Recharging cell tablet " << GetId() << endl;
  }
  ~Tablet()
  {
    cout << "Detroying Tablet" << endl;
  }
};

int main()
{
  const int count = 2;
  IRechargable *devices[2]{new CellPhone(10), new Tablet(11)};
  IRechargable **pDevice = devices;

  for (int i = 0; i < count; i++)
  {
    pDevice[i]->Recharge();
  }
  

  // cleanup

  for (int i = 0; i < count; i++)
  {
    delete pDevice[i];
    pDevice[i] = nullptr;
  }
  

  cout << "Finished " << endl;
}