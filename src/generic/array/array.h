#ifndef ARRAY_H
#define ARRAY_H

#include <stdlib.h>

#define Array(T) T*

void* construct_array(size_t cap);

size_t get_array_length(Array(void) arr);

size_t get_array_capacity(Array(void) arr);

void free_array(Array(void) arr);

#define init_array(arr, cap) construct_array((cap) * sizeof(*(arr)) + (sizeof(size_t) * 2))

#endif