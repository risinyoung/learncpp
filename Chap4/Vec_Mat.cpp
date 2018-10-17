#include <algorithm>
#include "Vec_Mat.hpp"
#include <iostream>
#include <cmath>

double Vec::onenorm(const double * const v, const int size){
    if(size > maxsize) std::cout << "vetor size too large" << std::endl;
    double norm = fabs(v[0]);
    for(int i = 1; i < size; i++) norm += fabs(v[i]);
    return norm;
}

double Vec::twonorm(const double * const v, const int size){
    if(size > maxsize) std::cout << "vetor size too large" << std::endl;
    double norm = v[0]*v[0];
    for(int i = 1; i < size; i++) norm += v[i]*v[i];
    return sqrt(norm);
}

double Vec::maxnorm(const double * const v, const int size){
    if(size > maxsize) std::cout << "vetor size too large" << std::endl;
    double norm = fabs(v[0]);
    for(int i = 1; i < size; i++) norm = std::max(norm, fabs(v[i]));
    return norm;
}

double Mat::maxnorm(const double * const * a, const int size){
    double norm = Vec::onenorm(a[0], size);
    for(int i = 1; i < size; i++)
        norm = std::max(norm, Vec::onenorm(a[i],size));
    return norm;
}

double Mat::onenorm(const double * const * a, const int size){
    double norm = 0;
    for(int j =0; j < size; j++){
        double temp = 0;
        for(int i = 0; i < size; i++) temp +=a[i][j];
        norm = std::max(norm, temp);
    }
    return norm;
}

double Mat::frobnorm(const double * const * a, const int size){
    double norm = 0;
    for(int j =0; j < size; j++)
        for(int i = 0; i < size; i++) norm +=a[i][j]*a[i][j];
    return sqrt(norm);
}