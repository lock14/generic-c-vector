#include <stdlib.h>
#include <string.h>

#ifndef STRING_T
#define STRING_T

typedef struct string_t {
    size_t length;
    char *chars;
} string_t;

void init_string(string_t *string, char *cstring);

#endif