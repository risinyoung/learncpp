#include <iostream>
#include "tem_exp.hpp"
int main(){
    double a[] {1,2,3,4,5};
    double b[] {6,7,8,9,10};
    double c[] {11,12,13,14,15};
    double d[5];
    Vtr X(5,a), Y(5,b), Z(5,c), W(5,d);
    W = X*Y*Z;
    for(int i = 0; i < 5; i++){
        std::cout << W[i] << ' ';
    }
    std::cout << std::endl;
}