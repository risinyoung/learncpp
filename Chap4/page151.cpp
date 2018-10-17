#include <sstream>
#include <fstream>
#include <iostream>

using namespace std;
int main(){

    ifstream infile("data.txt", ios_base::in);
    if(!infile){
        cout << "there shoulde be a text named 'data.txt'" << endl;
        exit(1);
    }
    int i;
    double d;
    infile.ignore(80,'\n');

    infile >> i;
    infile.ignore(80, '\n'); 
    infile >> d;

    ostringstream result;
    result << "ex" << i << "-" << int (1/d) << "h" << ".txt";
    ofstream outfile(result.str(), ios_base::out);
    outfile << "example number: " << i << endl;
    outfile << "grid size: " << d << endl;
    infile.close();
    outfile.close();
}