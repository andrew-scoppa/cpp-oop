#include <iostream>
#include <memory>



class Widget{
public:
    void Show() const{
        std::cout << "Here is the data..." << std::endl;
    }
};

int main(){
    const size_t count = 5;
    std::unique_ptr<Widget[]> w(new Widget[count]);
    
    for (size_t i = 0; i < count; i++)
    {
       w[i].Show();
    }
    
}