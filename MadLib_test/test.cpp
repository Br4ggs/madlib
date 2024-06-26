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

TEST(Transpose_flips_matrix_dimensions, Matrix_transpose)
{
	Matrix mat1(3, 1);
	mat1[0][0] = 1;
	mat1[1][0] = 2;
	mat1[2][0] = 3;

	Matrix mat2 = mat1.transpose();

	EXPECT_EQ(mat2.getRows(), 1);
	EXPECT_EQ(mat2.getColumns(), 3);
	EXPECT_EQ(mat2[0][0], 1);
	EXPECT_EQ(mat2[0][1], 2);
	EXPECT_EQ(mat2[0][2], 3);

}

TEST(Multiplication_multiplies_two_positive_matrices, Matrix_multiply)
{
	Matrix mat1(2, 2);
	mat1[0][0] = 2;
	mat1[0][1] = 3;
	mat1[1][0] = 4;
	mat1[1][1] = 5;
	Matrix mat2(2, 2);
	mat2[0][0] = 6;
	mat2[0][1] = 7;
	mat2[1][0] = 8;
	mat2[1][1] = 9;

	Matrix mat3 = mat1 * mat2;

	EXPECT_EQ(mat3[0][0], 36);
	EXPECT_EQ(mat3[0][1], 41);
	EXPECT_EQ(mat3[1][0], 64);
	EXPECT_EQ(mat3[1][1], 73);
}

TEST(Multiplication_throws_exception_when_matrix_columns_and_rows_are_not_equal, Matrix_multiply)
{
	Matrix mat1(3, 2);
	Matrix mat2(3, 3);

	EXPECT_THROW(
		{
			mat1 * mat2;
		}, std::invalid_argument);
}

TEST(Multiplication_creates_a_IxN_matrix_from_a_IxM_and_MxN, Matrix_multiply)
{
	Matrix mat1(4, 3);
	mat1[0][0] = 2;
	mat1[0][1] = 3;
	mat1[0][2] = 4;
	mat1[1][0] = 5;
	mat1[1][1] = 6;
	mat1[1][2] = 7;
	mat1[2][0] = 8;
	mat1[2][1] = 9;
	mat1[2][2] = 19;
	mat1[3][0] = 11;
	mat1[3][1] = 12;
	mat1[3][2] = 13;
	Matrix mat2(3, 5);
	mat2[0][0] = 14;
	mat2[0][1] = 15;
	mat2[0][2] = 16;
	mat2[0][3] = 17;
	mat2[0][4] = 18;
	mat2[1][0] = 19;
	mat2[1][1] = 20;
	mat2[1][2] = 21;
	mat2[1][3] = 22;
	mat2[1][4] = 23;
	mat2[2][0] = 24;
	mat2[2][1] = 25;
	mat2[2][2] = 26;
	mat2[2][3] = 27;
	mat2[2][4] = 28;

	Matrix mat3 = mat1 * mat2;
	EXPECT_EQ(mat3.getRows(), 4);
	EXPECT_EQ(mat3.getColumns(), 5);
	EXPECT_EQ(mat3[0][0], 181);
	EXPECT_EQ(mat3[0][1], 190);
	EXPECT_EQ(mat3[0][2], 199);
	EXPECT_EQ(mat3[0][3], 208);
	EXPECT_EQ(mat3[0][4], 217);
	EXPECT_EQ(mat3[1][0], 352);
	EXPECT_EQ(mat3[1][1], 370);
	EXPECT_EQ(mat3[1][2], 388);
	EXPECT_EQ(mat3[1][3], 406);
	EXPECT_EQ(mat3[1][4], 424);
	EXPECT_EQ(mat3[2][0], 739);
	EXPECT_EQ(mat3[2][1], 775);
	EXPECT_EQ(mat3[2][2], 811);
	EXPECT_EQ(mat3[2][3], 847);
	EXPECT_EQ(mat3[2][4], 883);
	EXPECT_EQ(mat3[3][0], 694);
	EXPECT_EQ(mat3[3][1], 730);
	EXPECT_EQ(mat3[3][2], 766);
	EXPECT_EQ(mat3[3][3], 802);
	EXPECT_EQ(mat3[3][4], 838);
}

TEST(Multiplication_multiplies_matrices_in_the_correct_order, Matrix_multiply)
{
	Matrix mat1(2, 2);
	mat1[0][0] = 2;
	mat1[0][1] = 3;
	mat1[1][0] = 4;
	mat1[1][1] = 5;
	Matrix mat2(2, 2);
	mat2[0][0] = 6;
	mat2[0][1] = 7;
	mat2[1][0] = 8;
	mat2[1][1] = 9;
	Matrix mat3(2, 2);
	mat3[0][0] = 10;
	mat3[0][1] = 11;
	mat3[1][0] = 12;
	mat3[1][1] = 13;

	Matrix mat4 = mat1 * mat2 * mat3;

	EXPECT_EQ(mat4[0][0], 852);
	EXPECT_EQ(mat4[0][1], 929);
	EXPECT_EQ(mat4[1][0], 1516);
	EXPECT_EQ(mat4[1][1], 1653);
}

TEST(Submatrix_removes_a_single_row_and_column, Matrix_submatrix)
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

	Matrix submat = mat.submatrix(1, 2);

	EXPECT_EQ(submat.getRows(), 2);
	EXPECT_EQ(submat.getColumns(), 2);
	EXPECT_EQ(submat[0][0], 1);
	EXPECT_EQ(submat[0][1], 2);
	EXPECT_EQ(submat[1][0], 7);
	EXPECT_EQ(submat[1][1], 8);
}

TEST(Submatrix_throws_exception_when_specified_row_or_column_is_out_of_range, Matrix_submatrix)
{
	Matrix mat(2, 2);

	EXPECT_THROW(
		{
			mat.submatrix(2, -1);
		}, std::invalid_argument);
}

TEST(Submatrix_removes_specified_rows_and_columns_and_returns_new_matrix, Matrix_submatrix)
{
	//TODO when we add methods for removing multiple rows and columns
}

TEST(Determinant_correctly_calculates_determinant_for_2x2_matrix, Matrix_determinant)
{
	Matrix mat(2, 2);
	mat[0][0] = 2;
	mat[0][1] = 3;
	mat[1][0] = 2;
	mat[1][1] = 3;

	int det = mat.determinant();

	EXPECT_EQ(det, 0);
}

TEST(Determinant_correctly_calculates_determinant_for_2x2_float_matrix, Matrix_determinant)
{
	Matrix mat(2, 2);
	mat[0][0] = 1.0f/2.0f;
	mat[0][1] = 2.0f/3.0f;
	mat[1][0] = 3.0f/8.0f;
	mat[1][1] = 4.0f/16.0f;

	float det = mat.determinant();

	EXPECT_EQ(det, -1.0f/8.0f);
}

TEST(Determinant_correctly_calculates_determinant_for_3x3_matrix, Matrix_determinant)
{
	Matrix mat(3, 3);
	mat[0][0] = 2;
	mat[0][1] = 5;
	mat[0][2] = -1;
	mat[1][0] = 4;
	mat[1][1] = 9;
	mat[1][2] = 6;
	mat[2][0] = 7;
	mat[2][1] = 8;
	mat[2][2] = 3;

	int det = mat.determinant();

	EXPECT_EQ(det, 139);
}

TEST(Determinant_correctly_calculates_determinant_for_4x4_matrix, Matrix_determinant)
{
	Matrix mat(4, 4);
	mat[0][0] = 1;
	mat[0][1] = 3;
	mat[0][2] = 5;
	mat[0][3] = 9;
	mat[1][0] = 1;
	mat[1][1] = 3;
	mat[1][2] = 1;
	mat[1][3] = 7;
	mat[2][0] = 4;
	mat[2][1] = 3;
	mat[2][2] = 9;
	mat[2][3] = 7;
	mat[3][0] = 5;
	mat[3][1] = 2;
	mat[3][2] = 0;
	mat[3][3] = 9;

	int det = mat.determinant();

	EXPECT_EQ(det, -376);
}

TEST(Determinant_throws_exception_when_matrix_is_non_square, Matrix_determinant)
{
	Matrix mat(3, 4);

	EXPECT_THROW(
		{
			mat.determinant();
		}, std::invalid_argument);
}

TEST(Inverse_calculates_the_inverse_of_a_2x2_matrix, Matrix_inverse)
{
	Matrix mat(2, 2);
	mat[0][0] = 1;
	mat[0][1] = 2;
	mat[1][0] = 3;
	mat[1][1] = 4;

	Matrix inv = mat.inverse();

	EXPECT_EQ(inv[0][0], -2.0f);
	EXPECT_EQ(inv[0][1], 1.0f);
	EXPECT_EQ(inv[1][0], 3.0f/2.0f);
	EXPECT_EQ(inv[1][1], -1.0f/2.0f);

	Matrix res = mat * inv;

	EXPECT_EQ(res[0][0], 1);
	EXPECT_EQ(res[0][1], 0);
	EXPECT_EQ(res[1][0], 0);
	EXPECT_EQ(res[1][1], 1);
}

TEST(Inverse_calculates_the_inverse_of_a_3x3_matrix, Matrix_inverse)
{
	Matrix mat(3, 3);
	mat[0][0] = 3;
	mat[0][1] = 0;
	mat[0][2] = 2;
	mat[1][0] = 2;
	mat[1][1] = 0;
	mat[1][2] = -2;
	mat[2][0] = 0;
	mat[2][1] = 1;
	mat[2][2] = 1;

	Matrix inv = mat.inverse();
	EXPECT_EQ(inv[0][0],  0.2f);
	EXPECT_EQ(inv[0][1],  0.2f);
	EXPECT_EQ(inv[0][2],  0.0f);
	EXPECT_EQ(inv[1][0], -0.2f);
	EXPECT_EQ(inv[1][1],  0.3f);
	EXPECT_EQ(inv[1][2],  1.0f);
	EXPECT_EQ(inv[2][0],  0.2f);
	EXPECT_EQ(inv[2][1], -0.3f);
	EXPECT_EQ(inv[2][2],  0);
}

//singular matrix test

//1x1 matrix test? -> throws exception

//4x4 matrix test
