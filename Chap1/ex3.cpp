#include <iostream>
#include <cmath>
using namespace std;
int main()
{
    double sum = 0;
    for(double d = 1.1; d <= 15.5; d+=1) sum += exp(d);
    cout << sum << endl;
}