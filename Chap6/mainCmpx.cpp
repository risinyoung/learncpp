/* 书中 207 页的程序，用来测试 Cmpx 类 */
#include "Cmpx.h"
int main(){
    using namespace std;
    Cmpx a(1,1);
    Cmpx b = a;
    Cmpx c = a + b;
    c -= b;
    cout << c << endl;
    c = -b;
    cout << -c + a*b << endl;
}