#include <iostream>
#include <fstream>
#include "timer.h"

using namespace std;
//What are things to consider in designing algorigthms?
//1) RunTime
//2) Space / Memory

//3) Use as bases programming
//4) Effectiveness

//1) O(1) ~ O(1 + 1) - Constatant
void hello(int n) {
    cout << "Hello World" << endl;//O(1)   
}
//hello(n) => f(n) => O(1) 

int main() {   
    {
        ofstream fout("constant_perf.csv");
        fout << "n, lapse" << endl;
        Timer timer;
        for (int n = 1; n < 35; n++) {
            timer.reset();
            hello(n);
            fout << n << ", "<< timer.elapsed() << endl;
        }
    }
    return 0;
}