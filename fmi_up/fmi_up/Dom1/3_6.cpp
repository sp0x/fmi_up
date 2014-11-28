//3_6.cpp
#include <cstring>
#include <stdio>
#include <iostream>
#include <algorithm>
using namespace std;

void zad6();

void main(){
    zad6();
}

void zad6(){
    char * str2Rev;
    cout << "Something funny: "; cin >> str2Rev;
    int len =strlen(str2Rev);
    for(int i= len; i>-1; i--){
        swap(str[i], str[len-i]);
    }
}