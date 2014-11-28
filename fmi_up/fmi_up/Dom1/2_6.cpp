//2_6.cpp
#include <iostream>
using namespace std;
int binary(int number);


void main(){
        int num; cout << "Number: "; cin >> num;
        tobin(num);
}


int tobin(int number) {
    int remainder;

    if(number <= 1) {
        return number;
    }


    remainder = number%2;
    cout << remainder << " ";
    binary(number >> 1);
    return remainder;
}