#include <malloc.h>
#include <iostream>
#include <string.h>
#include "MatricaPica.h"

using namespace std;

void asdoi(){
	int rows, cols;
	cout << "Rows: "; cin >> rows; cout << "Cols: "; cin >> cols;
	Matrix<float> matrix(rows, cols);
	matrix.inputMatrix();
}


void zad1(){
	int n, m;
	cout << "Enter number of rows: "; cin >> n;
	cout << "Enter number of cols: "; cin >> m;
	Matrix<float> mx(n, m);
	mx.inputMatrix();
}
void zad2(){
	int n, m;
	cout << "Enter number of rows: "; cin >> n;
	cout << "Enter number of cols: "; cin >> m;
	Matrix<float> mx(n, m);
	mx.inputMatrix();
	cout << mx;

}
void zad3(){
	int n, m;
	float c;
	cout << "Enter number of rows: "; cin >> n;
	cout << "Enter number of cols: "; cin >> m;
	cout << "Enter random number: "; cin >> c;
	Matrix<float> mx(n, m);
	mx.inputMatrix();
	Matrix<float> mxB = mx * c;
	cout << mxB;
}
void zad4(){
	int n, m, nb, mb;
	cout << "Enter number of rows for A: "; cin >> n;
	cout << "Enter number of cols for A: "; cin >> m;
	Matrix<float> mx(n, m);
	cout << "Enter number of rows for B: "; cin >> nb;
	cout << "Enter number of cols for B: "; cin >> mb;
	Matrix<float> mxb(nb, mb);
	mx.inputMatrix(); mxb.inputMatrix();
	Matrix<float> mxc = mx + mxb;
	cout << mxc;
}
void zad5(){
	int n, m;
	cout << "Enter number of rows: "; cin >> n;
	cout << "Enter number of cols: "; cin >> m;
	Matrix<float> mx(n, m);
	mx.inputMatrix();
	mx.print(cout, true);
}
void zad6(){
	int n, m;
	cout << "Enter number of rows: "; cin >> n;
	cout << "Enter number of cols: "; cin >> m;
	Matrix<float> mx(n, m);
	mx.inputMatrix();
	mx.print(cout, false, true);
}
void zad7(){
	int n, m;
	cout << "Enter number of rows: "; cin >> n;
	cout << "Enter number of cols: "; cin >> m;
	Matrix<float> mx(n, m);
	mx.inputMatrix();
	mx.print(cout, false, false, true);
}
void zad8(){
	int n, m;
	cout << "Enter number of rows: "; cin >> n;
	cout << "Enter number of cols: "; cin >> m;
	Matrix<float> mx(n, m);
	mx.inputMatrix();
	mx.print(cout, false, false, false, true, DIAGONAL_PRIMARY);
}
void zad9(){
	int n, m;
	cout << "Enter number of rows: "; cin >> n;
	cout << "Enter number of cols: "; cin >> m;
	Matrix<float> mx(n, m);
	mx.inputMatrix();
	mx.print(cout, false, false, false, true, DIAGONAL_SECONDARY);
}
void zad10(){
	int n, m;
	cout << "Enter number of rows: "; cin >> n;
	cout << "Enter number of cols: "; cin >> m;
	Matrix<float> mx(n, m);
	mx.inputMatrix();
	mx.print(cout, false, false, false, true, DIAGONAL_PRIMARY_LOWER);
}
void zad11(){
	int n, m;
	cout << "Enter number of rows: "; cin >> n;
	cout << "Enter number of cols: "; cin >> m;
	Matrix<float> mx(n, m);
	mx.inputMatrix();
	mx.print(cout, false, false, false, true, DIAGONAL_SECONDARY_UPPER);
}
void zad12(){
	int n, m;
	cout << "Enter number of rows: "; cin >> n;
	cout << "Enter number of cols: "; cin >> m;
	Matrix<float> mx(n, m); mx.inputMatrix();
	Matrix<float> mxb(n, m); mx.inputMatrix();
	Matrix<float>::addWithCoefficients(1.3, mx, 2.2, mxb);
}
void zad13(){
	int n, m;
	cout << "Enter number of rows: "; cin >> n;
	cout << "Enter number of cols: "; cin >> m;
	Matrix<string> mx(n, m);
	mx.inputMatrix();
	string match;
	int imatch = mx.findLongestSequence(mx, &match);
	cout << "There were " << imatch << " matches of " << match.c_str();
}




