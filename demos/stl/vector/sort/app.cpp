#include <iostream>
#include <vector>
#include <algorithm>

struct Part
{
    int _SKU;
    std::string _name;
    double _price;
    bool operator<(const Part &rhs) const
    {
        return this->_SKU < rhs._SKU;
    }
    bool operator>(const Part &rhs) const
    {
        return this->_SKU > rhs._SKU;
    }
};

void print(std::vector<Part> parts)
{
    for (auto it = parts.begin(); it < parts.end(); ++it)
    {
        std::cout << it->_SKU << '\t' << it->_name << '\t' << it->_price << std::endl;
    }
    std::cout << std::endl;
}

bool SortNameDesc(const Part &lhs, const Part &rhs)
{
    return lhs._name > rhs._name;
}

struct SortNameAsc
{
    bool operator()(const Part &lhs, const Part &rhs)
    {
        return lhs._name < rhs._name;
    }
};

int main()
{
    std::vector<Part> parts;
    parts.push_back(Part{10, "AWIDGET-01", 12.99});
    parts.push_back(Part{12, "AWIDGET-29", 13.99});
    parts.push_back(Part{05, "AWIDGET-91", 15.99});

    std::sort(parts.begin(), parts.end(), std::greater<Part>());
    print(parts);

    std::sort(parts.begin(), parts.end(), [](const Part &lhs, const Part &rhs)
              { return lhs._price < rhs._price; });

    print(parts);

    std::sort(parts.begin(), parts.end(), SortNameAsc());

    print(parts);

    std::sort(parts.begin(), parts.end(), SortNameDesc);

    print(parts);

    return 0;
}