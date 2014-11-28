//2_1.cpp
#include <iostream>
#include <cctype>
#include <cmath>
using namespace std;

void zad1();
void main(){
    zad1();
}

void zad1(){
        char c;
        cin >> c;
        string result;
        if (isdigit(c)){
            result = "number";
        }
        else{
            result = isupper(c) ? "Upper-case letter" : "Lower-case letter";
        }
        cout << result.c_str();
    }