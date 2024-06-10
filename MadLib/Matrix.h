#ifndef MATRIX_H
#define MATRIX_H

#include <vector>

/// <summary>
/// matrix[row][column]
/// </summary>
class Matrix
{
public:
	Matrix(int rows, int columns); //Unsigned?
	Matrix() = delete;

	int getRows();
	int getColumns();


	//https://stackoverflow.com/questions/33642050/overloading-subscript-operators-for-specific-read-and-write-operations
	std::vector<float>& operator[](const int index);				//for setting values
	const std::vector<float>& operator[](const int index) const;	//for getting values

	Matrix operator+(const Matrix& mat) const;
	Matrix operator-(const Matrix& mat) const;
	Matrix operator*(const Matrix& mat) const;

	Matrix transpose() const;
	//TODO: inverse
	//TODO: identity matrix
	//TODO: debug print

private:
	int rows;
	int columns;

	// vectors are used to allow construction during initialization
	std::vector<std::vector<float>> components;
};

#endif // !MATRIX_H