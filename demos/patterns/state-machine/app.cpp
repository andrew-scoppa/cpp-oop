#include <iostream>
#include <map>
#include <stdexcept>
#include <string>
#include <fstream>

using std::map;
using std::string;

class Order
{
private:
    // insert nested classes here

    // Nested base class OrderState
    class OrderState
    {
    protected:
        Order *_order = nullptr;

    public:
        OrderState(Order *order)
        {
            this->_order = order;
        }

        virtual void Log(std::fstream &fs, string detail)
        {
            // no throw - not coupled to any state
            fs << detail << std::endl;
        }
        virtual void RetrieveCart()
        {
            throw std::logic_error("Not allowed to retrieve cart in current state");
        }
        virtual void SelectorTransition()
        {
            throw std::logic_error("Not allowed to transition to selector in current state");
        }
        virtual void AddItem(string isbn, int quantity)
        {
            throw std::logic_error("Not allowed to add a book in current state");
        }
        virtual void CheckoutTransition()
        {
            throw std::logic_error("Not allowed transition to checkout in current state");
        }
        virtual void ProcessPayment()
        {
            throw std::logic_error("Not allowed to place order in current state");
        }
        virtual std::string GetReceipt()
        {
            throw std::logic_error("Not allowed to place retrieve receipt in current state");
        }
    };

    // Nested subclass SelectorState
    class SelectorState : public OrderState
    {
    public:
        SelectorState(Order *order) : OrderState(order) {}

        void AddItem(string SKU, int quantity) override
        {
            _order->_itemTable->insert({SKU, quantity});
        }

        void CheckoutTransition() override
        {
            if (_order->_itemTable->size() > 0)
            {
                _order->SetState(_order->_checkoutState);
            }
        }
    };

    // Nested subclass CheckinState
    class CheckinState : public OrderState
    {
    public:
        CheckinState(Order *order) : OrderState(order) {}
        void RetrieveCart() override
        {
            // some authentication here
        }
        void SelectorTransition() override
        {
            _order->SetState(_order->_selectorState);
        }
    };

    // Nested subclass CheckoutState
    class CheckoutState : public OrderState
    {
    public:
        CheckoutState(Order *order) : OrderState(order) {}
        void ProcessPayment() override
        {
            // process items in map...
        }

        string GetReceipt() override
        {
            std::string receipt = "SKU\tQUANTITY\n";
            for (auto it = _order->_itemTable->begin(); it != _order->_itemTable->end(); ++it)
            {
                receipt += it->first + "\t" + std::to_string(it->second);
                receipt += "\n";
            }
            return receipt;
        }
    };

    // other Order members here
private:
    void SetState(OrderState *orderState)
    {
        _orderState = orderState;
    }

    OrderState *_orderState = nullptr;
    CheckinState *_checkinState = nullptr;
    SelectorState *_selectorState = nullptr;
    CheckoutState *_checkoutState = nullptr;
    map<string, int> *_itemTable = nullptr;

public:
    Order()
    {
        _itemTable = new map<string, int>;
        _checkinState = new CheckinState(this);
        _selectorState = new SelectorState(this);
        _checkoutState = new CheckoutState(this);

        SetState(_checkinState);
    }

    void Begin()
    {
        _orderState->RetrieveCart();
        _orderState->SelectorTransition();
    }

    void SelectItem(string SKU, int quantity)
    {
        _orderState->AddItem(SKU, quantity);
    }

    void Checkout()
    {
        _orderState->CheckoutTransition();
        _orderState->ProcessPayment();
    }

    void PrintReceipt()
    {
        std::string receipt = _orderState->GetReceipt();
        std::cout << receipt << std::endl;
    }

    void Log(std::string filename, std::string details)
    {
        std::fstream ofs(filename, std::ios::app | std::ios::out);
        _orderState->Log(ofs, details);
        ofs.close();
    }

    ~Order()
    {
        delete _itemTable;
        delete _checkinState;
        delete _selectorState;
        delete _checkoutState;
    }
};

int main()
{
    Order order;
    std::string logfile = "logfile.txt";
    try
    {

        order.Begin();
        
        order.SelectItem("A121", 10);
        order.SelectItem("C122", 30);
        order.SelectItem("C123", 15);

        order.Checkout();
        order.PrintReceipt();
    }
    catch (const std::exception &e)
    {
        order.Log(logfile, e.what());
        std::cerr << e.what() << '\n';
        exit(EXIT_FAILURE);
    }

    return 0;
}