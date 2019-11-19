//
// Created by brian on 11/18/2019.
//

#ifndef C_TEST_STRING_VECTOR_H
#define C_TEST_STRING_VECTOR_H

#include <stdbool.h>
#include "vector.h"
#include "string_t.h"

typedef_vector(string_t);
typedef vector(string_t) string_vector;

string_vector* new_string_vector();
void sv_free(string_vector *vector);
void sv_add(string_vector *vector, size_t idx, char *cstring);
char* sv_get(string_vector *vector, size_t i);
string_t* sv_get_val(string_vector *vector, size_t i);
bool sv_is_empty();
char* sv_pop(string_vector *vector);
void sv_push(string_vector *vector, char* cstring);
char* sv_remove_at(string_vector * vector, size_t idx);
void sv_set(string_vector *vector, size_t i, char* cstring);
size_t sv_size(string_vector *vector);
void sv_print(string_vector *vector);

#endif //C_TEST_STRING_VECTOR_H
