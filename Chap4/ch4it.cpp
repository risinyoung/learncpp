#include <ch4it.hpp>
double bisctn(double a, double b, double (*f)(double), double delta, double epsn){
    int static maxit = 10000;
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

double fa(double x){
    if(x) return 1.0/x - pow(2,x);
    else{
        cout << "division by zero occurred in function fa()" << endl;
        exit(1);
    }
}

double fb(double x){
    return pow(2, -x) + exp(x) + 2*cos(x) -6;
}

double fc(double x){
    double denorm = ((2*x - 9)*x + 18)*x - 2;
    if(denorm) return (((x + 4)*x + 3)*x - 5);
    else{
        cout << "division by zero occurred in function fa()" << endl;
        exit(1);
    }
}