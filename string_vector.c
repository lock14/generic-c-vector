//
// Created by brian on 11/18/2019.
//
#include "string_vector.h"

string_vector* new_string_vector() {
    string_vector *sv = new_vector(string_t);
    for (size_t i = 0; i < sv->capacity; ++i) {
        v_get(sv, i)->chars = NULL;
    }
    return sv;
}

void sv_free(string_vector *vector) {
    for (size_t i = 0; i < vector->capacity; i++) {
        free((&vector->data[i])->chars);
    }
    v_free(vector);
}

void sv_add(string_vector *vector, char* cstring) {

}
void sv_add_at(string_vector *vector, size_t idx, char* cstring) {
    string_t string;
    init_string(&string, cstring);
    v_add(vector, idx, string);
}

void sv_set(string_vector *vector, size_t i, char* cstring) {
    string_t *string = v_get(vector, i);
    free(string->chars);
    init_string(string, cstring);
}

// user must take responsibility for freeing the
// returned pointer
char* sv_pop(string_vector *vector) {
    return sv_remove_at(vector, v_size(vector) - 1);
}

void sv_push(string_vector *vector, char* cstring) {
    sv_add_at(vector, v_size(vector), cstring);
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
