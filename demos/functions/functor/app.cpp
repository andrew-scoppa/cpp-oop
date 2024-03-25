#include <iostream>

class OnOffSwitch{
private:
    bool _val = false;
public:
    void Toggle(){
        _val = !_val;
    }
    bool operator()(){
        return _val;
    }
};

int main(){
    OnOffSwitch onOff;
    onOff.Toggle();
    std::cout << (onOff() ? "On" : "Off") << std::endl;

}
