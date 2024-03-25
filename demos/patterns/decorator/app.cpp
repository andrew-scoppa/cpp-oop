// Decorator
#include <iostream>
#include <chrono>
#include <thread>

class IWidget
{
public:
    virtual void run() = 0;
    virtual ~IWidget() {}
};

class Gadget final : public IWidget
{
public:
    virtual void run() override
    {
        std::cout << "Gadget running..." << std::endl;
        std::this_thread::sleep_for(std::chrono::seconds(3));
    }
};

class WidgetDecorator : public IWidget
{
public:
    WidgetDecorator(IWidget &target)
        : _root(target)
    {
    }

    virtual void run() override
    {
        // Do something else here to decorate
        std::cout << "Getting ready to run..." << std::endl;
        _root.run();
        std::cout << "finished running!";
    }

private:
    IWidget &_root;
};

void Invoker(IWidget &widget)
{
    widget.run();
}

int main()
{
    Gadget g;
    WidgetDecorator decorated{g};

    Invoker(decorated);
}
