#include <iostream>
#include "Mtx.h"
using namespace std;
int main(){
    int n = 500;
    Mtx a(n,n);
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            a[i][j] = 1/(i+j+1.0);

    Vtr t(n);                     //真实解
    Vtr x(n);
    for(int i = 0; i < n; i++) t[i] = 1/(i + 3.14);

    int iter = 300;
    double eps = 1e-9;
    Vtr b = a*t;
    int ret = a.CG(x, b, eps, iter);
    if(ret == 0) cout << "CG returned successfully" << endl;
    cout << "Iterations used in CG method: " << iter << endl;
    cout << "Residual : " << eps << endl;
    cout << "Two-norm of exact error vector : " << (t - x).twonorm() << endl;

}
