#include <iostream>
using std::cout, std::endl;


void Copy(int a){
    cout << "Copy(unsigned int a): a = " << a << endl;
}

void Ref(int& a){
    cout << "Ref(int& a): a = " << a << endl;
}

// void Ref(int&& a){
//     cout << "Ref(int&& a): a = " << a << endl;
// }

int main(){
    int a = 10;
    
    enum   Color:int{RED, GREEN, BLUE};
    Color c = BLUE;

    Copy(a);
    Copy(c);

    Ref(a);
    //Ref(move(c));

    return 0;
}