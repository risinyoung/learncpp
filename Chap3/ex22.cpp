#include <cmath>
#include <iostream>
#include <cstdlib>
#include <cassert>

typedef double (*pfn)(double);
double trapezoidal(double a, double b, pfn f, int n);
double simpson(double a, double b, pfn f, int n);
inline double f(double d) { return exp(-pow(d,2)); }

int main(int argc, char *argv[])
{
    using namespace std;
    int n =100;
    double result = trapezoidal(0, 2, f, n);
    cout.precision(10);
    cout << "Integral e^(-x^2) using trapezoidal with n = " << n << " is: "
        << result << endl;

    result = simpson(0, 2, f, n);
    cout.precision(10);
    cout << "Integral e^(-x^2) using simpson with n = " << n << " is: "
        << result << endl;

    n =300;
    result = trapezoidal(0, 2, f, n);
    cout.precision(10);
    cout << "Integral e^(-x^2) using trapezoidal with n = " << n << " is: "
        << result << endl;

    result = simpson(0, 2, f, n);
    cout.precision(10);
    cout << "Integral e^(-x^2) using simpson with n = " << n << " is: "
        << result << endl;

    n =500;
    result = trapezoidal(0, 2, f, n);
    cout.precision(10);
    cout << "Integral e^(-x^2) using trapezoidal with n = " << n << " is: "
        << result << endl;

    result = simpson(0, 2, f, n);
    cout.precision(10);
    cout << "Integral e^(-x^2) using simpson with n = " << n << " is: "
        << result << endl;
    
}

double trapezoidal(double a, double b, pfn f, int n)
{
    double h = (b - a)/n;
    double sum = f(a)*0.5;
    for(int i = 1; i < n; i++) sum += f(a + i*h);
    sum += f(b)*0.5;
    return sum*h;
}

double simpson(double a, double b, pfn f, int n)
{
    double h = (b - a)/n;
    double sum = f(a)*0.5;
    for(int i = 1; i < n; i++) sum += f(a + i*h);
    sum += f(b)*0.5;
    
    double summid = 0;
    for(int i = 1; i <= n; i++) summid += f(a + (i - 0.5)*h);
    return (sum + 2*summid)*h/3;
}