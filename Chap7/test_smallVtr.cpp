#include "smallVtr.hpp"
#include <iostream>

int main(){
    smallVtr<4, int> u,v;
    for(int i = 0; i < 4; i++){
        u[i] = i + 1;
        v[i] = (i + 2)/3;
    }

    int d = dot(u,v);
    std::cout << " dot = " << d << std::endl;
}