#include "ch4it.hpp"
double f(double x){
    return 1 - x - exp(-x);
}

double fder(double x){
    return -1 + exp(-x);
}

double g(double x){
    return tan(x) - x;
}

double gder(double x){
    return 1/(cos(x)*cos(x)) - 1;
}

int main(){
    
    double root = newton(1, f, fder, 1e-8, 1e-9);
    cout << "Approximate root of f() near 1 is " << root << endl;
    cout << "Residual is " << f(root) << endl;

    root = newton(4.5, g, gder, 1e-8, 1e-9);
    cout << "Approximate root of g() near 4.5 is " << root << endl;
    cout << "Residual is " << g(root) << endl;

    root = newton(5, g, gder, 1e-8, 1e-9);
    cout << "Approximate root of g() near 5 is " << root << endl;
    cout << "Residual is " << g(root) << endl;
}