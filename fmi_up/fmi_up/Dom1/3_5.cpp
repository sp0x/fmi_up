//3_5.cpp
#include <cstring>
#include <stdio>
#include <iostream>
#include <malloc.h>
using namespace std;


void zad5();
void main(){
    int n; cout << "Enter number of elements in the array that is to be sorted: "; cin >> n;
    int * arr = (int*)calloc(n, sizeof(int));
    for(int i=0; i<n; i++){
        cout << "array[" << (i + 1 )<< "]="; cin >> arr[i];
    }
    zad5(arr,n);
}

/*
Does insertion sorting...
*/
void zad5(int * arr, int arrlen){
    for(int i=1; i<arrlen; i++){
        int crVal=arr[i];
        int prev =arr[i-1];
        //iterate backwards untill base is reached. exit if previous is smaller than current
        while( prev>=0 && arr[prev] > crVal){
            arr[prev+1] = arr[prev]; // set the element after the prev. one.
            prev--;
        }
        arr[prev+1]=crVal;
    }
}