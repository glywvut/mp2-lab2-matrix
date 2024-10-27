#include "tmatrix.h"

#include <gtest.h>

TEST(TDynamicVector, can_create_vector_with_positive_length)
{
  ASSERT_NO_THROW(TDynamicVector<int> v(5));
}

TEST(TDynamicVector, cant_create_too_large_vector)
{
  ASSERT_ANY_THROW(TDynamicVector<int> v(MAX_VECTOR_SIZE + 1));
}

TEST(TDynamicVector, throws_when_create_vector_with_negative_length)
{
  ASSERT_ANY_THROW(TDynamicVector<int> v(-5));
}

TEST(TDynamicVector, can_create_copied_vector)
{
  TDynamicVector<int> v(10);

  ASSERT_NO_THROW(TDynamicVector<int> v1(v));
}

TEST(TDynamicVector, copied_vector_is_equal_to_source_one)
{
    int* arr = new int[10] {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    TDynamicVector<int> v1(arr, 10);
    delete[] arr;
    TDynamicVector<int> v2(v1);

    EXPECT_EQ(v1, v2);
}

TEST(TDynamicVector, copied_vector_has_its_own_memory)
{
    int* arr = new int[10] {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    TDynamicVector<int> v1(arr, 10);
    delete[] arr;
    TDynamicVector<int> v2(v1);
    TDynamicVector<int>* p1 = &v1;
    TDynamicVector<int>* p2 = &v2;

    EXPECT_NE(p1, p2);
}

TEST(TDynamicVector, can_get_size)
{
  TDynamicVector<int> v(4);

  EXPECT_EQ(4, v.size());
}

//TEST(TDynamicVector, can_set_and_get_element)
//{
//  TDynamicVector<int> v(4);
//  v[0] = 4;
//
//  EXPECT_EQ(4, v[0]);
//}

TEST(TDynamicVector, throws_when_set_element_with_negative_index)
{
    TDynamicVector<int> v(10);

    ASSERT_ANY_THROW(v.at(-1) = 1);
}

TEST(TDynamicVector, throws_when_set_element_with_too_large_index)
{
    TDynamicVector<int> v(10);

    ASSERT_ANY_THROW(v.at(10) = 1);
}

TEST(TDynamicVector, can_assign_vector_to_itself)
{
    TDynamicVector<int> v(10);

    ASSERT_NO_THROW(v = v);
}

TEST(TDynamicVector, can_assign_vectors_of_equal_size)
{
    TDynamicVector<int> v1(10);
    TDynamicVector<int> v2(10);
    v1 = v2;

    EXPECT_EQ(v1, v2);
}

TEST(TDynamicVector, assign_operator_change_vector_size)
{
    TDynamicVector<int> v1(5);
    size_t fsize = v1.size();
    TDynamicVector<int> v2(10);
    v1 = v2;
    size_t ssize = v1.size();

    EXPECT_NE(fsize, ssize);
}

TEST(TDynamicVector, can_assign_vectors_of_different_size)
{
    int* arr = new int[10] {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    TDynamicVector<int> v1(arr, 10);
    TDynamicVector<int> v2(5);
    v1 = v2;

    EXPECT_EQ(v1, v2);
}

TEST(TDynamicVector, compare_equal_vectors_return_true)
{
    int* arr = new int[10] {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    TDynamicVector<int> v1(arr, 10);
    TDynamicVector<int> v2(arr, 10);

    EXPECT_TRUE(v1 == v2);
}

TEST(TDynamicVector, compare_vector_with_itself_return_true)
{
    int* arr = new int[10] {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    TDynamicVector<int> v1(arr, 10);

    EXPECT_TRUE(v1 == v1);
}

TEST(TDynamicVector, vectors_with_different_size_are_not_equal)
{
    TDynamicVector<int> v1(10);
    TDynamicVector<int> v2(5);

    EXPECT_NE(v1, v2);
}

TEST(TDynamicVector, can_add_scalar_to_vector)
{
    TDynamicVector<int> v(10);
    TDynamicVector<int> res(10);
    for (size_t i = 0; i < 10; ++i)
        res[i] = 1;
    int sc = 1;
    v = v + sc;

    EXPECT_EQ(v, res);
}

TEST(TDynamicVector, can_subtract_scalar_from_vector)
{
    TDynamicVector<int> v(10);
    TDynamicVector<int> res(10);
    for (size_t i = 0; i < 10; ++i)
        res[i] = -1;
    int sc = 1;
    v = v - sc;

    EXPECT_EQ(v, res);
}

TEST(TDynamicVector, can_multiply_scalar_by_vector)
{
    TDynamicVector<int> v(10);
    for (size_t i = 0; i < 10; ++i)
        v[i] = 1;
    TDynamicVector<int> res(10);
    for (size_t i = 0; i < 10; ++i)
        res[i] = 10;
    int sc = 10;
    v = v * sc;

    EXPECT_EQ(v, res);
}

TEST(TDynamicVector, can_add_vectors_with_equal_size)
{
    TDynamicVector<int> v1(10);
    TDynamicVector<int> v2(10);
    for (size_t i = 0; i < 5; i++)
        v1[i] = 10;
    v2 = v2 + v1;

    EXPECT_EQ(v1, v2);
}

TEST(TDynamicVector, cant_add_vectors_with_not_equal_size)
{
    TDynamicVector<int> v1(5);
    TDynamicVector<int> v2(10);

    ASSERT_ANY_THROW(v1 + v2);
}

TEST(TDynamicVector, can_subtract_vectors_with_equal_size)
{
    int* arr = new int[5] {5, 5, 5, 5, 5};
    TDynamicVector<int> v1(arr, 5);
    TDynamicVector<int> v2(arr, 5);
    TDynamicVector<int> res(5);
    v2 = v2 - v1;

    EXPECT_EQ(v2, res);
}

TEST(TDynamicVector, cant_subtract_vectors_with_not_equal_size)
{
    TDynamicVector<int> v1(5);
    TDynamicVector<int> v2(10);

    ASSERT_ANY_THROW(v1 - v2);
}

TEST(TDynamicVector, can_multiply_vectors_with_equal_size)
{
    int* arr1 = new int[5] {2, 2, 2, 2, 2};
    int* arr2 = new int[5] {5, 5, 5, 5, 5};
    TDynamicVector<int> v1(arr1, 5);
    TDynamicVector<int> v2(arr2, 5);
    int res = v1 * v2;

    EXPECT_EQ(50, res);
}

TEST(TDynamicVector, cant_multiply_vectors_with_not_equal_size)
{
    TDynamicVector<int> v1(5);
    TDynamicVector<int> v2(10);

    ASSERT_ANY_THROW(v1 * v2);
}

