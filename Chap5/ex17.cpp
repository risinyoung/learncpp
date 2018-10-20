#include "ode.h"
#include <fstream>
static double lambda;
double f(double t, double x){
    return x*lambda;
}

double exact(double t){
    return exp(lambda*t);
}

double fder(double t, double x){
    return lambda;
}

int main(int argc, char * argv[])
{
    using namespace std;
    if(argc < 3){
        cout << "Please input : intervals and lambda" << endl;
        exit(1);
    }
    int n = atoi(argv[1]);    
    lambda = atof(argv[2]);
    
    ode exmp(0,1,2,f,fder);
    double norm = 0;
    double h = 2.0/n;    
    double * solnEuler = new double [n+1];
    solnEuler = exmp.euler(n);
    for(int i = 1; i <= n; i++)
        norm = max(norm, fabs(solnEuler[i] - exact(i*h)));
    cout << "max norm of error by euler's method = " << norm << endl;

    double * solnEulerpc = new double [n+1];
    solnEulerpc = exmp.eulerpc(n);
    norm = 0;
    for(int i = 1; i <= n; i++)
        norm = max(norm, fabs(solnEulerpc[i] - exact(i*h)));
    cout << "max norm of error by eulerpc's method = " << norm << endl;

    double * solnRk2 =  new double [n+1];
    solnRk2 = exmp.rk2(n);
    norm = 0;
    for(int i = 1; i <= n; i++)
        norm = max(norm, fabs(solnRk2[i] - exact(i*h)));
    cout << "max norm of error by rk2's method = " << norm << endl;

    double * solnRk4 = new double [n+1];
    solnRk4 = exmp.rk4(n);
    norm = 0;
    for(int i = 1; i <= n; i++)
        norm = max(norm, fabs(solnRk4[i] - exact(i*h)));
    cout << "max norm of error by rk4's method = " << norm << endl;

    double * solnEulerim = new double [n+1];
    solnEulerim = exmp.eulerim(n);
    norm = 0;
    for(int i = 1; i <= n; i++)
        norm = max(norm, fabs(solnEulerim[i] - exact(i*h)));
    cout << "max norm of error by eulerim's method = " << norm << endl;

    ofstream outf("data.txt",ios_base::out);
    outf.precision(4);
    outf.setf(ios_base::scientific, ios_base::floatfield);
    for(int i = 0; i <= n; i++){
            outf.width(12);
            outf << i*h << " " ;
            outf.width(12);
            outf << solnEuler[i] << " " ;
            outf.width(12);
            outf << solnEulerpc[i] << " ";
            outf.width(12);
            outf << solnEulerim[i] << " ";
            outf.width(12);
            outf << solnRk2[i] << " ";
            outf.width(12);
            outf << solnRk4[i] << " ";
            outf.width(12);
            outf << exact(i*h) << endl;
    }
    outf.close();
    delete [] solnEuler;
    delete [] solnEulerpc;
    delete [] solnEulerim;
    delete [] solnRk2;
    delete [] solnRk4;
}