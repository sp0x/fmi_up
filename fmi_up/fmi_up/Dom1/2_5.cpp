//2_5.cpp
#include <iostream>
#include <cctype>
#include <cmath>
#include <stack>
using namespace std;

stack<int> zad3(int number);
void zad5();


void main(){
    zad5();
}
/**
    * Checks for palindroms
    **/
    void zad5(){
        int palindrom; cin >> palindrom;
        int sz = 0;
        int * pNums = toArray<int>(zad3(palindrom), sz);
        bool isInvalid = false;
        if (sz % 2 != 0){
            cout << "Not a palindrome\n"; return;
        }
        for (int i = 0; i<sz; i++){
            if (pNums[i] != pNums[sz - i]){
                isInvalid = true;
            }
        }
        cout << palindrom << " Is " << (isInvalid ? "not" : "a") << " palindrome!";
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