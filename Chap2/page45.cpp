#include <iostream>
using namespace std;
int main()
{
    long fp = 1;
    long fc = 1;
    cout.width(2);
    cout << "n";
    cout.width(20);
    cout << "Fibonacci number";
    cout.width(30);
    cout << "Fibonacci quotient" << endl;
    cout.precision(20);

    for(int i = 2; i <= 40; i++)
    {
        cout.width(2);
        cout << i;
        cout.width(20);
        cout << fc;
        cout.width(30);
        cout << (long double)fc/fp << endl;
        long tmp = fc;
        fc += fp;
        fp = tmp;
        
    }
}