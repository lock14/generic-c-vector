//
// Created by brian on 11/18/2019.
//

#ifndef C_TEST_STRING_T_H
#define C_TEST_STRING_T_H

#include <stdlib.h>
#include <string.h>

typedef struct string_t {
    size_t length;
    char *chars;
} string_t;

void init_string(string_t *string, char *cstring);

#endif //C_TEST_STRING_T_H
