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
    int last = carray_get(array_ptr, size - 1);
    int second_last = carray_get(array_ptr, size - 2);
    EXPECT_EQ(last, carray_pop(array_ptr));
    EXPECT_EQ(second_last, carray_pop(array_ptr));
    EXPECT_EQ(size - 2, carray_size(array_ptr));
}

TEST(CArrayTest, delete_values)
{
    int size = carray_size(array_ptr);
    int first = carray_get(array_ptr, 0);
    int middle = carray_get(array_ptr, size / 2);
    int last = carray_get(array_ptr, size - 1);
    carray_delete(array_ptr, 0);
    carray_delete(array_ptr, carray_size(array_ptr) / 2);
    carray_delete(array_ptr, carray_size(array_ptr) - 1);

    ASSERT_NE(first, carray_get(array_ptr, 0));
    ASSERT_NE(middle, carray_get(array_ptr, size / 2));
    ASSERT_NE(last, carray_get(array_ptr, size - 1));
}

TEST(CArrayTest, remove_values)
{
    int size = carray_size(array_ptr);
    int first = carray_get(array_ptr, 0);
    int middle = carray_get(array_ptr, size / 2);
    int last = carray_get(array_ptr, size - 1);
    carray_remove(array_ptr, first);
    carray_remove(array_ptr, middle);
    carray_remove(array_ptr, last);
    ASSERT_EQ(-1, carray_find(array_ptr, first));
    ASSERT_EQ(-1, carray_find(array_ptr, middle));
    ASSERT_EQ(-1, carray_find(array_ptr, last));
}

TEST(CArrayTest, find_values)
{
    int size = carray_size(array_ptr);
    int first = carray_get(array_ptr, 0);
    int middle = carray_get(array_ptr, size / 2);
    int last = carray_get(array_ptr, size - 1);
    ASSERT_LE(0, carray_find(array_ptr, first));
    ASSERT_LE(size / 2, carray_find(array_ptr, middle));
    ASSERT_LE(size - 1, carray_find(array_ptr, last));
}