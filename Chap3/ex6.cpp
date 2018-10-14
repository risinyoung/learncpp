#include <cmath>
#include <iostream>
int main()
{
    using namespace std;
    double b;
    cin >> b;
    int n;
    cin >> n;
    double pre = sqrt(b);
    cout << pre << endl;
    double x0 = 1;
    double x;
    double er = 1;
    for(int i = 0; i < n; i++){
        x = (x0 + b/x0)/2;
        cout.width(10);
        cout << x - pre;
        cout.width(10);
        cout << pow(er,2)/abs(x - x0) << endl;
        er = abs(x - x0);
        x0 = x;
    }
}