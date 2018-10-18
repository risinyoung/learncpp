#include <iostream>
#include <ctime>
#include <cstdlib>
#include <algorithm>

#ifdef __cplusplus
using namespace std;
#endif

int main(){
    
    int n = 100000;
    double * dp = new double [n];

    srand(time(0));
    for(int i = 0; i < n; i++) dp[i] = rand()%1000;

    sort(dp, dp + n);
}
