//1_7.cpp
#include <iostream>
#include <cstring>
using namespace std;

void zad7();

void main(){
    zad7();
}
void zad7(){
        float singlePrice;
        int count = 0;
        cout << "Enter the price of the thing you're buying";       cin >> singlePrice;
        cout << "How many items are you going to buy ?";            cin >> count;
        cout << "The Bulgarian VAT tax for this purchase is: " << 0.20*(singlePrice*count);
    }