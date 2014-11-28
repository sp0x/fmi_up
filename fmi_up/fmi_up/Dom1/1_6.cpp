//1_6.cpp
#include <iostream>
#include <cstring>
using namespace std;

void zad6();

void main(){
    zad6();
}


void zad6(){
        float sides[3] = { 0.0f, 0.0f, 0.0f };
        float p = 0.0f;
        cout << "Parameter calculator";
        for (int iSide = 0; iSide < 3; iSide++)
        {
            cout << "Enter side " << iSide+1 << ": "; cin >> sides[iSide];
            p += sides[iSide];
        }
        cout << "Perimeter is " << p;
    }