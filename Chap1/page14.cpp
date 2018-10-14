#include <iostream>
#include <limits>
using namespace std;

int main(){
    cout << "largest float = " 
        << numeric_limits<float>::max() << endl;
    cout << "smallest float = " 
        << numeric_limits<float>::min() << endl;
    cout << "min exponent in binary = " 
        << numeric_limits<float>::min_exponent << endl;
    cout << "min exponent in decimal = " 
        << numeric_limits<float>::min_exponent10 << endl;
    cout << "max exponent in binary = " 
        << numeric_limits<float>::max_exponent << endl;
    cout << "max exponent in decimal = " 
        << numeric_limits<float>::max_exponent10 << endl;
    cout << "# of binary digits in mantissa = " 
        << numeric_limits<float>::digits << endl;
    cout << "# of decimal digits in mantissa = " 
        << numeric_limits<float>::digits10 << endl;
    cout << "base of exponent in float: "
        << numeric_limits<float>::radix << endl;
    cout << "infinity in float: "
        << numeric_limits<float>::infinity() << endl;
    cout << "float epsilon = "
        << numeric_limits<float>::epsilon() << endl;
    cout << "float rounding error = "
        << numeric_limits<float>::round_error() << endl;
    cout << "float rounding style = "
        << numeric_limits<float>::round_style << endl;
    cout << endl;

    double smallestDouble = numeric_limits<double>::min();
    double doubleEps = numeric_limits<double>::epsilon();
    long double largestLongDouble = numeric_limits<long double>::max();
    long double longDoubleEpsilon = numeric_limits<long double>::epsilon();

    cout << "smallest double = " << smallestDouble << endl;
    cout << "double epsilon = " << doubleEps << endl;
    cout << "largest long double = " << largestLongDouble <<endl;
    cout << "long double epsilon = " <<longDoubleEpsilon << endl;
    
}