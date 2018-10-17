#include "ch4it.hpp"
int main(){
    double root = bisctn(1e-2, 1, fa, delta, epsn);
    cout << "Approximate root of fa() is " << root << endl;
    cout << "Residual is " << fa(root) << endl;

    root = bisctn(1, 3, fb, delta, epsn);
    cout << "Approximate root of fa() is " << root << endl;
    cout << "Residual is " << fb(root) << endl;

    root = bisctn(0, 4, fc, delta, epsn);
    cout << "Approximate root of fa() is " << root << endl;
    cout << "Residual is " << fc(root) << endl;

}