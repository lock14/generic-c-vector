//
// Created by brian on 11/18/2019.
//
#include "string_vector.h"

string_vector* new_string_vector() {
    string_vector *vector = new_vector(string_t);
    for (size_t i = 0; i < vector->capacity; ++i) {
        (&vector->data[i])->chars = NULL;
    }
    return vector;
}

void sv_free(string_vector *vector) {
    for (size_t i = 0; i < vector->capacity; i++) {
        free((&vector->data[i])->chars);
    }
    v_free(vector);
}

void sv_add(string_vector *vector, size_t idx, char *cstring) {
    string_t string;
    init_string(&string, cstring);
    size_t old_capacity = vector->capacity;
    v_add(vector, idx, string);
    if (vector->capacity != old_capacity) {
        for (size_t i = old_capacity + 1; i < vector->capacity; ++i) {
            (&vector->data[i])->chars = NULL;
        }
    }
}

char* sv_get(string_vector *vector, size_t i) {
    return v_get(vector, i)->chars;
}

string_t* sv_get_val(string_vector *vector, size_t i) {
    return v_get(vector, i);
}

bool sv_is_empty(string_vector *vector) {
    return v_is_empty(vector);
}

// user must take responsibility for freeing the
// returned pointer
char* sv_pop(string_vector *vector) {
    return sv_remove_at(vector, v_size(vector) - 1);
}

void sv_push(string_vector *vector, char* cstring) {
    sv_add(vector, v_size(vector), cstring);
}

// user must take responsibility for freeing the
// returned pointer
char* sv_remove_at(string_vector *vector, size_t idx) {
    assert(v_valid_index(vector, idx));
    char* ret = v_get(vector, idx)->chars;
    v_remove_at(vector, idx);
    (&vector->data[vector->size])->chars = NULL;
    return ret;
}

void sv_set(string_vector *vector, size_t i, char* cstring) {
    string_t *string = v_get(vector, i);
    free(string->chars);
    init_string(string, cstring);
}

size_t sv_size(string_vector *vector) {
    return v_size(vector);
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
