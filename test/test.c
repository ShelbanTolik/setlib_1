#include "../include/set.h"
#include <stdio.h>

int main() {
    Set *a = set_create(10);
    Set *b = set_create(10);

    set_add(a, 1);
    set_add(a, 2);
    set_add(b, 2);
    set_add(b, 3);

    printf("Set A: ");
    set_print(a);
    printf("Set B: ");
    set_print(b);

    Set *u = set_union(a, b);
    printf("A ∪ B: ");
    set_print(u);

    Set *i = set_intersection(a, b);
    printf("A ∩ B: ");
    set_print(i);

    Set *d = set_difference(a, b);
    printf("A - B: ");
    set_print(d);

    Set *s = set_symmetric_difference(a, b);
    printf("A △ B: ");
    set_print(s);

    Set *c = set_complement(a);
    printf("~A: ");
    set_print(c);

    set_free(a);
    set_free(b);
    set_free(u);
    set_free(i);
    set_free(d);
    set_free(s);
    set_free(c);

    return 0;
}
