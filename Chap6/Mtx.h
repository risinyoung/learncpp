#pragma once
#include "Vtr.h"
using namespace std;
class Mtx {
    int nrows;
    int ncols;
    double ** ets;
public:
    Mtx(int, int, double **);
    Mtx(int, int, double = 0);
    Mtx(const Mtx & );
    ~Mtx();

    Mtx & operator=(const Mtx &);
    Mtx & operator+=(const Mtx &);
    Mtx & operator-=(const Mtx &);
    Vtr operator*(const Vtr &) const;
    double * operator[](int i) const { return ets[i]; }
    double & operator()(int i, int j) const { return ets[i][j]; }

    Mtx & operator+();
    Mtx operator+(const Mtx &) const;
    Mtx & operator-();
    Mtx operator-(const Mtx &) const;

    int CG(Vtr &, const Vtr &, double & eps, int & iter);
};

Mtx::Mtx(int n, int m, double ** a){
    ets = new double * [nrows = n];
    for(int i = 0; i < n; i++){
        ets[i] = new double [ncols = m];
        for(int j = 0; j < m; j++) ets[i][j] = a[i][j];
    }
}

Mtx::Mtx(int n, int m, double d){
    ets = new double * [nrows = n];
    for(int i = 0; i < n; i++){
        ets[i] = new double [ncols = m];
        for(int j = 0; j < m; j++) ets[i][j] = d;
    }
}

Mtx::Mtx(const Mtx & mat){
    nrows = mat.nrows;
    ncols = mat.ncols;
    ets = new double * [nrows];
    for(int i = 0; i < nrows; i++){
        ets[i] = new double [ncols];
        for(int j = 0; j < ncols; j++) ets[i][j] = mat[i][j];
    }
}

inline Mtx::~Mtx(){
    for(int i = 0; i < nrows; i++) delete [] ets[i];
    delete [] ets;
}

Mtx & Mtx::operator=(const Mtx & mat){
    if(this != & mat){
        if(nrows != mat.nrows || ncols != mat.ncols) 
            error("bad matrix sizes");
        for(int i = 0; i < nrows; i++)
            for(int j = 0; j < ncols; j++) ets[i][j] = mat[i][j];
    }
    return *this;
}

Mtx & Mtx::operator+=(const Mtx & mat){
    if(nrows != mat.nrows || ncols != mat.ncols) 
        error("bad matrix sizes");
    for(int i = 0; i < nrows; i++)
        for(int j = 0; j < ncols; j++) ets[i][j] += mat[i][j];
    return *this;
}

Mtx & Mtx::operator-=(const Mtx & mat){
    if(nrows != mat.nrows || ncols != mat.ncols) 
        error("bad matrix sizes");
    for(int i = 0; i < nrows; i++)
        for(int j = 0; j < ncols; j++) ets[i][j] -= mat[i][j];
    return *this;
}

inline Mtx & Mtx::operator+() {
    return *this;
}

inline Mtx & Mtx::operator-(){
    for(int i = 0; i < nrows; i++)
        for(int j = 0; j < ncols; j++) ets[i][j] = -ets[i][j];
    return *this;
}

Mtx Mtx::operator+(const Mtx & mat) const {
    if(nrows != mat.nrows || ncols != mat.ncols)
        error("bad matrix sizes");
    Mtx sum = *this;
    return sum += mat;
}

Mtx Mtx::operator-(const Mtx & mat) const{
    if(nrows != mat.nrows || ncols != mat.ncols)
        error("bad matrix sizes");
    Mtx sum = *this;
    return sum -= mat;
}

Vtr Mtx::operator*(const Vtr & v) const {
    if(ncols != v.size())
        error("matrix and vector sizes do not match");
    Vtr tmp(nrows);
    for(int i = 0; i < nrows; i++)
        for(int j = 0; j < ncols; j++)
            tmp[i] += ets[i][j]*v[j];
    return tmp;
}

int Mtx::CG(Vtr & x, const Vtr & b, double  & eps, int & iter){
    if(nrows != b.size()){
        cout << "matrix and vector sizes do not match" << endl;
        return 1;
    }

    const int maxiter = iter;
    Vtr r = b - (*this)*x;
    Vtr p = r;
    double zr = dot(r,r);
    const double stp = eps*b.twonorm();

    if(r.twonorm() == 0){
        eps = 0.0;
        iter = 0;
        return 0;
    }

    double alpha;
    double zrold;
    for(iter = 0; iter < maxiter; iter++){
        Vtr mp = (*this)*p;
        alpha = zr/dot(mp,p);
        x += alpha*p;
        r -= alpha*mp;
        if(r.twonorm() <= stp) break;
        zrold = zr;
        zr = dot(r,r);
        p = r + (zr/zrold)*p;
    }
    eps = r.twonorm();
    if(iter == maxiter) return 1;
    else return 0;
}