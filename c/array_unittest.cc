#include "array.h"
#include "array.c"
#include "gtest/gtest.h"

int capacity = 17;
CArray *array_ptr = carray_new(capacity);

TEST(CArrayTest, is_empty)
{
    EXPECT_EQ(true, carray_is_empty(array_ptr));
}

TEST(CArrayTest, initial_capacity)
{
    EXPECT_EQ(carray_increase_capacity(capacity), carray_capacity(array_ptr));
}

TEST(CArrayTest, initial_size)
{
    EXPECT_EQ(0, carray_size(array_ptr));
}

TEST(CArrayTest, push_values)
{
    for (int i = 0; i < capacity; i++)
    {
	carray_push(array_ptr, i);
    }

    EXPECT_EQ(5, carray_get(array_ptr, 5));
}

TEST(CArrayTest, insert_values)
{
    carray_insert(array_ptr, 5, 99999);
    carray_insert(array_ptr, 10, 999999);
    EXPECT_EQ(99999, carray_get(array_ptr, 5));
    EXPECT_EQ(5, carray_get(array_ptr, 6));
    EXPECT_EQ(999999, carray_get(array_ptr, 10));
}

TEST(CArrayTest, prepend_values)
{
    carray_prepend(array_ptr, 99999);
    EXPECT_EQ(99999, carray_get(array_ptr, 0));
}

TEST(CArrayTest, pop_values)
{
    int size = carray_size(array_ptr);
    int last = carray_get(array_ptr, carray_size(array_ptr) - 1);
    int second_last = carray_get(array_ptr, carray_size(array_ptr) - 2);
    EXPECT_EQ(last, carray_pop(array_ptr));
    EXPECT_EQ(second_last, carray_pop(array_ptr));
    EXPECT_EQ(size - 2, carray_size(array_ptr));
}