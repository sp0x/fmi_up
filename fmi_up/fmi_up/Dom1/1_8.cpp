//1_8.cpp
#include <iostream>
#include <cstring>
#include <cmath>

using namespace std;

void zad8();

void main(){
    zad8();
}

void zad8(){
        float a[1], b[1];
        cout << "Enter the coordinates of point A";
        cin >> a[0]; cin >> a[1];
        cout << "Enter the coordinates of point B";
        cin >> b[0]; cin >> b[1];
        float dist = sqrt(pow((b[0] - a[0]), 2) + pow((b[1] - a[1]), 2));
        cout << "Distance is " << dist;
    }