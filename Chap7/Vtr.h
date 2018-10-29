#pragma once
#include <iostream>
#include <cmath>
#include <algorithm>
#include <complex>
#include <string>
template<typename T>
class Vtr {
    int length;
    T * ets;
public:
    Vtr(int,const T * const );
    Vtr(int  = 0, T = 0);
    Vtr(const Vtr & );
    ~Vtr(){delete [] ets;}

    int size() const { return length;}
    Vtr & operator=(const Vtr &);
    Vtr & operator+=(const Vtr &);
    Vtr & operator-=(const Vtr &);
    double maxnorm() const;
    double twonorm() const;
    T & operator[](int i) const { return ets[i]; }
    Vtr operator+();
    Vtr operator-();
    //vector addition and subtraction
    template<typename S>
    friend Vtr<S> operator+(const Vtr<S> &, const Vtr<S> &);

    template<typename S>
    friend Vtr<S> operator-(const Vtr<S> &, const Vtr<S> &);

    //vector scalar multiplication
    template<typename S>
    friend Vtr<S> operator*(double, const Vtr<S> &);

    template<typename S>
    friend Vtr<S> operator*(const Vtr<S> &, double);

    //vector scalar division
    template<typename S>
    friend Vtr<S> operator/(const Vtr<S> &, double);
    
    //vector element-wise multiplication
    template<typename S>
    friend Vtr<S> operator*(const Vtr<S> &, const Vtr<S> &);

    //vector dot multiplication
    template<typename S>
    friend S dot(const Vtr<S> &, const Vtr<S> &);
    
    //vector output
    template<typename S>
    friend std::ostream & operator<<(std::ostream &, const Vtr<S> &);
};


inline void error(std::string v){
    std::cout << v << ", program exited" << std::endl;
    exit(1);
}

template<typename T>
Vtr<T>::Vtr(int n, const T * const abd) {
    ets = new T [length = n];
    for(int i = 0; i < n; i++)  ets[i] = abd[i]; 
}

template<typename T>
Vtr<T>::Vtr(int n, T d) {
    ets = new T [length = n];
    for(int i = 0; i < n; i++)  ets[i] = d; 
}

template<typename T>
Vtr<T>::Vtr(const Vtr & v){
    ets = new T [length = v.length];
    for(int i = 0; i < length; i++) ets[i] = v[i];
}

template<typename T>
Vtr<T> & Vtr<T>::operator=(const Vtr & v){
    if(this != &v){
        if(length != v.length) error("bad vector sizes");
        for(int i = 0; i < length; i++) ets[i] = v[i];
    }
    return *this;
}

template<typename T>
Vtr<T> & Vtr<T>::operator+=(const Vtr & v){
    if(length != v.length) error("bad vector size");
    for(int i = 0; i < length; i++) ets[i] += v[i];
    return *this;
}

template<typename T>
Vtr<T> & Vtr<T>::operator-=(const Vtr & v){
    if(length != v.length) error("bad vector size");
    for(int i = 0; i < length; i++) ets[i] -= v[i];
    return *this;
}

template<typename T>
Vtr<T> & operator+(Vtr<T> & v){
    return v;
}

template<typename T>
Vtr<T> Vtr<T>::operator-(){
    return length - *this;
}

template<typename S>
Vtr<S> operator+(const Vtr<S> & v1, const Vtr<S> & v2){
    if(v1.length != v2.length) error("bad vector sizes");
    Vtr<S> sum = v1;
    return sum += v2;
}

template<typename S>
Vtr<S> operator-(const Vtr<S> & v1, const Vtr<S> & v2){
    if(v1.length != v2.length) error("bad vector sizes");
    Vtr<S> sum = v1;
    return sum -= v2;
}

template<typename S>
Vtr<S> operator*(double scalar,const Vtr<S> & v){
    Vtr<S> tmp(v.length);
    for(int i = 0; i < v.length; i++) tmp[i] = scalar*v[i];
    return tmp;
}

template<typename S>
Vtr<S> operator*(const Vtr<S> & v, double scalar){
    Vtr<S> tmp(v.length);
    for(int i = 0; i < v.length; i++) tmp[i] = scalar*v[i];
    return tmp;
}

template<typename S>
Vtr<S> operator/(const Vtr<S> & v, double scalar){
    Vtr<S> tmp(v.length);
    for(int i = 0; i < v.length; i++) tmp[i] = v[i]/scalar;
    return tmp;
}

template<typename S>
Vtr<S> operator*(const Vtr<S> & v1,const Vtr<S> & v2){
    if(v1.length != v2.length) error("bad vector sizes");
    Vtr<S> tmp = Vtr<S>(v1.length);
    for(int i = 0; i < v1.length; i++) tmp[i] = v1[i]*v2[i];
    return tmp;
}

template<typename T>
double Vtr<T>::twonorm() const {
    double norm = ets[0]*ets[0];
    for(int i = 1; i < length; i++) norm += ets[i]*ets[i];
    return sqrt(norm);
}

template<typename T>
double Vtr<T>::maxnorm() const {
    double norm = fabs(ets[0]);
    for(int i = 1; i < length; i++) norm = std::max(norm, fabs(ets[i]));
    return norm;
}

template<typename T>
T dot(const Vtr<T> & v1, const Vtr<T> &v2){
    if(v1.length != v2.length) error("bad vector sizes");
    T tmp = v1[0]*v2[0];
    for(int i = 1; i < v1.length; i++) tmp += v1[i]*v2[i];
    return tmp;
}

template<typename T>
std::ostream & operator<<(std::ostream & s, const Vtr<T> & v){
    for(int i = 0; i < v.length; i++) {
        s << v[i] << " ";
        if(i%10 == 9) s << std::endl;
    }
    return s;
}


//specialization for complex vector
using std::complex;
using std::conj;
template<typename T> class Vtr<complex<T>>{
    int length;
    complex<T> * ets;
public:
    Vtr(int,const complex<T> * const );
    Vtr(int  = 0, const complex<T> = 0);
    Vtr(const Vtr & );
    ~Vtr(){delete [] ets;}

    int size() const { return length;}
    Vtr & operator=(const Vtr &);
    Vtr & operator+=(const Vtr &);
    Vtr & operator-=(const Vtr &);
    double maxnorm() const;
    double twonorm() const;
    complex<T> & operator[](int i) const { return ets[i]; }
    Vtr operator+();
    Vtr operator-();
    //vector addition and subtraction
    template<typename S>
    friend Vtr<complex<S>> operator+(const Vtr<complex<S>> &, const Vtr<complex<S>> &);

    template<typename S>
    friend Vtr<complex<S>> operator-(const Vtr<complex<S>> &, const Vtr<complex<S>> &);

    //vector scalar multiplication
    template<typename S>
    friend Vtr<complex<S>> operator*(double, const Vtr<complex<S>> &);

    template<typename S>
    friend Vtr<complex<S>> operator*(const Vtr<complex<S>> &, double);

    //vector scalar division
    template<typename S>
    friend Vtr<complex<S>> operator/(const Vtr<complex<S>> &, S);
    
    //vector element-wise multiplication
    template<typename S>
    friend Vtr<complex<S>> operator*(const Vtr<complex<S>> &, const Vtr<complex<S>> &);

    //vector dot multiplication
    template<typename S>
    friend complex<S> dot(const Vtr<complex<S>> &, const Vtr<complex<S>> &);
    
    //vector output
    template<typename S>
    friend std::ostream & operator<<(std::ostream &, const Vtr<complex<S>> &);
};

template<typename T>
Vtr<complex<T>>::Vtr(int n, const complex<T> * const v){
    ets = new complex<T> [length = n];
    for(int i = 0; i < length; i++) ets[i] = v[i];
}

template<typename T>
Vtr<complex<T>>::Vtr(int n, const complex<T>  v){
    ets = new complex<T> [length = n];
    for(int i = 0; i < length; i++) ets[i] = v;
}

template<typename T>
Vtr<complex<T>>::Vtr(const Vtr & v){
    ets = new complex<T> [length = v.length];
    for(int i = 0; i < length; i++) ets[i] = v[i];
}

template<typename T>
Vtr<complex<T>> & Vtr<complex<T>>::operator=(const Vtr & v){
    if(this != &v){
        if(length != v.length) error("bad vector sizes");
        for(int i = 0; i < length; i++) ets[i] = v[i];
    }
    return *this;
}

template<typename T>
Vtr<complex<T>> & Vtr<complex<T>>::operator+=(const Vtr & v){
    if(length != v.length) error("bad vector size");
    for(int i = 0; i < length; i++) ets[i] += v[i];
    return *this;
}

template<typename T>
Vtr<complex<T>> & Vtr<complex<T>>::operator-=(const Vtr & v){
    if(length != v.length) error("bad vector size");
    for(int i = 0; i < length; i++) ets[i] -= v[i];
    return *this;
}

template<typename T>
Vtr<complex<T>> & operator+(Vtr<complex<T>> & v){
    return v;
}

template<typename T>
Vtr<complex<T>> Vtr<complex<T>>::operator-(){
    return length - *this;
}

template<typename T>
Vtr<complex<T>> operator+(const Vtr<complex<T>> & v1, const Vtr<complex<T>> & v2){
    if(v1.length != v2.length) error("bad vector sizes");
    Vtr<complex<T>> sum = v1;
    return sum += v2;
}

template<typename T>
Vtr<complex<T>> operator-(const Vtr<complex<T>> & v1, const Vtr<complex<T>> & v2){
    if(v1.length != v2.length) error("bad vector sizes");
    Vtr<complex<T>> sum = v1;
    return sum -= v2;
}

template<typename T>
Vtr<complex<T>> operator*(double scalar,const Vtr<complex<T>> & v){
    Vtr<complex<T>> tmp(v.length);
    for(int i = 0; i < v.length; i++) tmp[i] = scalar*v[i];
    return tmp;
}

template<typename T>
Vtr<complex<T>> operator*(const Vtr<complex<T>> & v, double scalar){
    Vtr<complex<T>> tmp(v.length);
    for(int i = 0; i < v.length; i++) tmp[i] = scalar*v[i];
    return tmp;
}

template<typename T>
Vtr<complex<T>> operator/(const Vtr<complex<T>> & v, double scalar){
    Vtr<complex<T>> tmp(v.length);
    for(int i = 0; i < v.length; i++) tmp[i] = v[i]/scalar;
    return tmp;
}

template<typename T>
Vtr<complex<T>> operator*(const Vtr<complex<T>> & v1,const Vtr<complex<T>> & v2){
    if(v1.length != v2.length) error("bad vector sizes");
    Vtr<complex<T>> tmp(v1.length);
    for(int i = 0; i < v1.length; i++) tmp[i] = v1[i]*v2[i];
    return tmp;
}

template<typename T>
double Vtr<complex<T>>::twonorm() const {
    complex<T> norm = ets[0]*conj(ets[0]);
    for(int i = 1; i < length; i++) norm += ets[i]*conj(ets[i]);
    return sqrt(norm.real());
}

template<typename T>
double Vtr<complex<T>>::maxnorm() const {
    double norm = abs(ets[0]);
    for(int i = 1; i < length; i++) norm = std::max(norm, abs(ets[i]));
    return norm;
}

template<typename T>
complex<T> dot(const Vtr<complex<T>> & v1, const Vtr<complex<T>> & v2){
    if(v1.length != v2.length) error("bad vector sizes");
    complex<T> tmp = v1[0]*conj(v2[0]);
    for(int i = 1; i < v1.length; i++) tmp += v1[i]*conj(v2[i]);
    return tmp;
}

template<typename T>
std::ostream & operator<<(std::ostream & s, const Vtr<complex<T>> & v){
    for(int i = 0; i < v.length; i++) {
        s << v[i] << " ";
        if(i%10 == 9) s << std::endl;
    }
    return s;
}


