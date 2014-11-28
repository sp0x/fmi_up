//2_4.cpp
#include <iostream>
#include <cctype>
#include <cmath>
#include <stack>
using namespace std;

stack<int> zad3(int number);
void zad4();

void main(){
    zad4();
}
    void zad4(){
        cout << "1-  One digit number\n";
        cout << "2-  Two digits numbers\n";
        cout << "3-  Three digits number\n";
        cout << "4-  Four digits number\n";
        cout << "5-  Five digits number\n";
        int numDigits; cin >> numDigits;
        cout << "Enter your number: ";
        int num; cin >> num;
        zad3(num);
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