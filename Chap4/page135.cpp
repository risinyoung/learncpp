#include <iostream>
#include <ctime>
int main(){
    int n = 100000000;
    double d, dpi = 3.1415926535897923385;
    float f, fpi = 3.1415926535897932384;
    time_t tm0 = time(nullptr);
    clock_t ck0 = clock();

    for(int i = 0; i < n; i++) d = (double(i) +dpi)*dpi;
    time_t tm1 = time(nullptr);
    clock_t ck1 = clock();
    std::cout << "wall time = " << difftime(tm1,tm0) << " seconds" <<\
        std::endl;
    std::cout << "CPU  time = " << double(ck1 - ck0)/CLOCKS_PER_SEC <<\
        "seconds" << std::endl;
    
    for(int i = 0; i < n; i++) f = (double(i) +fpi)*fpi;
    time_t tm2 = time(nullptr);
    clock_t ck2 = clock();
    std::cout << "wall time = " << difftime(tm2,tm1) << " seconds" <<\
        std::endl;
    std::cout << "CPU  time = " << double(ck2 - ck1)/CLOCKS_PER_SEC <<\
        "seconds" << std::endl;
    
    std::cout << "The current time is: " << ctime(&tm2) << std::endl;
}