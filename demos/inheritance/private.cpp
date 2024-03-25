#include <iostream>
#include <ctime>

class TimeService
{
public:
    time_t CurrentTime()
    {
        return std::time(nullptr);
    }
};

class Geolocator : private TimeService
{
private:
    double _latitude = 0, _longitude = 0, _altitude = 0;
public:
    // add additional code to set latitude, longitude, and altitude...

    double Latitude() { return _latitude; }
    double Longitude() { return _longitude; }
    double Altitude() { return _altitude; }
    time_t Time()
    {
        return this->CurrentTime();
    }
};

int main()
{
    TimeService tp;
    std::cout << tp.CurrentTime() << std::endl;
}