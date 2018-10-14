#include <iostream>
int main()
{
    using namespace std;
    union val 
    {
        int i;
        double d;
        char c;
    };

    val x;
    x.i = 5;
    cout << x.i << " " << x.d << " " << x.c << endl;

    x.d = 6.28;
    cout << x.i << " " << x.d << " " << x.c << endl;
    
    x.c = 'G';
    cout << x.i << " " << x.d << " " << x.c << endl;
}