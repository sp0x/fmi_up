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
		Matrix(rows, cols, (float*)calloc(rows*cols, sizeof(float))); //Allocate space for the matrix, by using it's total element count
	}
	Matrix(int rows, int cols, float * buffer){
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
	float * operator [](int row) const {
		return &buffer[row * sizeof(float)];
	}
	float & operator [](int row) {
		return buffer[row * sizeof(float)];
	}
	template<typename Func>
	Matrix operator()(Func function){
		for (int iRow = 0; iRow < this->rows; iRow++){
			for (int iCol = 0; iCol < this->cols; iCol++){
				function( (&( this->buffer[iRow] )) [iCol]);
			}
		}
		return Matrix(this->rows, this->cols, this->buffer);
	}

	
	Matrix operator +(float num){
		return (*this)([num](float& colElem){	colElem += num;		});
	}
	Matrix operator +(int num){
		return (*this)([num](int& colElem){	colElem += num;		});
	}
	Matrix operator +(Matrix matB){
		if ( rows!=matB.rows || cols!=matB.cols ){
			std::cout << "Invalid matrix dimension combination";
		} else {
			Matrix out(rows, cols);
			memcpy(out.buffer, this->buffer, sizeof(float)*(rows*cols)); // Copy matrix A
			int pos = 0;
			out([&matB, pos](float &elemFromC){
				int tmpRow = pos/matB.rows; //Get row offset
				int tmpCol = pos%matB.rows; //Get column offset
				elemFromC += (&matB[tmpRow])[tmpCol];
			});
			return out;
		}
	}

	Matrix operator -(float num){
		return (*this)([num](float& colElem) {	colElem -= num;		});
	}
	Matrix operator *(float num){
		return (*this)([num](float& colElem) {	colElem *= num;		});
	}
	Matrix operator /(float num){
		return (*this)([num](float& colElem) {	colElem /= num;		});
	}
	std::ostream operator <<(std::ostream& out){
		this->print(out);	
	}
#pragma endregion

#pragma region Methods
	void set(int iRow, int iCol, float value){
		(&this->buffer[iRow])[iCol] = value;
	}

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
				case DIAGONAL_PRIMARY: out << (&(*this)[iRow])[iRow] << " "; break;
				case DIAGONAL_SECONDARY: out << (&(*this)[iRow])[this->rows - iRow] << " "; break;
				case DIAGONAL_PRIMARY_LOWER:
					delimiter = '\n';
					for (int iCol = 0; iCol < this->cols; iCol++){
						if (iCol <= iRow){ //Is on or under the primary diagonal
							out << (&(*this)[iRow])[iCol] << "	";
						}
						else break;
					}
					break;
				case DIAGONAL_SECONDARY_UPPER:
					delimiter = '\n';
					for (int iCol = 0; iCol < this->cols; iCol++){
						if ( !iRow || !iCol || (iRow+iCol)==this->rows ){ //Is first row/column or on the secondary diagonal.
							out << (&(*this)[iRow])[iCol] << "	";
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
					val = (&(*this)[tmpRowIndex])[tmpColIndex];
					out << val << "	";
				}
				out << std::endl;
			}
		}
		}
	
	static Matrix addWithCoefficients(float coef1, Matrix matA, float coef2, Matrix matB){
		matA = matA * coef1;
		matB = matB * coef1;
		return matA + matB; // C = c.A + d.B
	}	


};
#pragma endregion

#endif