#include <cstdlib>
#include <iostream>
int main()
{
    using namespace std;
    cout << RAND_MAX;
    for(int i = 0; i < 100; i++) cout << rand()%46 +5 << endl;
}