#include <ctest.h>
#include <generic/array/array.h>

CTEST(generic_array, initialize)
{
    Array(float) arr = init_array(float, 10);
    ASSERT_EQUAL(0, get_array_length(arr));
    ASSERT_EQUAL(10, get_array_capacity(arr));
    free_array(arr);

    Array(float) arr_empty = init_array(float, 0);
    ASSERT_EQUAL(0, get_array_length(arr_empty));
    ASSERT_EQUAL(0, get_array_capacity(arr_empty));
    free_array(arr_empty);
}

CTEST(generic_array, add)
{
    Array(double) arr = init_array(double, 8);
    for (size_t i = 0; i < 100; ++i)
    {
        add_array(arr, i);
        ASSERT_EQUAL(i + 1, get_array_length(arr));
    }
    for (size_t i = 0; i < 100; ++i)
    {
        ASSERT_EQUAL(i, arr[i]);
    }
    ASSERT_EQUAL(128, get_array_capacity(arr));
    free_array(arr);
    arr = NULL;
    add_array(arr, 0);
}

CTEST(generic_array, add_range)
{
    Array(int) arr = init_array(int, 4);
    int collection[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    add_range_array(arr, collection, sizeof(collection) / sizeof(int));
    for (size_t i = 0; i < sizeof(collection) / sizeof(int); ++i)
    {
        ASSERT_EQUAL(collection[i], arr[i]);
    }
    ASSERT_EQUAL(16, get_array_capacity(arr));
    free_array(arr);
}

CTEST(generic_array, search)
{
    Array(short) arr = init_array(short, 4);
    short collection[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    add_range_array(arr, collection, sizeof(collection) / sizeof(short));
    size_t result;
    for (size_t i = 0; i < sizeof(collection) / sizeof(short); ++i)
    {
        search_array(arr, i, result);
        ASSERT_EQUAL(i, result);
    }
    search_array(arr, 123, result);
    ASSERT_EQUAL(-1, result);
    free_array(arr);
}

CTEST(generic_array, clear)
{
    Array(double) arr = init_array(double, 8);
    for (size_t i = 0; i < 100; ++i)
    {
        add_array(arr, i);
        ASSERT_EQUAL(i + 1, get_array_length(arr));
    }
    ASSERT_EQUAL(128, get_array_capacity(arr));
    ASSERT_EQUAL(100, get_array_length(arr));
    clear_array(arr);
    ASSERT_EQUAL(128, get_array_capacity(arr));
    ASSERT_EQUAL(0, get_array_length(arr));
    free_array(arr);
}