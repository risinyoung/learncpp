#include <iostream>

double* mxvrmy(const double * const * const mx, double* const vr,
    int n, int m)
{
    double* tmv = new double [n];
    for(int i = 0; i < n; i++){
        tmv[i] = 0;
        for(int j = 0; j < m; j++)
            tmv[i] += mx[i][j]*vr[j];
    }
    return tmv;
}

int main()
{
    using namespace std;
    int n = 100;
    int m = 200;
    double** a = new double* [n];
    for(int i = 0; i < n; i++) a[i] = new double [m];
    double* b = new double [m];
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++) a[i][j] = i*i +j;
    
    for(int j = 0; j < m; j++) b[j] = j;
    double* c = mxvrmy(a, b, n, m);
    double sum = 0;
    for(int j = 0; j < m; j++) sum += c[j];
    cout << sum << endl;
    for(int i = 0; i < n; i++) delete[] a[i];
    delete[] a;
    delete[] b;
    delete[] c;
}

