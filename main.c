#include <stdbool.h>
#include "vector.h"
#include "string_t.h"

int main() {
    vector(int) *list = new_vector(int);
    print_vector(list);
    v_set(list, 1, 100);
    print_vector(list);
    v_push(list, 1);
    v_push(list, 2);
    v_push(list, 3);
    v_push(list, 4);
    v_push(list, 5);
    v_push(list, 6);
    v_push(list, 7);
    v_push(list, 8);
    v_push(list, 9);
    v_push(list, 10);
    v_push(list, 11);
    print_vector(list);
    printf("%d\n", v_is_empty(list));
    printf("%d\n", v_pop(list));
    print_vector(list);
    v_free(list);

    string_vector *sv = new_vector(string_t);
    sv_push(sv, "Hello");
    sv_push(sv, "my");
    sv_push(sv, "name");
    sv_push(sv, "is");
    sv_push(sv, "brian");
    printf("%ld\n", v_size(sv));
    sv_print(sv);
    free(sv_pop(sv));
    sv_print(sv);
    sv_free(sv);
    return 0;
}


