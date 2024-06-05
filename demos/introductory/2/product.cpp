#include <string>
#include <iostream>

class Product {
private:
    static int next_id;
    int id;
    std::string name;
    double price;

public:
    // Default constructor
    Product() : id(next_id++), name(""), price(0.0) {}

    Product(const std::string& name, double price) : id(next_id++), name(name), price(price) {}

    // Getters
    int getId() const { return id; }
    std::string getName() const { return name; }
    double getPrice() const { return price; }

    // Setters
    void setName(const std::string& name) { this->name = name; }
    void setPrice(double price) { this->price = price; }
};

// Initialize static member
int Product::next_id = 1;

int main()
{
    // create an array of 5 pointers to product
    Product* products[5];

    // create 5 new products and store their addresses in the array
    products[0] = new Product("Apple", 0.99);
    products[1] = new Product("Banana", 0.59);
    products[2] = new Product("Carrot", 0.49);
    products[3] = new Product("Donut", 1.99);
    products[4] = new Product("Eggplant", 1.49);

    // print the products
    int size = sizeof(products) / sizeof(products[0]);
    for (int i = 0; i < size; i++)
    {
        std::cout << "Product " << products[i]->getId() << ": " << products[i]->getName() << " $" << products[i]->getPrice() << std::endl;
    }   

    // delete the products
    for (int i = 0; i < size; i++)
    {
        delete products[i];
    }

    return 0;
}