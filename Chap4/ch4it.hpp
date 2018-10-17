#pragma once
#include <iostream>
#include <cmath>
#include <cstdlib>
using namespace std;
 const double delta = 1e-8;
 const double epsn = 1e-9;
 
 double bisctn(double, double, double (*)(double), double, double);

 double fa(double);
 double fb(double);
 double fc(double);