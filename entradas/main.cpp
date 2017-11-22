#include <iostream>
#include <fstream>
#include <ctime>
#include <stdlib.h>

using namespace std;

int main()
{
    ofstream file("cpp-home.txt");
    srand(time(0));
    
    int numero = -1;
    //file<<numero<<endl;;
    for(int i=1;i<500;i++){
        int r = rand()%500+1;        
        file<<r<<endl;
    }
    
    file.close();
    
    return 0;
}
