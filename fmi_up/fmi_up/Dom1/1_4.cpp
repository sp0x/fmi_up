//1_4.cpp
#include <iostream>
#include <cstring>
using namespace std;

/**
*Prints out the name of 5 friends.
*/
void main(){
        //Array with friends
        string friends[5] = { "friend0", "friend1", "friend2", "friend3", "friend4" };
        for (int i = 0; i <= 4; i++){
            cout << (friends[i]).c_str();
        }
}