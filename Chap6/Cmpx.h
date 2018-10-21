#pragma once
#include <iostream>
using namespace std;
class Cmpx {
    double re;
    double im;
public:
    Cmpx(double x = 0,double y = 0):re(x),im(y) {};
    Cmpx & operator+=(Cmpx);
    Cmpx & operator+=(double);
    Cmpx & operator-=(Cmpx);
    friend Cmpx operator*(Cmpx z1, Cmpx z2);
    friend std::ostream & operator<<(std::ostream &, Cmpx );
    friend std::istream & operator>>(std::istream &, Cmpx &);
};

inline Cmpx operator+(Cmpx a, Cmpx b){
    return a += b;
}

inline Cmpx operator-(Cmpx a, Cmpx b){
    return a -= b;
}

inline Cmpx & Cmpx::operator+=(Cmpx z){
    re += z.re;
    im += z.im;
    return *this;
}

inline Cmpx & Cmpx::operator+=(double a){
    re += a;
    return *this;
}

inline Cmpx & Cmpx::operator-=(Cmpx z){
    re -= z.re;
    im -= z.im;
    return *this;
}

inline Cmpx operator+(Cmpx z){
    return z;
}

inline Cmpx operator-(Cmpx z){
    return 0 - z;
}

inline Cmpx operator*(Cmpx a, Cmpx b){
    return Cmpx(a.re*b.re - a.im*b.im, a.re*b.im + a.im*b.re);
}

std::ostream & operator<<(std::ostream & s, Cmpx z){
    s << "(" << z.re << ", " << z.im << ")";
    return s;
}

std::istream & operator>>(std::istream & s, Cmpx & z){
    s >> z.re >> z.im;
    return s;
}