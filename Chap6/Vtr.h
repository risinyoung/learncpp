#pragma once
#include <iostream>
#include <cmath>
#include <algorithm>
#include <string>
class Vtr {
    int length;
    double * ets;
public:
    Vtr(int,double*);
    Vtr(int  = 0, double = 0);
    Vtr(const Vtr & );
    ~Vtr(){delete [] ets;}

    int size() const { return length;}
    Vtr & operator=(const Vtr &);
    Vtr & operator+=(const Vtr &);
    Vtr & operator-=(const Vtr &);
    double maxnorm() const;
    double twonorm() const;
    double & operator[](int i) const { return ets[i]; }
    friend Vtr operator+(const Vtr &);
    friend Vtr operator-(const Vtr &);
    friend Vtr operator+(const Vtr &, const Vtr &);
    friend Vtr operator-(const Vtr &, const Vtr &);

    friend Vtr operator*(double, const Vtr &);
    friend Vtr operator*(const Vtr &, double);
    friend Vtr operator/(const Vtr &, double);
    
    friend Vtr operator*(const Vtr &, const Vtr &);
    friend double dot(const Vtr &, const Vtr &);
    friend std::ostream & operator<<(std::ostream &, const Vtr &);
};


double dot(const Vtr &, const Vtr &);
std::ostream & operator<<(std::ostream &, const Vtr &);

inline void error(std::string v){
    std::cout << v << ". program exited" << std::endl;
    exit(1);
}

Vtr::Vtr(int n, double * abd) {
    ets = new double [length = n];
    for(int i = 0; i < n; i++)  ets[i] = abd[i]; 
}

Vtr::Vtr(int n, double d) {
    ets = new double [length = n];
    for(int i = 0; i < n; i++)  ets[i] = d; 
}

Vtr::Vtr(const Vtr & v){
    ets = new double [length = v.length];
    for(int i = 0; i < length; i++) ets[i] = v[i];
}

Vtr & Vtr::operator=(const Vtr & v){
    if(this != &v){
        if(length != v.length) error("bad vector sizes");
        for(int i = 0; i < length; i++) ets[i] = v[i];
    }
    return *this;
}

Vtr & Vtr::operator+=(const Vtr & v){
    if(length != v.length) error("bad vector size");
    for(int i = 0; i < length; i++) ets[i] += v[i];
    return *this;
}

Vtr & Vtr::operator-=(const Vtr & v){
    if(length != v.length) error("bad vector size");
    for(int i = 0; i < length; i++) ets[i] -= v[i];
    return *this;
}

inline Vtr & operator+(Vtr & v){
    return v;
}

inline Vtr operator-(const Vtr & v){
    return Vtr(v.length) - v;
}

Vtr operator+(const Vtr & v1, const Vtr & v2){
    if(v1.length != v2.length) error("bad vector sizes");
    Vtr sum = v1;
    return sum += v2;
}

Vtr operator-(const Vtr & v1, const Vtr & v2){
    if(v1.length != v2.length) error("bad vector sizes");
    Vtr sum = v1;
    return sum -= v2;
}

Vtr operator*(double scalar,const Vtr & v){
    Vtr tmp(v.length);
    for(int i = 0; i < v.length; i++) tmp[i] = scalar*v[i];
    return tmp;
}

Vtr operator*(const Vtr & v, double scalar){
    Vtr tmp(v.length);
    for(int i = 0; i < v.length; i++) tmp[i] = scalar*v[i];
    return tmp;
}

Vtr operator/(const Vtr & v, double scalar){
    Vtr tmp(v.length);
    for(int i = 0; i < v.length; i++) tmp[i] = v[i]/scalar;
    return tmp;
}

Vtr operator*(const Vtr & v1,const Vtr & v2){
    if(v1.length != v2.length) error("bad vector sizes");
    Vtr tmp = Vtr(v1.length);
    for(int i = 0; i < v1.length; i++) tmp[i] = v1[i]*v2[i];
    return tmp;
}

double Vtr::twonorm() const {
    double norm = ets[0]*ets[0];
    for(int i = 1; i < length; i++) norm += ets[i]*ets[i];
    return sqrt(norm);
}

double Vtr::maxnorm() const {
    double norm = fabs(ets[0]);
    for(int i = 1; i < length; i++) norm = std::max(norm, fabs(ets[i]));
    return norm;
}

double dot(const Vtr & v1, const Vtr &v2){
    if(v1.length != v2.length) error("bad vector sizes");
    double tmp = v1[0]*v2[0];
    for(int i = 1; i < v1.length; i++) tmp += v1[i]*v2[i];
    return tmp;
}

std::ostream & operator<<(std::ostream & s, const Vtr & v){
    for(int i = 0; i < v.length; i++) {
        s << v[i] << " ";
        if(i%10 == 9) s << std::endl;
    }
    return s;
}
