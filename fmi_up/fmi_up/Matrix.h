#ifndef MATRIX_PICA
#define MATRIX_PICA

#define DIAGONAL_PRIMARY 1
#define DIAGONAL_SECONDARY 2
#define DIAGONAL_PRIMARY_LOWER 3
#define DIAGONAL_SECONDARY_UPPER 4

#include "malloc.h"
#include <cmath>
#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <utility>

enum WALK_TYPE {
	WALK_DIAGONAL_FIRST=0x0, WALK_DIAGONAL_SECOND=0x1,
	WALK_LINEAR_VERTICAL=0x10, WALK_LINEAR_HORIZONTAL=0x11,
	WALK_ALL=0xf
};



template < typename mType >
class Matrix{

private:
	mType * buffer;

public:
#pragma region Variables
	int rows;
	int cols;

#pragma endregion

#pragma region Constructors
	Matrix(int rows, int cols);
	Matrix(int rows, int cols, mType * buffer);
	Matrix(int rows, int cols, bool zeroFilled);

#pragma endregion

#pragma region Destructors
	~Matrix(){
		free(buffer);
	}


#pragma endregion

#pragma region Operators
	mType * operator()(int row, int col);
	mType & operator()(int row, int col);

	template<typename Func>
	Matrix operator()(Func function);


	Matrix operator +(float num);
	Matrix operator +(int num);
	Matrix operator +(Matrix matB);

	Matrix operator -(float num);
	Matrix operator *(float num);
	Matrix operator /(float num);
	friend std::ostream operator <<(std::ostream& out, Matrix<mtype> mx);
#pragma endregion

#pragma region Methods
	void set(int iRow, int iCol, mType value);
	/* Only worls for float matricies */
	void inputMatrix();

	bool isDiagonal();
	bool isOnDiagonal(int dimensions, int row, int col);
	bool isNeighbour(int rowSize, int colSize, int row, int col, int rowB, int colB);
	template<typename tPredicate>
	mType * isEqualNeighbour(Matrix mx, int rowA, int colA, int rowB, int colB, tPredicate filter);

	/*
	@param neighbours: neighbours contains an array of pointers to all valid neighbours
	@returns: the number of neighbours found
	*/
	template<typename tPredicate>
	int getNeighbours(int row, int col, mType & neighbours[8], tPredicate filter);


	/*
	* Universal print method, supports many printing formats.
	*/
	void print(
		std::ostream& out,
		bool mirroredH = false,
		bool mirroredV = false,
		bool transposed = false,
		bool diagonal = false,
		char diagonalType = DIAGONAL_PRIMARY);

	static Matrix addWithCoefficients(float coef1, Matrix<float> matA, float coef2, Matrix<float> matB);

	//TODO: Finish this ..
	static int findLongestSequence(Matrix< std::string > mx, std::string* match);

};
#pragma endregion

#endif
