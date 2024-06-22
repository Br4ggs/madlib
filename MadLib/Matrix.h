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

	/// <summary>
	/// Returns the transposition of the matrix
	/// </summary>
	/// <returns>The transposed matrix</returns>
	Matrix transpose() const;

	/// <summary>
	/// Specific submatrix routine implementation that is for determinant calculations.
	/// Deletes a single row and column and returns the result
	/// </summary>
	/// <param name="row">The row to be deleted</param>
	/// <param name="column">The column to be deleted</param>
	/// <returns>The resulting matrix</returns>
	Matrix submatrix(const unsigned int row, const unsigned int column) const;

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