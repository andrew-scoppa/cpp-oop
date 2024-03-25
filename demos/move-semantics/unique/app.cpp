#include <iostream>
#include <memory>
#include <cassert>

class Num
{
private:
    int m_val = 0;
public:
    void Inc() {
        ++m_val;
    }
    void Show() const{
        std::cout << m_val << std::endl;
    }
};

std::unique_ptr<Num> Make(){
    std::unique_ptr<Num> m(new Num());
    return  std::move(m);
}

void Report(const std::unique_ptr<Num> n){
    n->Show();
}
int main(){

    std::unique_ptr<Num> m(new Num());
    m->Inc();
    Report(move(m));
    assert(m.get() == nullptr);

    std::unique_ptr<Num> n(Make());
    n->Show();



}