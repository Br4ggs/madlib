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

int Matrix::getRows()
{
	return rows;
}

int Matrix::getColumns()
{
	return columns;
}

