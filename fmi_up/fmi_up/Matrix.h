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
	Matrix(int rows, int cols){
		Matrix(rows, cols, (mType*)calloc(rows*cols, sizeof(mType))); //Allocate space for the matrix, by using it's total element count
	}
	Matrix(int rows, int cols, mType * buffer){
		this->rows = rows;
		this->cols = cols;
		this->buffer = buffer;
	}
#pragma endregion

#pragma region Destructors
	~Matrix(){
		free(buffer);
	}
#pragma endregion

#pragma region Operators
	/*mType * operator [](int row) const {
		return &buffer[row * sizeof(mType)];
	}
	mType & operator [](int row) {
		return buffer[row * sizeof(mType)];
	}*/
	mType * operator()(int row, int col) const {
		return &(&(this->buffer[row]))[col];
	}
	mType & operator()(int row, int col){
		return (&(this->buffer[row]))[col];
	}



	template<typename Func>
	Matrix operator()(Func function){
		for (int iRow = 0; iRow < this->rows; iRow++){
			for (int iCol = 0; iCol < this->cols; iCol++){
				function( (*this)(iRow,iCol) );
			}
		}
		return Matrix(this->rows, this->cols, this->buffer);
	}

	
	Matrix operator +(float num){
		return (*this)([num](mType& colElem){	colElem += num;		});
	}
	Matrix operator +(int num){
		return (*this)([num](mType& colElem){	colElem += num;		});
	}
	Matrix operator +(Matrix matB){
		if ( rows!=matB.rows || cols!=matB.cols ){
			std::cout << "Invalid matrix dimension combination";
		} else {
			Matrix out(rows, cols);
			memcpy(out.buffer, this->buffer, sizeof(mType)*(rows*cols)); // Copy matrix A
			int pos = 0;
			out([&matB, pos](mType &elemFromC){
				int tmpRow = pos/matB.rows; //Get row offset
				int tmpCol = pos%matB.rows; //Get column offset
				elemFromC += matB(tmpRow, tmpCol);
				pos++;
			});
			return out;
		}
	}

	Matrix operator -(float num){
		return (*this)([num](mType& colElem) {	colElem -= num;		});
	}
	Matrix operator *(float num){
		return (*this)([num](mType& colElem) {	colElem *= num;		});
	}
	Matrix operator /(float num){
		return (*this)([num](mType& colElem) {	colElem /= num;		});
	}
	std::ostream operator <<(std::ostream& out){
		this->print(out);	
	}
#pragma endregion

#pragma region Methods
	void set(int iRow, int iCol, mType value){
		(&this->buffer[iRow])[iCol] = value;
	}
	/* Only worls for float matricies */
	void inputMatrix(){
		char * delim = " ";
		for (int iRow = 0; iRow < (int)this->rows; iRow++){
			std::string line;
			char *crIndex = &line[0];
			std::cin.ignore();
			std::cout << "Row[" << iRow << "].columns=";
			std::cin.getline(crIndex, 128);
			int len = strlen(crIndex);
			int iCol = 0;
			do{
				if ((iCol + 1) > (int)cols) break;
				int digitLen = std::search(crIndex, crIndex + len, delim, delim + 1) - crIndex;
				float crFl = (float)atof(crIndex);
				set(iRow, iCol, crFl);
				crIndex = std::search(crIndex, crIndex + len, delim, delim + 1) + 1; //Find next whitespace.
				len -= digitLen + 1;
			} while (len>0);
		}

	}

	bool isDiagonal(){
		return this->rows == this->cols;
	}
	bool isOnDiagonal(int dimensions, int row, int col){
		return (row == col || ((row + col)-1) == dimensions);
	}
	bool isNeighbour(int rowSize, int colSize, int row, int col, int rowB, int colB){
		bool valid = false;
		if (rowSize == colSize){//Diagonal
			valid = isOnDiagonal(rowSize, rowB, colB);
		}
		bool isToTheSide = row == rowB && ( (col > 0 && colB == (col - 1)) || (col < colSize - 1 && colB == (col + 1) )  );
		bool isAbove_or_Below = col == colB && ( (row > 0 && rowB == (row - 1)) || (row < rowSize - 1 && rowB == (row + 1)));
		valid = valid || isToTheSide || isAbove_or_Below; //is to the left/right or above/below
	}
	template<typename tPredicate>
	mType * isEqualNeighbour(Matrix mx, int rowA, int colA, int rowB, int colB, tPredicate filter){
		if (!isNeighbour(mx->rows, mx->cols, rowA, colA, rowB, colB)){
			return NULL;
		}
		if (filter == NULL){
			if (mx(rowA, colA) == mx(rowB, colB)){
				return &mx(rowB, colB);
			}
		}
		else {
			return filter(mx(rowA, colA), mx(rowB, colB));
		}
		
	}

	/*
	@param neighbours: neighbours contains an array of pointers to all valid neighbours
	@returns: the number of neighbours found
	*/
	template<typename tPredicate>
	int getNeighbours(int row, int col, mType & neighbours[8], tPredicate filter){
		int nCoords[8][2] = { 
			{ row - 1, col - 1 }, { row - 1, col }, { row - 1, col + 1 },
			{ row, col +1 },
			{ row + 1, col + 1 }, { row + 1, col }, {row+1, col-1},
			{ row, col -1 }};
		int cFound = 0;
		mType * tmpMatch;
		for (int cNeighour = 0; cNeighour < 8; cNeighbour){
			if (tmpMatch = this->isEqualNeighbour(this, row, col, nCoords[cNeighour][0], nCoords[cNeighour][1]) , filter ){
				neighbours[cFound++] = tmpMatch;
			}
		}
		return cFound;
	}


	/*
	* Universal print method, supports many printing formats.
	*/
	void print(
		std::ostream& out, 
		bool mirroredH = false,
		bool mirroredV = false,
		bool transposed = false,
		bool diagonal = false,
		char diagonalType = DIAGONAL_PRIMARY){

		int tmpColIndex = 0;
		int tmpRowIndex = 0;
		char delimiter = NULL;
		if (diagonal){
			if (!this->isDiagonal()){
				std::cout << "Matrix is not diagonal";
			}
			for (int iRow = 0; iRow < this->rows; iRow++){
				switch (diagonalType){
				case DIAGONAL_PRIMARY: out << (*this)(iRow,iRow) << " "; break;
				case DIAGONAL_SECONDARY: out << (*this)(iRow, this->rows - iRow) << " "; break;
				case DIAGONAL_PRIMARY_LOWER:
					delimiter = '\n';
					for (int iCol = 0; iCol < this->cols; iCol++){
						if (iCol <= iRow){ //Is on or under the primary diagonal
							out << (*this)(iRow, iCol) << "	";
						}
						else break;
					}
					break;
				case DIAGONAL_SECONDARY_UPPER:
					delimiter = '\n';
					for (int iCol = 0; iCol < this->cols; iCol++){
						if ( !iRow || !iCol || (iRow+iCol)==this->rows ){ //Is first row/column or on the secondary diagonal.
							out << (*this)(iRow, iCol) << "	";
						}
					}
					break;
				}
				
				if (delimiter) out << delimiter;
			}
		}
		else {
			for (int iRow = 0; iRow < this->rows; iRow++){
				for (int iCol = 0; iCol < this->cols; iCol++){
					float val;
					tmpRowIndex = mirroredV ? this->rows - iRow : iRow;
					tmpColIndex = mirroredH ? this->cols - iCol : iCol;
					if (transposed){
						int tmppos = tmpRowIndex;
						tmpRowIndex = tmpColIndex;
						tmpColIndex = tmppos;
					}
					val = (*this)(tmpRowIndex, tmpColIndex);
					out << val << "	";
				}
				out << std::endl;
			}
		}
		}
	
	static Matrix addWithCoefficients(float coef1, Matrix<float> matA, float coef2, Matrix<float> matB){
		matA = matA * coef1;
		matB = matB * coef1;
		return matA + matB; // C = c.A + d.B
	}	


	//TODO: Finish this ..
	static int findLongestSequence(Matrix< std::string > mx, std::string* match){
		//iterate each element, and while a valid neighbour index is found, jump to it and add +1
		int tRow = 0;
		int tCol = 0;
		while (tRow < rows){
			while (tCol < cols){
				std::string neighbours[8];
				int matchCount = 0;
				//While there are equal neighbours found
				while (matchCount = mx.getNeighbours(tRow, tCol, neighbours, [matchCount](std::string matchA, std::string matchB){
					return !strcmp(matchA, matchB); // Validate only equal neighbour strings
				})){
					//TODO: Stack instead of recursion, to avoid sucky stack overflow exceptions :D

				}
				tCol++;
			}			

			tRow++;
		}
	}

};
#pragma endregion

#endif