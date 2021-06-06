#include <assert.h>
#include <generic/array/array.h>
#include <memory.h>

#define ARRAY_DATA_ST 2
#define ARRAY_LENGTH_P -1
#define ARRAY_CAP_P -2

#define set_array_capacity(source, size) source ? ((size_t*)(source))[ARRAY_CAP_P] = (size) : 0

#define set_array_length(source, size) source ? ((size_t*)(source))[ARRAY_LENGTH_P] = (size) : 0

void* initialize_array(size_t elem_size, size_t init_cap)
{
    if (!init_cap)
    {
        return NULL;
    }
    size_t cur_size = (init_cap * elem_size + (sizeof(size_t) * 2));
    size_t* tmp = malloc(cur_size);
    void* source = (void*)(&tmp[ARRAY_DATA_ST]);
    set_array_length((source), 0);
    set_array_capacity((source), (init_cap));
    return source;
}

size_t get_array_length(Array(void) arr)
{
    return ((arr) ? ((size_t*)(arr))[ARRAY_LENGTH_P] : (size_t)0);
}

size_t get_array_capacity(Array(void) arr)
{
    return ((arr) ? ((size_t*)(arr))[ARRAY_CAP_P] : (size_t)0);
}

void expand_array(void** blockptr, size_t cur_cap, size_t cap)
{
    size_t* tmp = realloc(&((size_t*)(*blockptr))[-2], cur_cap);
    (*blockptr) = (void*)(&tmp[2]);
    ((size_t*)(*blockptr))[-2] = cap;
}

void free_array(Array(void) arr)
{
    (arr) ? (free(&((size_t*)(arr))[ARRAY_CAP_P])) : 0;
}