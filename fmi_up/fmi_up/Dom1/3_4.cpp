//3_4.cpp
#include <cstring>
#include <stdio>
#include <iostream>
#include <malloc.h>
using namespace std;

void zad4();
void main(){
    zad4();
}

bool isSorted(int * arr , size_t arrlen);
void zad4(){
    int arr1[5]={1,2,3,4,5}; //ascending
    int arr2[5]={5,4,3,2,1}; //descending
    int arr3[5]={145,1,777,123,2}; // randomly ordered
    cout << "Array 1 is" <<  isSorted(arr1,5) ? "" : "n't" << "sorted";
    cout << "Array 2 is" <<  isSorted(arr2,5) ? "" : "n't" << "sorted";
    cout << "Array 3 is" <<  isSorted(arr3,5) ? "" : "n't" << "sorted";
}

bool isSorted(int * arr , size_t arrlen){
    if(arr==0){
        cout << "INVALID ARRAY!"; return false;
    }
    bool ascending = arr[0]<arr[arrlen-1];
    bool descending = arr[0]>arr[arrlen-1];
    for(int i=0; i<arrlen-1; i++){
        if(ascending){
            if(arr[i]>=arr[i+1]) return false; // prev can't be equal or greater than next
        } else if(descending){
            if(arr[i]<=arr[i+1]) return false;// prev can't be equal or less than next
        }
    }
    return true;
}