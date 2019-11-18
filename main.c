#include <stdbool.h>
#include "vector.h"
#include "string_t.h"

int main() {
    vector(int) *list = new_vector(int, 1, 2, 3);
    print_vector(list);
    v_set(list, 1, 100);
    print_vector(list);
    v_push(list, 4, 5, 6, 7, 8, 9, 10, 11);
    print_vector(list);
    printf("%d\n", v_is_empty(list));
    printf("%d\n", v_pop(list));
    print_vector(list);
    v_free(list);

    string_vector *sv = new_vector(string_t);
    sv_push_all(sv, 5, "Hello", "my", "name", "is", "brian");
    printf("%ld\n", sv->size);
    sv_print(sv);
    sv_free(sv);
    return 0;
}


