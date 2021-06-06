#ifndef ARRAY_H
#define ARRAY_H

#include <stdbool.h>
#include <stdlib.h>

#define Array(T) T*

void* initialize_array(size_t elem_size, size_t init_cap);

size_t get_array_length(Array(void) arr);

size_t get_array_capacity(Array(void) arr);

void expand_array(void** blockptr, size_t cur_cap, size_t cap);

void free_array(Array(void) arr);

static inline bool is_array_full(Array(void) arr)
{
    return get_array_length(arr) >= get_array_capacity(arr);
}

#define init_array(type, cap) (initialize_array(sizeof(type), cap))

#define try_to_expand(source, cur_cap)                                                                                 \
    expand_array(((void**)&source), (cur_cap * 2) * sizeof(*(source)) + (sizeof(size_t) * 2), cur_cap * 2)

#define add_array_item(source, item)                                                                                   \
    source[get_array_length(source)] = (item);                                                                         \
    ++((size_t*)(source))[-1]

#define add_array(source, item)                                                                                        \
    {                                                                                                                  \
        if (is_array_full(source))                                                                                     \
        {                                                                                                              \
            try_to_expand(source, get_array_capacity(source));                                                         \
        }                                                                                                              \
        add_array_item(source, item);                                                                                  \
    }

#endif