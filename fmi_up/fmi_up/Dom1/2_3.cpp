//2_3.cpp
#include <iostream>
#include <cctype>
#include <cmath>
#include <stack>
using namespace std;

stack<int> zad3(int number);

void main(){
    int n; cout << "Number to chop up: "; cin >> n;
    zad3(n);
}
stack<int> zad3(int number){
        if (number == 0) number = 1234;
        std::stack<int> stk;
        std::stack<int> stkCopy;
        do{
            int rem = number % 10;
            number = number / 10;
            stk.push(rem);
        } while (number > 1);
        stkCopy = stk;
        while (stk.size() > 0){
            cout << (int)stk.top() << "\n"; stk.pop();
        }
        return stkCopy;
    }