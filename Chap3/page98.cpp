#include <iostream>
#include <cmath>

int main()
{
    double eval(const double* const , int, double);
    double horner(const double* const , int, double);
    using namespace std;
    double a[9] = {1, -8, 28, -56, 70, -56, 28, -8, 1};
    for(double x = 0.99999; x <= 1.0001; x += 1.0e-5){
        cout.width(18);
        cout << eval(a, 8, x);
        cout.width(18);
        cout << horner(a, 8, x);
        cout.width(18);
        cout << pow(x-1, 8) ;
        cout.width(20);
        cout << 1.0e10*(pow(x-1,8) - eval(a,8,x));
        cout.width(20);
        cout << 1.0e10*(pow(x-1,8) - horner(a,8,x)) << endl;
    }
}

double eval(const double* const a, int n, double x)
{
    double sum = 0;
    for(int k = n; k >= 0; k--){
        sum += a[k]*pow(x, k);
    }
    return sum;
}

double horner(const double* const a, int n, double x)
{
    double u = a[n];
    for(int i = n-1; i >= 0; i--) u = u*x + a[i];
    return u;
}