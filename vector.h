//
// Created by brian on 11/17/2019.
//

#ifndef C_TEST_VECTOR_H
#define C_TEST_VECTOR_H

#include <assert.h>
#include <stdlib.h>
#include <stdio.h>
#include "string_t.h"

#define LIST_LEN(a) (sizeof(a) / sizeof(*a))

#define vector(T) vector_##T

#define vector_base      \
    struct {             \
        size_t capacity; \
        size_t size;     \
    }

#define typedef_vector(T)      \
    typedef struct vector(T) { \
        vector_base;           \
        T data[];              \
    } vector(T)

#define new_vector(T)                                                      \
({                                                                         \
    size_t initial_size = 10;                                              \
    vector(T) *v = malloc(sizeof(vector_base) + sizeof(T) * initial_size); \
    v->capacity = initial_size;                                            \
    v->size = 0;                                                           \
    memset(v->data, 0, v->capacity * sizeof(T));                           \
    v;                                                                     \
})

#define v_free(v) free(v)

#define v_add(v, idx, e)                                 \
({                                                       \
   if (size_t(idx) != v->size) {                         \
       assert(v_valid_index(v, idx));                    \
   }                                                     \
   if (v->size == v->capacity) {                         \
       v_resize(v, (v->capacity + (v->capacity >> 1u))); \
   }                                                     \
   for (size_t i = v->size; i > idx; --i) {              \
       v->data[i] = v->data[i - 1];                      \
   }                                                     \
   v->data[idx] = e;                                     \
   ++v->size;                                            \
})

#define v_get(v, i)              \
({                               \
    assert(v_valid_index(v, i)); \
    &v->data[(size_t) i];        \
})

#define v_get_val(v, i) (*v_get(v, i))

#define v_is_empty(v) (v_size(v) == 0)

#define v_pop(v) (v->data[--v->size])

#define v_push(v, e) v_add(v, v_size(v), e)

#define v_remove_at(v, idx)                            \
({                                                     \
    assert(v_valid_index(v, idx));                     \
    if (v_size(v) > 1) {                               \
        for (size_t i = idx; i < v_size(v) - 1; ++i) { \
            v->data[i] = v->data[i + 1];               \
        }                                              \
    }                                                  \
    --v->size;                                         \
})

#define v_resize(v, new_capacity)                                             \
({                                                                            \
    assert(size_t(new_capacity) > v->capacity);                               \
    v->capacity = new_capacity;                                               \
    v = realloc(v, sizeof(vector_base) + v->capacity * sizeof(*v->data));     \
    memset(v->data + v->size, 0, (v->capacity - v->size) * sizeof(*v->data)); \
})

#define v_set(v, i, va) v_get_val(v, i) = va

#define v_size(v) v->size

#define v_valid_index(v, i) (size_t(i) < v->size)

#define size_t(i) ((size_t) i)

#define GET_FMT_SPEC(x) _Generic((x), int: "%d", float: "%f", char*: "%s", char: "%c")

#define print_vector(v)                               \
({                                                    \
    printf("[");                                      \
    for (size_t i = 0; i < v->size; ++i) {            \
        printf(GET_FMT_SPEC(v->data[i]), v->data[i]); \
        if (i + 1 < v->size)                          \
            printf(", ");                             \
    }                                                 \
    printf("]\n");                                    \
})

// typedef vector for common types

typedef_vector(char);
typedef_vector(short);
typedef_vector(int);
typedef_vector(long);
typedef_vector(float);
typedef_vector(double);


#endif //C_TEST_VECTOR_H
