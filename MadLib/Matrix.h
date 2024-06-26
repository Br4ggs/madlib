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

	int getRows() const;
	int getColumns() const;


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

	float determinant() const;

	/// <summary>
	/// Calculates the inverse of this matrix using the analytic solution
	/// i.e. by calculating the minors cofactors and adjugate
	/// </summary>
	/// <returns>The inverse of the matrix</returns>
	Matrix inverse() const;

	//TODO: inverse
	//see https://www.mathsisfun.com/algebra/matrix-inverse-minors-cofactors-adjugate.html
	
	//TODO: identity matrix
	//TODO: debug print

private:
	int rows;
	int columns;

	// vectors are used to allow construction during initialization
	std::vector<std::vector<float>> components;

	float det(const Matrix mat) const;
};

#endif // !MATRIX_H