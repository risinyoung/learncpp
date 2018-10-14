#include <cmath>
#include <iostream>
#include <cstdlib>
#include <cassert>

typedef double (*pfn)(double);
double trapezoidal(double a, double b, pfn f, int n);
double simpson(double a, double b, pfn f, int n);
inline double square(double d) { return d*d; }

int main(int argc, char *argv[])
{
    using namespace std;
    assert(argc > 1);
    int n = atoi(argv[1]);
    assert(n > 0);
    double result = trapezoidal(0, 5, square, n);
    cout << "Integral square using trapezoidal with n = " << n << " is: "
        << result << endl;

    result = simpson(0, 5, square, n);
    cout << "Integral square using simpson with n = " << n << " is: "
        << result << endl;
    
    cout << "True integeral square is " << pow(5.0,3)/3 << endl << endl;

    result = trapezoidal(0, 5, sqrt, n);
    cout << "Integral sqrt using trapezoidal with n = " << n << " is: "
        << result << endl;

    result = simpson(0, 5, sqrt, n);
    cout << "Integral sqrt using simpson with n = " << n << " is: "
        << result << endl;

    cout << "True integeral sqrt is " << pow(5.0,3.0/2)*2/3 << endl << endl;
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