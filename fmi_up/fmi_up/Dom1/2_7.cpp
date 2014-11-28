//2_7.cpp
#include <iostream>
#include <malloc.h>

using namespace std;
void zad7();
void main(){
    zad7();
}

void zad7(){
    cout << "Number of contendors: ";
    int nContendors; cin >> nContendors;
    float * scores = (float*)calloc(nContendors, sizeof(float));
    int scIxMax=-1; //0= index of min, 1= index of max
    int scIxMin=-1;
    for (int i = 0; i<nContendors; i++){
        float pntsForContendor;
        cout << "Score for #" << i << ": "; cin >> pntsForContendor; cout << endl;
        if(scIxMin==-1){
            scIxMin=i;
        } else {
            if(scores[scIxMin] > pntsForContendor) //Last min score is higher than this guy's score.
                scIxMin=i;
        }
        if(scIxMax==-1){
            scIxMax=i;
        } else {
            if(scores[scIxMax] < pntsForContendor)  //Last max score is lower than this guy's score.
                scIxMax=i;
        }
        scores[i]=pntsForContendor;
    }
    cout << "The winner is #" << scIxMax << " with a score of " << scores[scIxMax] << endl;
    cout << "And in last place is #" << scIxMin << " with a score of " << scores[scIxMin] << endl;
}