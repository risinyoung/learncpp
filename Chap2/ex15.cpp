#include <iostream>
using namespace std;
int main(){
    int n;
    int mask = 1 << 31;
    while(true){
        cout << endl << "Enter an integer: " <<endl;
        if(!(cin >> n) ) break;
        cout << "bit representation of " << n << " is: ";
        for(int i = 1; i < 33; i++){
            char cc = (n & mask) ? '1' : '0';
            cout << cc;
            n <<= 1;
            if(i%8 == 0 && i != 32) cout << ' ';
        }
    }
    cout << "end with a noninteger" << endl;
}

