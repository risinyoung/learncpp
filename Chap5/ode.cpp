#include "ode.h"
#include <fstream>
double f(double t, double x){
    return x*(1 - exp(t))/(1 + exp(t));
}

double exact(double t){
    return 12*exp(t)/pow(1 + exp(t), 2);
}

double fder(double t, double x){
    return (1 - exp(t))/(1 + exp(t));
}
int main(int argc, char * argv[])
{
    using namespace std;
    if(argc < 2){
        cout << "Please input n : intervals" << endl;
        exit(1);
    }
    int n = atoi(argv[1]);    
    
    ode exmp(0,3,2,f,fder);
    double norm = 0;
    double h = 2.0/n;    
    double * soln = exmp.euler(n);
    for(int i = 1; i <= n; i++)
        norm = max(norm, fabs(soln[i] - exact(i*h)));
    cout << "max norm of error by euler's method = " << norm << endl;

    soln = exmp.eulerpc(n);
    norm = 0;
    for(int i = 1; i <= n; i++)
        norm = max(norm, fabs(soln[i] - exact(i*h)));
    cout << "max norm of error by eulerpc's method = " << norm << endl;

    soln = exmp.rk2(n);
    norm = 0;
    for(int i = 1; i <= n; i++)
        norm = max(norm, fabs(soln[i] - exact(i*h)));
    cout << "max norm of error by rk2's method = " << norm << endl;

    soln = exmp.rk4(n);
    norm = 0;
    for(int i = 1; i <= n; i++)
        norm = max(norm, fabs(soln[i] - exact(i*h)));
    cout << "max norm of error by rk4's method = " << norm << endl;

    ofstream ofile("data.txt",ios_base::out);

    soln = exmp.eulerim(n);
    norm = 0;
    for(int i = 1; i <= n; i++){
        norm = max(norm, fabs(soln[i] - exact(i*h)));
        ofile << i*h << " " << soln[i] << " " << exact(i*h) << endl;
    }
    cout << "max norm of error by eulerim's method = " << norm << endl;

    ofile.close();
    delete [] soln;
}