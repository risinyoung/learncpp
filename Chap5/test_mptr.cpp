#include <iostream>
class A{
    public:
    int x;
};

int main()
{
    using namespace std;
    A p,q;
    p.x = 1;
    q.x = 2;
    int A::*a;
    a = &A::x;
    cout << p.*a << endl;
    cout << q.*a << endl;
}