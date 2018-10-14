#include <iostream>
int main()
{
    double sum = 0;
    for(double x = 0; x <= 5.5; x+=0.1) sum += x;
    std::cout << sum << std::endl;
}