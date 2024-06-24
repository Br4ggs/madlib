#include "pch.h"
#include "Matrix.h"
#include <stdexcept>

Matrix::Matrix(int rows, int columns)
	:rows(rows), columns(columns)
{
	for (int r = 0; r < rows; r++)
	{
		components.push_back(std::vector<float>(columns, 0));
	}
}

std::vector<float>& Matrix::operator[](const int index)
{
	return components[index];
}

const std::vector<float>& Matrix::operator[](const int index) const
{
	return components[index];
}

Matrix Matrix::operator+(const Matrix& mat) const
{
	if (this->rows != mat.rows)
		throw std::invalid_argument("Row dimensions of matrices do not match");
	if (this->columns != mat.columns)
		throw std::invalid_argument("Column dimensions of matrices do not match");

	Matrix result(this->rows, this->columns);

	for (int i = 0; i < this->rows; i++)
	{
		for (int j = 0; j < this->columns; j++)
		{
			float a = (*this)[i][j];
			float b = mat[i][j];
			result[i][j] = a + b;
		}
	}

	return result;
}

Matrix Matrix::operator-(const Matrix& mat) const
{
	if (this->rows != mat.rows)
		throw std::invalid_argument("Row dimensions of matrices do not match");
	if (this->columns != mat.columns)
		throw std::invalid_argument("Column dimensions of matrices do not match");

	Matrix result(this->rows, this->columns);

	for (int i = 0; i < this->rows; i++)
	{
		for (int j = 0; j < this->columns; j++)
		{
			float a = (*this)[i][j];
			float b = mat[i][j];
			result[i][j] = a - b;
		}
	}

	return result;
}

Matrix Matrix::operator*(const Matrix& mat) const
{
	if (this->columns != mat.rows)
		throw std::invalid_argument("columns of first matrix and rows of second matrix do not match");

	//naive implementation, Could be interesting to change to something more efficient
	Matrix result(this->rows, mat.columns);
	for (int i = 0; i < result.rows; i++)
	{
		for (int j = 0; j < result.columns; j++)
		{
			float val = 0;
			for (int x = 0; x < this->columns; x++)
			{
				float a = (*this)[i][x];
				float b = mat[x][j];
				val += a * b;
			}

			result[i][j] = val;
		}
	}

	return result;
}

Matrix Matrix::transpose() const
{
	Matrix result(this->columns, this->rows);

	for (int i = 0; i < this->rows; i++)
	{
		for (int j = 0; j < this->columns; j++)
		{
			result[j][i] = (*this)[i][j];
		}
	}

	return result;
}

Matrix Matrix::submatrix(unsigned int row, unsigned int column) const
{
	if (row >= this->rows)
		throw std::invalid_argument("Specified row is out of range");
	if (column >= this->columns)
		throw std::invalid_argument("Specified column is out of range");

	Matrix mat(this->rows - 1, this->columns - 1);

	unsigned int resultingRow = 0;
	for (int i = 0; i < this->rows; i++)
	{
		if (i == row) continue;

		unsigned int resultingColumn = 0;
		for (int j = 0; j < this->columns; j++)
		{
			if (j == column) continue;

			mat[resultingRow][resultingColumn] = (*this)[i][j];
			resultingColumn++;
		}

		resultingRow++;
	}

	return mat;
}

float Matrix::determinant() const
{
	if (this->rows != this->columns)
		throw std::invalid_argument("Matrix is non-square");

	return det(*this);
}

float Matrix::det(const Matrix mat) const
{
	if (mat.rows == 2 && mat.columns == 2)
	{
		return (mat[0][0] * mat[1][1]) - (mat[1][0] * mat[0][1]);
	}

	else
	{
		float result = 0;
		int sign = 1;
		for (int i = 0; i < mat.columns; i++)
		{
			result += (float)sign * (mat[0][i] * det(mat.submatrix(0, i)));
			sign *= -1;
		}

		return result;
	}
}

Matrix Matrix::inverse() const
{
	if (this->rows != this->columns)
		throw std::invalid_argument("Matrix is non-square");

	float determinant = this->determinant();

	if (determinant == 0)
		throw std::invalid_argument("Matrix is singular (determinant is 0)");

	if (this->rows == 2)
	{
		//add scalar multiplication plox
		float recip = 1 / determinant;
		Matrix inv(2, 2);
		inv[0][0] = recip * (*this)[1][1];
		inv[0][1] = recip * -1 * (*this)[0][1];
		inv[1][0] = recip * -1 * (*this)[1][0];
		inv[1][1] = recip * (*this)[0][0];
	}
}

int Matrix::getRows() const
{
	return rows;
}

int Matrix::getColumns() const
{
	return columns;
}
