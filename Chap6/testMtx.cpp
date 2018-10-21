#include "Mtx.h"
int main(){
    using namespace std;
    int k = 2;
    // double ** mt = new double * [k];
    // for(int i = 0; i < k; i++) mt[i] = new double [k];
    // for(int i = 0; i < k; i++)
    //     for(int j = 0; j < k; j++)
    //         mt[i][j] = 2*i*j + i + 10;

    // Mtx m1(k, k, mt);
    // Mtx m2(k, k, 5);
    Mtx m3(k,k);
    for(int i = 0; i < k; i++)
        for(int j =0; j < k; j++) m3(i,j) = i+j;
    
    // // m3 += -m1 + m2;
    // m1 -= m3;

    Vtr vv(k);
    for(int i = 0; i < k; i++) vv[i] = 1;
    // vv = m3*vv;
    // cout << vv << endl;
    // vv = vv - 0.1*vv;
    // cout << vv << endl;
    cout << vv << endl;
    cout << dot(vv,vv) << endl;
    cout << vv.twonorm();
}