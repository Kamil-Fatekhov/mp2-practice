#include "tmatrix.h"

#include "gtest.h"

TEST(TMatrix, can_create_matrix_with_positive_length)
{
	ASSERT_NO_THROW(TMatrix<int> m(5));
}

TEST(TMatrix, cant_create_too_large_matrix)
{
	ASSERT_ANY_THROW(TMatrix<int> m(MAX_MATRIX_SIZE + 1));
}

TEST(TMatrix, throws_when_create_matrix_with_negative_length)
{
	ASSERT_ANY_THROW(TMatrix<int> m(-5));
}

TEST(TMatrix, can_create_copied_matrix)
{
	TMatrix<int> m(5);

	ASSERT_NO_THROW(TMatrix<int> m1(m));
}

TEST(TMatrix, copied_matrix_is_equal_to_source_one)
{
	TMatrix<int> m(5);
	m[1][1] = 3;
	TMatrix<int> m1(m);
	cout << m << endl;
	cout << m1 << endl;
	bool res = (m == m1);
	EXPECT_EQ(res, 1);
}

TEST(TMatrix, can_get_size)
{
	TMatrix<int> m(4);
	ASSERT_NO_THROW(m.GetSize());
}

TEST(TMatrix, can_set_and_get_element)
{
	TMatrix<int> m(5);
	m[2][3] = 3;
	cout << m;
	EXPECT_EQ(3, m[2][3]);
}

TEST(TMatrix, throws_when_set_element_with_negative_index)
{
	TMatrix<int> m(5);
	ASSERT_ANY_THROW(m[-1][-2] = 3);
}

TEST(TMatrix, throws_when_set_element_with_too_large_index)
{
	TMatrix<int> m(5);
	ASSERT_ANY_THROW(m[6][0] = 4);
}

TEST(TMatrix, can_assign_matrix_to_itself)
{
	TMatrix<int> m(5);
	ASSERT_NO_THROW(m = m);
}

TEST(TMatrix, can_assign_matrices_of_equal_size)
{
	TMatrix<int> m(5),m1(6);
	m[2][0] = 3;
	ASSERT_NO_THROW(m = m1);
}

TEST(TMatrix, assign_operator_change_matrix_size)
{
	int size = 5;
	int new_size = 6;
	TMatrix<int> m(size);
	TMatrix<int> m1(new_size);
	m = m1;
	EXPECT_EQ(6, m.GetSize());
}

TEST(TMatrix, can_assign_matrices_of_different_size)
{
	int size = 5;
	int new_size = 6;
	TMatrix<int> m(size);
	TMatrix<int> m1(new_size);
	ASSERT_NO_THROW(m = m1);
}

TEST(TMatrix, compare_equal_matrices_return_true)
{
	TMatrix<int> m(5), m1(5);
	m[2][3] = 3;
	m1[2][3] = 3;
	bool res = (m == m1);
	EXPECT_EQ(true, res);
}

TEST(TMatrix, compare_matrix_with_itself_return_true)
{
	TMatrix<int> m(5);
	bool res = (m == m);
	EXPECT_EQ(true, res);
}

TEST(TMatrix, matrices_with_different_size_are_not_equal)
{
	TMatrix<int> m(5), m1(6);
	m[2][3] = 3;
	m1[2][3] = 3;
	bool res = (m == m1);
	EXPECT_NE(true, res);
}

TEST(TMatrix, can_add_matrices_with_equal_size)
{
	TMatrix<int> m(5), m1(5);
	m[2][3] = 3;
	ASSERT_NO_THROW(m + m1);
}

TEST(TMatrix, cant_add_matrices_with_not_equal_size)
{
	TMatrix<int> m(5), m1(6);
	m[2][3] = 3;
	ASSERT_ANY_THROW(m + m1);
}

TEST(TMatrix, can_subtract_matrices_with_equal_size)
{
	TMatrix<int> m(5), m1(5);
	m[2][3] = 3;
	ASSERT_NO_THROW(m1 - m);
}

TEST(TMatrix, cant_subtract_matrixes_with_not_equal_size)
{
	TMatrix<int> m(5), m1(6);
	m[2][3] = 3;
	ASSERT_ANY_THROW(m1 - m);
}