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

//2) O(n) - Linear 
int sum(int n) {
    int nTotal = 0; //O(1)
    for (int i = 1; i <= n; i++) {
        nTotal += i;
    }
    return nTotal;
}
//sum(n) => f(n) => O(1)  + O(1) + n x (O(1)) => O(1) + O(n) => O(n)

//3) O(log(n)) or O(log_2(n))
int sumLog(int n) {
    int nTotal = 0;//O(1)
    for (int i = 1; i <= n; i = i * 2) { //* 2 -> is the base of log
        nTotal += i;//O(1)
    }
    return n;//O(1
}
//sumLog(n) => f(n) => O(1)  + O(log _2(n)) => O(log _2(n))


int main() {   
    {
        ofstream fout("constant_perf.csv");
        fout << "n, lapse" << endl;
        Timer timer;
        for (int n = 1; n < 500; n++) {
            timer.reset();
            hello(n);
            fout << n << ", "<< timer.elapsed() << endl;
        }
    }
    {
        ofstream fout("linear_perf.csv");
        fout << "n, lapse" << endl;
        Timer timer;
        for (int n = 1; n < 1000; n++) {
            timer.reset();
            cout  << sum(n) << endl;
            fout << n << ", "<< timer.elapsed() << endl;
        }
    }

    {
        ofstream fout("logarithmic_perf.csv");
        fout << "n, lapse" << endl;
        Timer timer;
        for (int n = 1; n < 1000; n++) {
            timer.reset();
            cout  << sumLog(n) << endl;
            fout << n << ", "<< timer.elapsed() << endl;
        }
    }
    
    return 0;
}