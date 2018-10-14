#include <math.h>
#include <iostream>
using namespace std;
int main(){
    float fpi = atan(1)*4;
    double dpi = atan(1)*4;
    long double ldpi = atan(1)*4;

    cout.precision(30);
    cout.width(30);
    cout << fpi << endl;
    cout.width(30);
    cout << dpi << endl;
    cout.width(30);
    cout << ldpi << endl;
}