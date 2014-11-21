#include <malloc.h>
#include <iostream>
#include <string.h>
#include "MatricaPica.h"

using namespace std;

void asdoi(){
	int rows, cols;
	cout << "Rows: "; cin >> rows; cout << "Cols: "; cin >> cols;
	Matrix matrix(rows, cols);
	matrix.inputMatrix();
}



