#pragma once
namespace Vec {
    const int maxsize = 100000;
    double onenorm(const double * const, const int);
    double twonorm(const double * const, const int);
    double maxnorm(const double * const, const int);
}

namespace Mat {
    const int maxsize = 100000;
    double onenorm(const double * const * const, const int);
    double twonorm(const double * const * const, const int);
    double maxnorm(const double * const * const, const int);
    double frobnorm(const double * const * const, const int);
}