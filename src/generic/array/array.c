#include <assert.h>
#include <generic/array/array.h>

#define ARRAY_DATA_ST 2
#define ARRAY_LENGTH_P -1
#define ARRAY_CAP_P -2

static void set_array_cap(Array(void) src, size_t cap)
{
    src ? ((size_t*)(src))[ARRAY_CAP_P] = (cap) : 0;
}

static void set_array_len(Array(void) src, size_t len)
{
    src ? ((size_t*)(src))[ARRAY_LENGTH_P] = (len) : 0;
}

size_t get_array_length(Array(void) arr)
{
    return ((arr) ? ((size_t*)(arr))[ARRAY_LENGTH_P] : (size_t)0);
}

size_t get_array_capacity(Array(void) arr)
{
    return ((arr) ? ((size_t*)(arr))[ARRAY_CAP_P] : (size_t)0);
}

void* construct_array(size_t cap)
{
    size_t* memblock = malloc(cap);
    assert(memblock);
    void* array = (void*)(&memblock[ARRAY_DATA_ST]);
    set_array_len(array, 0);
    set_array_cap(array, cap);
    return array;
}

void free_array(Array(void) arr)
{
    (arr) ? (free(&((size_t*)(arr))[ARRAY_CAP_P])) : 0;
}