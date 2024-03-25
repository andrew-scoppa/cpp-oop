#include <iostream>

using namespace std;

class DiscriminatedUnion
{
public:
    DiscriminatedUnion(int var)
        : type(Integer), _int(var) {}

    DiscriminatedUnion(float var)
        : type(Float), _float(var) {}

    enum
    {
        Integer,
        Float,
    } type;

    union {
        int _int;
        float _float;
        char _char[4];
    };
};

int main()
{
    DiscriminatedUnion du(0x41);
    cout << du._int << endl;
    cout << du._float << endl;
    cout << du._char[0] << du._char[1] << du._char[2] << du._char[3] << endl;
    return 0;
}