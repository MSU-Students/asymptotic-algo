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

//3) O(log(n)) or O(log_2(n)) - Logarithmic
int sumLog(int n) {
    int nTotal = 0;//O(1)
    for (int i = 1; i <= n; i = i * 2) { //* 2 -> is the base of log
        nTotal += i;//O(1)
    }
    return n;//O(1
}
//sumLog(n) => f(n) => O(1)  + O(log _2(n)) => O(log _2(n))


//4) O(n^2) - Quadratic
int sumQuad(int n) {
    int nTotal = 0;
    for (int j = 1; j <= n; j++) { //n x -> of exp (n x n) => n ^ 2
        for (int i = 1; i <= n; i++) { //x n of exp (n x n) => n ^ 2
            nTotal += i; //O(1)
        }
    }
    return nTotal;
}
//sumQuad(n) => f(n) => O(1)  + O(1) x n x n  => O(1 + 1) + O(n x n) =>  O(1) + O(n^2) => O(n^2)


//5) O(2^n) - Exponential 
int fib(int n) {
   if (n == 0 || n == 1) {
       return 1;//O(1)
   } 
   return fib(n - 1) + fib(n - 2);//O(2^n)
}
//fib(n) => f(n) => O(1) + O(2^n) => O(1) + O(2^n) =>  O(2^n)

//6) O(1^n) - Recursive Loop 
int sumRecursive(int n) {
   if (n == 1) { 
       return 1; //O(1)
   } 
   return n + sumRecursive(n - 1);//O(1) + O(1^n)
}
//sumRecursive(n) => f(n) => O(1) + O(1) + O(1^n) => O(1 + 1) + O(n) => O(1) + O(n) => O(n)

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

    {
        ofstream fout("quadratic_perf.csv");
        fout << "n, lapse" << endl;
        Timer timer;
        for (int n = 1; n < 1000; n++) {
            timer.reset();
            cout  << sumQuad(n) << endl;
            fout << n << ", "<< timer.elapsed() << endl;
        }
    }

    {
        ofstream fout("exponential_perf.csv");
        fout << "n, lapse" << endl;
        Timer timer;
        for (int n = 1; n < 45; n++) {
            timer.reset();
            cout << n << " fib => " <<  fib(n) << endl;
            fout << n << ", "<< timer.elapsed() << endl;
        }
    }

     {
        ofstream fout("recursive_loop_perf.csv");
        fout << "n, lapse" << endl;
        Timer timer;
        for (int n = 1; n < 1000; n++) {
            timer.reset();
            cout  << sumRecursive(n) << endl;
            fout << n << ", "<< timer.elapsed() << endl;
        }
    }
    
    return 0;
}