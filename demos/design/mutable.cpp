#include <iostream>
#include <cmath>
using namespace std;

class DeviceMonitor
{
private:
    const double _threshold = 100;
    mutable double _charge;
    double _potential, _capacitance;
    void CheckCapacitance() const
    {
        // possibly to safely alter charge
    }
public:
    bool IsCharged() const
    {
        CheckCapacitance();
        return (_capacitance < _threshold);
    }
};