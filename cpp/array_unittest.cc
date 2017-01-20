#include "array.h"
#include "array.cc"
#include "gtest/gtest.h"

int capacity = 17;
cpp::CPPArray *arr = new cpp::CPPArray(capacity);

TEST(CArrayTest, is_empty)
{
    EXPECT_EQ(true, arr->is_empty());
}

TEST(CArrayTest, initial_capacity)
{
    EXPECT_EQ(2 * capacity, arr->get_capacity());
}

TEST(CArrayTest, initial_size)
{
    EXPECT_EQ(0, arr->get_size());
}

TEST(CArrayTest, push_values)
{
    for (int i = 0; i < capacity; i++)
    {
        arr->push(i);
    }

    EXPECT_EQ(5, arr->get(5));
}

TEST(CArrayTest, insert_values)
{
    arr->insert(5, 99999);
    arr->insert(10, 999999);
    EXPECT_EQ(99999, arr->get(5));
    EXPECT_EQ(5, arr->get(6));
    EXPECT_EQ(999999, arr->get(10));
}

TEST(CArrayTest, prepend_values)
{
    arr->prepend(99999);
    EXPECT_EQ(99999, arr->get(0));
}

TEST(CArrayTest, pop_values)
{
    int size = arr->get_size();
    int last = arr->get(size - 1);
    int second_last = arr->get(size - 2);
    EXPECT_EQ(last, arr->pop());
    EXPECT_EQ(second_last, arr->pop());
    EXPECT_EQ(size - 2, arr->get_size());
}

TEST(CArrayTest, delete_values)
{
    int size = arr->get_size();
    int first = arr->get(0);
    int middle = arr->get(size / 2);
    int last = arr->get(size - 1);
    arr->deleteAt(0);
    arr->deleteAt(arr->get_size() / 2);
    arr->deleteAt(arr->get_size() - 1);

    ASSERT_NE(first, arr->get(0));
    ASSERT_NE(middle, arr->get(size / 2));
    ASSERT_NE(last, arr->get(size - 1));
}

TEST(CArrayTest, remove_values)
{
    int size = arr->get_size();
    int first = arr->get(0);
    int middle = arr->get(size / 2);
    int last = arr->get(size - 1);
    arr->remove(first);
    arr->remove(middle);
    arr->remove(last);
    ASSERT_EQ(-1, arr->find(first));
    ASSERT_EQ(-1, arr->find(middle));
    ASSERT_EQ(-1, arr->find(last));
}

TEST(CArrayTest, find_values)
{
    int size = arr->get_size();
    int first = arr->get(0);
    int middle = arr->get(size / 2);
    int last = arr->get(size - 1);
    ASSERT_LE(0, arr->find(first));
    ASSERT_LE(size / 2, arr->find(middle));
    ASSERT_LE(size - 1, arr->find(last));
}