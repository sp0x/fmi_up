//2_8.cpp
#include <iostream>
using namespace std;
void zad8();
void main(){
    zad8();
}
void zad8(){
        int n; cout << "Enter N: "; cin >> n;
        int tmpI = 0;
        char c; cout << "Enter triangle char: "; cin >> c;
        for (int i = 0; i < n; i++) cout << c << " ";
        for (int i = n - 1; i>0; i--){
            for (int j = 0; j < n; j++){
                cout << ((j == (i + 1) || j == ((n * 2 - 1) - i)) ? c : ' ');
                //       + + + + +
                //        +     +
                //         +   +
                //          + +
                //           +
            }
        }
    }