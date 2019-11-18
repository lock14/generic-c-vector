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

#define new_vector(T, items...)                                               \
({                                                                            \
    const T _items[] = {items};                                               \
    size_t initial_size = 10;                                                 \
    const size_t num_items = LIST_LEN(_items);                                \
    if (initial_size < num_items) {                                           \
        initial_size = num_items;                                             \
    }                                                                         \
    vector(T) *v = malloc(sizeof(vector(T)) + sizeof(T) * initial_size);      \
    v->capacity = initial_size;                                               \
    v->size = num_items;                                                      \
    memset(v->data, 0, v->capacity * sizeof(T));                              \
                                                                              \
    for (size_t i = 0; i < v->size; ++i) {                                    \
        v->data[i] = _items[i];                                               \
    }                                                                         \
    v;                                                                        \
})

#define v_free(v) free(v)

#define v_get(v, i)     \
({                               \
    assert(v_valid_index(v, (size_t) i)); \
    &v->data[(size_t) i];                 \
})

#define v_get_val(v, i) (*v_get(v, i))

#define v_is_empty(v) (v->size == 0)

#define v_pop(v) (v->data[--v->size])

#define v_push(v, items...)                          \
({                                                   \
    const typeof(*v->data) _items[] = {items};       \
    if (v->size + LIST_LEN(_items) >= v->capacity) { \
        v_resize(v, v->size + LIST_LEN(_items));     \
    }                                                \
    for (size_t i = 0; i < LIST_LEN(_items); ++i) {     \
        v->data[v->size++] = _items[i];              \
    }                                                \
    v;                                               \
})

#define v_resize(v, new_capacity)                                         \
({                                                                        \
    while (v->capacity <= new_capacity) {                                 \
        v->capacity = (v->capacity + (v->capacity >> 1));                 \
    }                                                                     \
    v = realloc(v, sizeof(vector_base) + v->capacity * sizeof(*v->data)); \
})

#define v_set(v, i, va) v_get_val(v, i) = va

#define v_size(v) v->size

#define v_valid_index(v, i) (i < v->size)

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

typedef_vector(char);
typedef_vector(int);
typedef_vector(float);
typedef_vector(double);
typedef_vector(string_t);
typedef vector(string_t) string_vector;

void sv_free(string_vector *vector);
char* sv_get(string_vector *vector, int i);
void sv_set(string_vector *vector, int i, char* cstring);
char* sv_pop(string_vector *vector);
void sv_push_all(string_vector *vector, size_t len, ...);
void sv_push(string_vector *vector, char* cstring);
void sv_print(string_vector *vector);


