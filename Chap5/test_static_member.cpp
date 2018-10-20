#include <iostream>
using namespace std;
class A{
    static int b;
    public:
    static int a;
};

class B: public A{
    static int a;
};
int A::a = 1;
int B::a = 3;
int main(){
    A A1,A2;
    cout << A1.a << endl;
    cout << A2.a << endl;
    cout << A::a << endl;
    cout << endl;
    B b1;
    // cout << b1.a << endl;
    // cout << B::a << endl;
    // b1.a = 2;
    // cout << b1.a << endl;
    // cout << A1.a << endl;
    cout << b1.A::a << endl;
}