#include <iostream>
// 这个程序本来不能运行，最后发现是mingw-w64的问题，删除了一个libstdc++的库文件就好了，是从一个stack-overflow上的答案
int main()
{
    using namespace std;
    int n;
    n = 10;
    double *a = new double [n];
    for(int i = 0; i < n; i++){
        a[i] = i;
    }

    for(int i = 0; i < n; i++){
        cout << a[i] << endl;
    }
}