#include <iostream>

using namespace std;

class Canvas;

class Window
{
private:
    double m_opacity;

public:
    Window()
    {
        m_opacity = .5;
    }
    double Get() const{
        return m_opacity;
    }
    friend class Canvas;
};

class Canvas{
    private:
    public:
    void WindowOpacity(Window &w, double o){
        w.m_opacity = o;
    }
};

int main(){
    Window w;
    Canvas c;
    c.WindowOpacity(w,.5);
    cout << w.Get() << endl;
}