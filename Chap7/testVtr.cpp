#include"Vtr.h"
int main(){
    int N;
    using std::cout;
    using std::cin;
    using std::endl;
    cout << "please input the size of vector: ";
    cin >> N;
    Vtr<double> a(N,2);
    Vtr<double> b(N,1);
    cout << "a + b = " << a + b << endl;
    cout << "a - b = " << a - b << endl;
    cout << "a's twonorm = " << a.twonorm() << endl;
    cout << "a*4 = " << a*4 << endl;
    cout << "a*b = " << a*b << endl;
    cout << "dot(a,b) = " << dot(a,b) << endl;
    cout << endl;
    cout << "complex test " << endl;
    cout << "please input the size of complex vector: ";
    cin >> N;
    cout << endl;


    complex<double> * aa = new complex<double> [N];
    for(int i = 0; i < N; i++) aa[i] = complex<double>(5,i);
    Vtr<complex<double>> c(N, aa);

    Vtr<complex<double>> d(N);
    for(int i = 0; i < N; i++) d[i] = complex<double>(2,3+i);
    cout << "c + d = " << c + d << endl;
    cout << "c - d = " << c - d << endl;
    cout << "c's twonorm = " << c.twonorm() << endl;
    cout << "c*4 = " << c*4 << endl;
    cout << "c*d = " << c*d << endl;
    Vtr<complex<double>> d_conj(N);
    for(int i = 0; i < N; i++) d_conj[i] = complex<double>(2,-3-i);
    cout << "c*conj(d) = " << c*d_conj << endl;
    cout << "dot(c,d) = " << dot(c,d) << endl;
    cout << "dot(c,c) = " << dot(c,c) << endl;
}