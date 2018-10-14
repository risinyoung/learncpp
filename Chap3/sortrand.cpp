#include <iostream>
#include <ctime>
#include <cstdlib>
#include <algorithm>

int main()
{
    using namespace std;
    int n = 100000;
    double *dp = new double[n];
    srand(time(0));
    for(int i = 0; i < n; i++) dp[i] = rand()%1000;

    sort(dp, dp + n);
}