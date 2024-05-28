#include "pch.h"
#include "Matrix.h"
#include "gtest/gtest.h"

TEST(TestCaseName, TestName) {
  EXPECT_EQ(1, 1);
  EXPECT_TRUE(true);
}

TEST(Constructor_does_not_allow_negative_values, Matrix_constructor)
{
	//TODO
}

TEST(Constructor_defaults_all_components_to_zero, Matrix_constructor)
{
	Matrix mat(2, 2);
	EXPECT_EQ(mat[0][0], 0);
	EXPECT_EQ(mat[0][1], 0);
	EXPECT_EQ(mat[1][0], 0);
	EXPECT_EQ(mat[1][1], 0);
}

TEST(Constructor_makes_2_by_3_matrix, Matrix_constructor)
{
	Matrix mat(2, 3);
	EXPECT_EQ(mat.getRows(), 2);
	EXPECT_EQ(mat.getColumns(), 3);
}

TEST(Indexer_gives_correct_component, Matrix_indexer)
{
	Matrix mat(3, 3);
	mat[0][0] = 1;
	mat[0][1] = 2;
	mat[0][2] = 3;
	mat[1][0] = 4;
	mat[1][1] = 5;
	mat[1][2] = 6;
	mat[2][0] = 7;
	mat[2][1] = 8;
	mat[2][2] = 9;

	EXPECT_EQ(mat[0][0], 1);
	EXPECT_EQ(mat[0][1], 2);
	EXPECT_EQ(mat[0][2], 3);
	EXPECT_EQ(mat[1][0], 4);
	EXPECT_EQ(mat[1][1], 5);
	EXPECT_EQ(mat[1][2], 6);
	EXPECT_EQ(mat[2][0], 7);
	EXPECT_EQ(mat[2][1], 8);
	EXPECT_EQ(mat[2][2], 9);
}

TEST(Indexer_throws_exception_when_out_of_range, Matrix_indexer)
{
	//TODO
}

//TODO: rework operator[] in a next version to use something that throws exception (like .at())
//		using [] operator directly without checking boundaries creates undefined behaviour
TEST(Indexer_throws_exeption_when_row_indexer_negative, Matrix_indexer)
{
	Matrix mat(3, 3);

	EXPECT_THROW(
		{
			mat[0].at(-1);
		}, std::out_of_range);
}

//TODO: prevent user from modifying vector size

TEST(Addition_throws_exception_when_matrix_rows_are_unequal, Matrix_addition)
{
	Matrix mat1(2, 3);
	Matrix mat2(3, 3);

	EXPECT_THROW(
		{
			mat1 + mat2;
		}, std::invalid_argument);
}

TEST(Addition_throws_exception_when_matrix_columns_are_unequal, Matrix_addition)
{
	Matrix mat1(3, 2);
	Matrix mat2(3, 3);

	EXPECT_THROW(
		{
			mat1 + mat2;
		}, std::invalid_argument);
}

TEST(Addition_with_zero_matrix_does_not_change_matrix, Matrix_addition)
{
	Matrix mat1(3, 3);
	mat1[0][0] = 1;
	mat1[0][1] = 2;
	mat1[0][2] = 3;
	mat1[1][0] = 4;
	mat1[1][1] = 5;
	mat1[1][2] = 6;
	mat1[2][0] = 7;
	mat1[2][1] = 8;
	mat1[2][2] = 9;
	Matrix zeroMat(3, 3);

	Matrix mat2 = mat1 + zeroMat;

	EXPECT_EQ(mat2[0][0], 1);
	EXPECT_EQ(mat2[0][1], 2);
	EXPECT_EQ(mat2[0][2], 3);
	EXPECT_EQ(mat2[1][0], 4);
	EXPECT_EQ(mat2[1][1], 5);
	EXPECT_EQ(mat2[1][2], 6);
	EXPECT_EQ(mat2[2][0], 7);
	EXPECT_EQ(mat2[2][1], 8);
	EXPECT_EQ(mat2[2][2], 9);
}

TEST(Addition_adds_two_matrices_together, Matrix_addition)
{
	Matrix mat1(3, 3);
	mat1[0][0] = 1;
	mat1[0][1] = 2;
	mat1[0][2] = 3;
	mat1[1][0] = 4;
	mat1[1][1] = 5;
	mat1[1][2] = 6;
	mat1[2][0] = 7;
	mat1[2][1] = 8;
	mat1[2][2] = 9;

	Matrix mat2(3, 3);
	mat2[0][0] = 1;
	mat2[0][1] = 2;
	mat2[0][2] = 3;
	mat2[1][0] = 4;
	mat2[1][1] = 5;
	mat2[1][2] = 6;
	mat2[2][0] = 7;
	mat2[2][1] = 8;
	mat2[2][2] = 9;

	Matrix mat3 = mat1 + mat2;

	EXPECT_EQ(mat3[0][0], 2);
	EXPECT_EQ(mat3[0][1], 4);
	EXPECT_EQ(mat3[0][2], 6);
	EXPECT_EQ(mat3[1][0], 8);
	EXPECT_EQ(mat3[1][1], 10);
	EXPECT_EQ(mat3[1][2], 12);
	EXPECT_EQ(mat3[2][0], 14);
	EXPECT_EQ(mat3[2][1], 16);
	EXPECT_EQ(mat3[2][2], 18);
}

TEST(Addition_treats_negative_values_as_subtraction, Matrix_addition)
{
	Matrix mat1(3, 3);
	mat1[0][0] = 1;
	mat1[0][1] = 2;
	mat1[0][2] = 3;
	mat1[1][0] = 4;
	mat1[1][1] = 5;
	mat1[1][2] = 6;
	mat1[2][0] = 7;
	mat1[2][1] = 8;
	mat1[2][2] = 9;

	Matrix mat2(3, 3);
	mat2[0][0] = -1;
	mat2[0][1] = -2;
	mat2[0][2] = -3;
	mat2[1][0] = -4;
	mat2[1][1] = -5;
	mat2[1][2] = -6;
	mat2[2][0] = -7;
	mat2[2][1] = -8;
	mat2[2][2] = -9;

	Matrix mat3 = mat1 + mat2;

	EXPECT_EQ(mat3[0][0], 0);
	EXPECT_EQ(mat3[0][1], 0);
	EXPECT_EQ(mat3[0][2], 0);
	EXPECT_EQ(mat3[1][0], 0);
	EXPECT_EQ(mat3[1][1], 0);
	EXPECT_EQ(mat3[1][2], 0);
	EXPECT_EQ(mat3[2][0], 0);
	EXPECT_EQ(mat3[2][1], 0);
	EXPECT_EQ(mat3[2][2], 0);
}

//TODO: subtraction tests
TEST(Subtraction_throws_exception_when_matrix_rows_are_unequal, Matrix_subtraction)
{
	Matrix mat1(3, 3);
	Matrix mat2(2, 3);

	EXPECT_THROW(
		{
			mat1 - mat2;
		}, std::invalid_argument);
}

TEST(Subtraction_throws_exception_when_matrix_columns_are_unequal, Matrix_subtraction)
{
	Matrix mat1(3, 3);
	Matrix mat2(3, 2);

	EXPECT_THROW(
		{
			mat1 - mat2;
		}, std::invalid_argument);
}

TEST(Subtraction_with_zero_matrix_does_not_change_matrix, Matrix_subtraction)
{
	Matrix mat1(3, 3);
	mat1[0][0] = 1;
	mat1[0][1] = 2;
	mat1[0][2] = 3;
	mat1[1][0] = 4;
	mat1[1][1] = 5;
	mat1[1][2] = 6;
	mat1[2][0] = 7;
	mat1[2][1] = 8;
	mat1[2][2] = 9;
	Matrix zeroMat(3, 3);

	Matrix mat2 = mat1 - zeroMat;

	EXPECT_EQ(mat2[0][0], 1);
	EXPECT_EQ(mat2[0][1], 2);
	EXPECT_EQ(mat2[0][2], 3);
	EXPECT_EQ(mat2[1][0], 4);
	EXPECT_EQ(mat2[1][1], 5);
	EXPECT_EQ(mat2[1][2], 6);
	EXPECT_EQ(mat2[2][0], 7);
	EXPECT_EQ(mat2[2][1], 8);
	EXPECT_EQ(mat2[2][2], 9);
}

TEST(Subtraction_subtracts_two_matrices_from_another, Matrix_subtraction)
{
	Matrix mat1(3, 3);
	mat1[0][0] = 2;
	mat1[0][1] = 3;
	mat1[0][2] = 4;
	mat1[1][0] = 5;
	mat1[1][1] = 6;
	mat1[1][2] = 7;
	mat1[2][0] = 8;
	mat1[2][1] = 9;
	mat1[2][2] = 10;

	Matrix mat2(3, 3);
	mat2[0][0] = 1;
	mat2[0][1] = 2;
	mat2[0][2] = 3;
	mat2[1][0] = 4;
	mat2[1][1] = 5;
	mat2[1][2] = 6;
	mat2[2][0] = 7;
	mat2[2][1] = 8;
	mat2[2][2] = 9;

	Matrix mat3 = mat1 - mat2;

	EXPECT_EQ(mat3[0][0], 1);
	EXPECT_EQ(mat3[0][1], 1);
	EXPECT_EQ(mat3[0][2], 1);
	EXPECT_EQ(mat3[1][0], 1);
	EXPECT_EQ(mat3[1][1], 1);
	EXPECT_EQ(mat3[1][2], 1);
	EXPECT_EQ(mat3[2][0], 1);
	EXPECT_EQ(mat3[2][1], 1);
	EXPECT_EQ(mat3[2][2], 1);
}

TEST(Subtraction_treats_negative_values_as_subtraction, Matrix_subtraction)
{
	Matrix mat1(3, 3);
	mat1[0][0] = 1;
	mat1[0][1] = 2;
	mat1[0][2] = 3;
	mat1[1][0] = 4;
	mat1[1][1] = 5;
	mat1[1][2] = 6;
	mat1[2][0] = 7;
	mat1[2][1] = 8;
	mat1[2][2] = 9;

	Matrix mat2(3, 3);
	mat2[0][0] = -1;
	mat2[0][1] = -2;
	mat2[0][2] = -3;
	mat2[1][0] = -4;
	mat2[1][1] = -5;
	mat2[1][2] = -6;
	mat2[2][0] = -7;
	mat2[2][1] = -8;
	mat2[2][2] = -9;

	Matrix mat3 = mat1 - mat2;

	EXPECT_EQ(mat3[0][0], 2);
	EXPECT_EQ(mat3[0][1], 4);
	EXPECT_EQ(mat3[0][2], 6);
	EXPECT_EQ(mat3[1][0], 8);
	EXPECT_EQ(mat3[1][1], 10);
	EXPECT_EQ(mat3[1][2], 12);
	EXPECT_EQ(mat3[2][0], 14);
	EXPECT_EQ(mat3[2][1], 16);
	EXPECT_EQ(mat3[2][2], 18);
}

TEST(Transpose_flips_matrix_on_diagonal, Matrix_transpose)
{
	Matrix mat1(3, 3);
	mat1[0][0] = 1;
	mat1[0][1] = 2;
	mat1[0][2] = 3;
	mat1[1][0] = 4;
	mat1[1][1] = 5;
	mat1[1][2] = 6;
	mat1[2][0] = 7;
	mat1[2][1] = 8;
	mat1[2][2] = 9;

	Matrix mat2 = mat1.transpose();

	EXPECT_EQ(mat2[0][0], 1);
	EXPECT_EQ(mat2[0][1], 4);
	EXPECT_EQ(mat2[0][2], 7);
	EXPECT_EQ(mat2[1][0], 2);
	EXPECT_EQ(mat2[1][1], 5);
	EXPECT_EQ(mat2[1][2], 8);
	EXPECT_EQ(mat2[2][0], 3);
	EXPECT_EQ(mat2[2][1], 6);
	EXPECT_EQ(mat2[2][2], 9);
}