#include <ch4it.hpp>
double bisctn(double a, double b, double (*f)(double), double delta, double epsn){
    int static maxit = 1000;
    double u = f(a);
    double e = b - a;
    double c;

    for(int k = 1; k <= maxit; k++){
        e *= 0.5;
        c = a + e;
        double w = f(c);
        if(fabs(e) < delta || fabs(c) < epsn) return c;
        ((u>0 && w<0) || (u<0 && w>0)) ? (b=c) : (a=c, u=w);
    }
    return c;
}

double newton(double xp, pfn f, pfn fd, double delta, double epson){
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