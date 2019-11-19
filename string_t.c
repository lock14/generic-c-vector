//
// Created by brian on 11/18/2019.
//
#include "string_t.h"

void init_string(string_t *string, char *cstring) {
    string->length = strlen(cstring);
    string->chars = (char *) malloc((string->length + 1) * sizeof(char));
    strcpy(string->chars, cstring);
}
