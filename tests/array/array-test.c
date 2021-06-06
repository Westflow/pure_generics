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
