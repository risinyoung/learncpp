#pragma once
#include <iostream>
#include <cmath>
#include <cstdlib>
using namespace std;

typedef double (*pfn)(double);
double bisctn(double, double, pfn, double delta = 1e-8, double epsn = 1e-9);

template<class Fo>
double newton(double xp, Fo f, Fo fd, double delta = 1e-8, double epsn = 1e-9){
    static int mxt = 500;
    double v = f(xp);
    double xnew;
    for(int k = 1; k <= mxt; k++){
        double derv = fd(xp);
        if(!derv){
            cout << "Division by 0 occurated in newton()" << endl;
            exit(1);
        }
        xnew = xp - v/derv;
        v = f(xnew);
        if(fabs(xnew - xp) < delta || fabs(v) < epsn) return xnew;
        xp = xnew;
    }
    return xnew;
}

double fa(double);
double fb(double);
double fc(double);