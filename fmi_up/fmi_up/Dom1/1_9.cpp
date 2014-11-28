//1_9.cpp
#include <iostream>
#include <cstdlib>
#include <cmath>
#include <string>
using namespace std;

void zad9();

void main(){
    zad9();
}

    void zad9(){
        int myAge = 0;
        int currentYear = 2014;
        int compareYear;

        cout << "Your age: ";       cin >> myAge;
        cout << "Current year: ";   cin >> currentYear;
        cout << "Enter the year to compare with: ";  cin >> compareYear;

        if (abs(compareYear - currentYear) > (150 - myAge))
            cout << "It's been 150 years, you should be dead by then :D";
    }