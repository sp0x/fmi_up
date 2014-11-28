//3_2.cpp
#include <cstring>
#include <stdio>
#include <iostream>
using namespace std;

void zad2();


void main(){
    zad2();
}

void zad2(){
    cout << "How many friends do you have? ";
    int szFrs; cin >> szFrs;
    int *iFrAges = (int*)calloc(szFrs, sizeof(int)); // Allocate space for friend ages
    int ixMin=-1, ixMax=-1;
    cout << "Enter the ages of your " << szFrs <<  " friends: ";
    for(int i=0; i< szFrs; cin >> iFrAges[i++]);
    for(int i=0; i<szFrs; i++){
        if(iMin==-1){
            ixMin=i;
        } else {
            ixMin= (iFrAges[i]<iFrAges[ixMin]) ? i : ixMin ;
        }
        if(ixMax==-1){
            ixMax=i;
        } else {
            ixMax= (iFrAges[i]>iFrAges[ixMax]) ? i : ixMax ;
        }
    }
    cout << "The oldest of your friends is " << iFrAges[ixMax] <<
     " years old. The youngest is " << iFrAges[ixMin] << "." << endl;
}