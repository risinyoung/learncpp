#ifndef ODE_H_
#define ODE_H_
#include <iostream>
#include <cmath>
#include <algorithm>
#include <functional>
#include "ch4it.hpp"
class ode {
    double tini;
    double ison;
    double tend;
    double (*sfn)(double, double);
    double (*sfnder)(double,double);

    public:
    ode(double t0, double x0, double T, double (*f)(double, double),double (*fder)(double,double) = nullptr):tini(t0),ison(x0),tend(T),sfn(f),sfnder(fder){}

    double *euler(int) const;
    double *eulerpc(int) const;
    double *eulerim(int) const;
    double *rk2(int) const;
    double *rk4(int) const;
};

double *ode::euler(int n) const{
    double *x = new double [n+1];
    x[0] = ison;
    double h = (tend - tini)/n;
    for(int i = 0; i < n; i++){
        x[i+1] = x[i] + h*sfn(tini + i*h, x[i]);
    }
    return x;
}

double *ode::eulerpc(int n) const{
    double *x = new double [n+1];
    x[0] = ison;
    double h = (tend - tini)/n;
    for(int i = 0; i < n; i++){
        double xrpc = x[i] + h*sfn(tini + i*h,x[i]);
        x[i+1] = x[i] + h*sfn(tini + i*h, x[i]);
    }
    return x;
}

double *ode::eulerim(int n) const{
    double *x = new double [n+1];
    x[0] = ison;
    double h = (tend - tini)/n;
    for(int i = 0; i < n; i++){
        function<double(double)> f_ =  [=,&x](double y) -> double{
             return x[i] + h*((*(this->sfn))((tini + i*h), y)) - y;
            };
        function<double(double)> fder_ =  [=,&x](double y) -> double{
             return  h*((*(this->sfnder))((tini + i*h), y)) - 1;
            };
        x[i + 1] = newton(x[i], f_, fder_);
        
    }
    return x;
}

double *ode::rk2(int n) const{
    double *x = new double [n+1];
    x[0] = ison;
    double h = (tend - tini)/n;
    for(int i = 0; i < n; i++){
        double tp = tini + i*h;
        double f = h*sfn(tp,x[i]);
        x[i+1] = x[i] + 0.5*(f + h*sfn(tp + h, x[i] + f));
    }
    return x;
}

double *ode::rk4(int n) const{
    double *x = new double [n+1];
    x[0] = ison;
    double h = (tend - tini)/n;
    for(int i = 0; i < n; i++){
        double f1 = sfn(tini +  i*h, x[i]);
        double tp = tini +  (i + 0.5)*h;
        double f2 = sfn(tp, x[i] + h*f1/2);
        double f3 = sfn(tp, x[i] + h*f2/2);
        double f4 = sfn(tini +  (i+1)*h, x[i] + h*f3);
        x[i+1] = x[i] + h*(f1 + 2*f2 + 2*f3 + f4)/6;
    }
    return x;
}
#endif