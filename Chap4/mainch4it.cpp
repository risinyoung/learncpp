#include "ch4it.hpp"

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

double f(double x){
    return ((x - 5)*x + 3)*x + 7;
}

double fder(double x){
    return (3*x - 10)*x +3;
}

int main(){
    
    cout << "Test bisection method" << endl;
  
    double root = bisctn(1e-2, 1, fa, delta, epsn);   
    cout << "Approximate root of fa() is " << root << endl;
    cout << "Residual is " << fa(root) << endl;

    root = bisctn(1, 3, fb, delta, epsn);
    cout << "Approximate root of fa() is " << root << endl;
    cout << "Residual is " << fb(root) << endl;

    root = bisctn(0, 4, fc, delta, epsn);
    cout << "Approximate root of fa() is " << root << endl;
    cout << "Residual is " << fc(root) << endl;

    cout << endl;
    cout << "Test newton method" << endl;

    root = newton(5, f, fder, 1e-8, 1e-9);
    cout << "Approximate root of fa() is " << root << endl;
    cout << "Residual is " << f(root) << endl;

}