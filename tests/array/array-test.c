#include <ctest.h>
#include <generic/array/array.h>

CTEST(generic_array, initialize)
{
    Array(float) arr = init_array(arr, 10);
    ASSERT_EQUAL(0, get_array_length(arr));
    ASSERT_EQUAL(10 * sizeof(float) + sizeof(size_t) * 2, get_array_capacity(arr));
    free_array(arr);
}
