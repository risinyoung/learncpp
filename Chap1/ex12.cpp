#include <iostream>
#include <float.h>
using namespace std;
int main()
{
    double x = DBL_MAX;
    double eps = DBL_EPSILON;

    double zero = 0.0;
    double y = 100.2;
    double z0 = x + x;
    double z1 = x * 2;
    double z2 = eps/9;
    double z3 = y/zero;
    double z4 = zero/zero;
    double z5 = z3 - z3;
    double z6 = x + y;

    cout << "outputting results:\n";
    cout << z0 << endl;
    cout << z1 << endl;
    cout << z2 << endl;
    cout << z3 << endl;
    cout << z4 << endl;
    cout << z5 << endl;
    cout << z6 << endl;
    cout << 1 + z2 << endl;
}