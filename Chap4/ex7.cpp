#include <iostream>
#include <ctime>
using namespace std;
long fib(int m){
    long fp = 1;
    long fc = 1;
    for(int n = 2; n < m; n++){
        long tmp = fc;
        fc += fp;
        fp = tmp;
    }
    return fc;
}

long fib_recur(int m){
    if(m == 2 || m == 1) return 1;
    else return fib_recur(m-1) + fib_recur(m-2);
}

int main(int argc, char * argv[]){
    clock_t clock0 = clock();
    long result;
    int k = atoi(argv[1]);
    for(int i = 0; i < k; i++){
        result = fib(20);
    }
    clock_t clock1 = clock();
    cout << "no recur" << endl;
    cout << "result: " << result << endl;
    cout << "time cost " << (double)(clock1 - clock0)/CLOCKS_PER_SEC << endl;

    
    for(int i = 0; i < k; i++){
        result = fib_recur(20);
    }
    clock_t clock2 = clock();
    cout << "recur" << endl;
    cout << "result: " << result << endl;
    cout << "time cost " << (double)(clock2 - clock1)/CLOCKS_PER_SEC << endl;

}