//3_1.cpp
#include <cstring>
#include <stdio>
#include <iostream>
using namespace std;


void zad1Vars();
void zad1Arrays();
void main(){
    zad1Vars();
    zad1Arrays();
}

void zad1Vars(){
    string name1; cout << "Student 1: "; cin >> name1; cout << endl;
    string name2; cout << "Student 2: "; cin >> name2; cout << endl;
    string name3; cout << "Student 3: "; cin >> name3; cout << endl;
    string name4; cout << "Student 4: "; cin >> name4; cout << endl;
    string name5; cout << "Student 5: "; cin >> name5; cout << endl;
    string name6; cout << "Student 6: "; cin >> name6; cout << endl;
    string name7; cout << "Student 7: "; cin >> name7; cout << endl;
    string name8; cout << "Student 8: "; cin >> name8; cout << endl;
    string name8; cout << "Student 8: "; cin >> name8; cout << endl;
    string name9; cout << "Student 9: "; cin >> name9; cout << endl;
    string name10; cout << "Student 10: "; cin >> ame10; cout << endl;
    string name11; cout << "Student 11: "; cin >> ame11; cout << endl;
    string name12; cout << "Student 12: "; cin >> ame12; cout << endl;
    string name13; cout << "Student 13: "; cin >> ame13; cout << endl;
    string name14; cout << "Student 14: "; cin >> ame14; cout << endl;
    string name15; cout << "Student 15: "; cin >> ame15; cout << endl;
    string name16; cout << "Student 16: "; cin >> ame16; cout << endl;
    string name17; cout << "Student 17: "; cin >> ame17; cout << endl;
    string name18; cout << "Student 18: "; cin >> ame18; cout << endl;
    string name19; cout << "Student 19: "; cin >> ame19; cout << endl;
    string name20; cout << "Student 20: "; cin >> ame20; cout << endl;
    cout << name1 << endl; cout << name2 << endl; cout << name3 << endl; cout << name4 << endl; cout << name5 << endl; cout << name6 << endl; cout << name7 << endl; cout << name8 << endl; cout << name8 << endl; cout << name9 << endl;
    cout << name10 << endl; cout << name11 << endl; cout << name12 << endl; cout << name13 << endl; cout << name14 << endl; cout << name15 << endl; cout << name16 << endl; cout << name17 << endl; cout << name18 << endl; cout << name19 << endl; cout << name20 << endl;

}
void zad1Arrays(){
    string students[20];
    cout << "Enter a list of 20 students: ";
    for(int i=0; i<20; cin::getline(cin,students[i++]));
    for(int i=0; i<20; cout << "Student # " << i+1 << students[i++] << endl);
}

