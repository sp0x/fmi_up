//3_3.cpp
#include <cstring>
#include <stdio>
#include <iostream>
#include <malloc.h>
using namespace std;


void zad3();
void main(){
    zad3();
}



void zad3(){
    float gpa=0.0f;
    float grSum;
    int cntGrs=0;
    while(!cntGrs)
         cout << "Number of grades: "; cin >> cntGrs;
    float * fGrades = (float*)calloc(cntGrs ,sizeof(float)); // to lazy to use new :D
    for(int=0; i<cntGrs; i++){
        cout << "Grade #" << i << ": "; cin >> fGrades[i];  grSum+=fGrades[i];
    }
    cout << "Your GPA is " << grSum/cntGrs << endl; //  cntGrs CAN'T BE ZERO, the input was checked.
}