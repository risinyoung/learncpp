#include <iostream>
int square(int a) {return a*a;}
int (*f)(int a);

int main()
{
    using namespace std;
    f = &square;
    cout << f(2);
    cout << endl << square(2) << endl;
    cout << f <<  endl << &f <<endl;
    cout << square << endl << &square << endl;
    cout << endl;
    cout << (&square)(2) << endl;
}