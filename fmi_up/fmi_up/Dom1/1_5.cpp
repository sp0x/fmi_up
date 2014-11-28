//1_5.cpp
#include <iostream>
#include <cstring>
using namespace std;

int zad5();
void main(){
    zad5();
}
int zad5(){
        int favoriteNumber;
        cout << "What is your favorite number? " << endl;
        cin >> favoriteNumber;
        cout << "Oh, " << favoriteNumber << " is my favorite number, too!" << endl;
        return favoriteNumber;
    }