#include <iostream>
#include <cstdlib>
#include <cmath>

using namespace std;



void main(){
	cout << "Hi, FMI";
}


void zad2(){
	int age = 59;
	cout << "Hi I'm " << age << " and my name\s Gates Bill";
}

void zad3(){
	bool lovePrograming = true;
	bool loveLudogorets = false;
	bool programShouldHAVEComments = true;
	cout << "I love programming" << lovePrograming;
	cout << "I love Ludogorets" << loveLudogorets;
	cout << "Programs should have comments " << programShouldHAVEComments;
}


/**
 Prints out of our 5 friends.
*/
void zad4(){
	//Array with friends
	string friends[4] = { "friend0", "friend1", "friend2", "friend3", "friend4" };
	for (int i = 0; i <= 4; i++){
		cout << friends[i].c_str;
	}
}

int zad5(){
	int favoriteNumber;
	cout << "What is your favorite number?" << endl;
	cin >> favoriteNumber;
	cout << "Oh, " << favoriteNumber << " is my favorite number, too!" << endl;
	return favoriteNumber;
}

void zad6(){
	float sides[3] = {0.0f, 0.0f, 0.0f};
	float p;
	cout << "Parameter calculator";
	for (int iSide = 0; iSide < 3; iSide++)
	{
		cout << "Enter side " << iSide << ": "; cin >> sides[iSide];
		p += sides[iSide];
	}
	cout << "Perimeter " << p;
}

void zad7(){
	float singlePrice;
	int count = 0;
	cout << "Enter the price of the thing you're buying";
	cin >> singlePrice;
	cout << "How many items are you going to buy ?";
	cin >> count;
	cout << "The Bulgarian VAT tax for this purchase is: " <<
		0.20*(singlePrice*count);
}

void zad8(){
	float a[1], b[1];
	cout << "Enter the coordinates of point A";
	cin >> a[0]; cin >> a[1];
	cout << "Enter the coordinates of point B";
	cin >> b[0]; cin >> b[1];
	float dist = sqrt( pow((b[0] - a[0]),2) + pow((b[1] - a[1]),2));
	cout << "Distance is " << dist;
}

void zad9(){
	int myAge = 0;
	int currentYear = 2014;
	int compareYear;

	cout << "Your age: ";  cin >> myAge;
	cout << "Current year: ";  cin >> currentYear;
	cout << "Enter the year to compare with: ";  cin >> compareYear;

	if (abs(compareYear - currentYear) > (150-myAge))
		cout << "It's been 150 years, you should be dead by then :D";
}
