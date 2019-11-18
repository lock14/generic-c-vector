#include <stdarg.h>
#include "vector.h"

void sv_free(string_vector *vector) {
    for (size_t i = 0; i < vector->capacity; i++) {
        free((&vector->data[i])->chars);
    }
    v_free(vector);
}

char* sv_get(string_vector *vector, size_t i) {
    return v_get(vector, i)->chars;
}

void sv_set(string_vector *vector, size_t i, char* cstring) {
    string_t *string = v_get(vector, i);
    free(string->chars);
    init_string(string, cstring);
}

// user must take responsibility for freeing the
// returned pointer
char* sv_pop(string_vector *vector) {
    return sv_remove(vector, v_size(vector) - 1);
}

void sv_push_all(string_vector *vector, size_t len, ...) {
    va_list args;
    va_start(args, len);
    for (size_t i = 0; i < len; i++) {
        sv_push(vector, va_arg(args, char*));
    }
    va_end(args);
}

void sv_push(string_vector *vector, char* cstring) {
    string_t string;
    init_string(&string, cstring);
    v_push(vector, string);
}

// user must take responsibility for freeing the
// returned pointer
char* sv_remove(string_vector *vector, size_t i) {
    assert(v_valid_index(vector, i));
    char* ret = v_get(vector, i)->chars;
    v_remove(vector, i);
    (&vector->data[vector->size])->chars = NULL;
    return ret;
}

void sv_print(string_vector *vector) {
    printf("[");
    if (v_size(vector) > 0) {
        printf("%s", v_get(vector, 0)->chars);
    }
    for (size_t i = 1; i < v_size(vector); i++) {
        printf(", %s", v_get(vector, i)->chars);
    }
    printf("]\n");
}