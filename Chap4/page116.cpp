#include "Vec_Mat.hpp"
#include <iostream>

int main(){
    int n = 1000;
    double ** a = new double * [n];
    for(int i = 0; i < n; i++) a[i] = new double  [n];
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            a[i][j] = 1.0/(i + j + 1);
    std::cout << Mat::maxnorm(a, n) << std::endl;
    std::cout << Vec::maxnorm(a[2], n) << std::endl;
}