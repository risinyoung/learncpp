#include <iostream>
using namespace std;
int main()
{
    int n,m;
    cout << "Enter two integers:" << endl;
    cin >> n >> m;
    if(n>m)
    {
        int temp = n;
        n = m;
        m = temp;
    }
    double sum = 0.0;
    for(int i = n; i <= m; i++)
    {
        sum += i;
    }
    cout << "Sum of integers from " << n << " to " << m
    << " is " << sum << endl;
}