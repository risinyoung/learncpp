#include <iostream>
#include <ctime>
#include <cstdlib>
int main(){
    const int n = 10;
    int a[n];
    srand((unsigned) time(nullptr));
    for(int i = 0; i < n; i++) a[i] = rand()%n;

    double mean( int [],int);
    int max( int [],int);
    int min( int [],int);

    using namespace std;
    for(int i = 0; i < n; i++)
        cout << a[i] << ' ' ;
    cout << endl;
    cout << "mean: " << mean(a,n) << endl;
    cout << "max: " << max(a,n) << endl;
    cout << "min: " << min(a,n) << endl;
}

double mean(int a[],int n){
    int len = n;
    int sum = 0;
    for(int i = 0; i < len; i++) sum += a[i];
    return (double)sum/len;
}

int max(int a[],int n){
    int len = n;
    int tmp = a[0];
    for(int i = 1; i < len; i++) if(a[i] > tmp) tmp = a[i];
    return tmp;
}

int min(int a[],int n){
    int len = n;
    int tmp = a[0];
    for(int i = 1; i < len; i++) if(a[i] < tmp) tmp = a[i];
    return tmp;
}