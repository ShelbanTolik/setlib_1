#include "set.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BYTE_INDEX(i) ((i) / 8)
#define BIT_MASK(i) (1 << ((i) % 8))

Set *set_create(size_t size) {
    Set *set = malloc(sizeof(Set));
    set->size = size;
    size_t byte_size = (size + 7) / 8;
    set->data = calloc(byte_size, 1);
    return set;
}

void set_free(Set *set) {
    if (set) {
        free(set->data);
        free(set);
    }
}

void set_add(Set *set, size_t element) {
    if (element < set->size)
        set->data[BYTE_INDEX(element)] |= BIT_MASK(element);
}

void set_remove(Set *set, size_t element) {
    if (element < set->size)
        set->data[BYTE_INDEX(element)] &= ~BIT_MASK(element);
}

bool set_contains(const Set *set, size_t element) {
    return (element < set->size) &&
           (set->data[BYTE_INDEX(element)] & BIT_MASK(element));
}

bool set_is_subset(const Set *a, const Set *b) {
    for (size_t i = 0; i < (a->size + 7) / 8; ++i) {
        if ((a->data[i] & ~b->data[i]) != 0)
            return false;
    }
    return true;
}

bool set_is_strict_subset(const Set *a, const Set *b) {
    return set_is_subset(a, b) && !set_is_subset(b, a);
}

Set *set_union(const Set *a, const Set *b) {
    Set *result = set_create(a->size);
    for (size_t i = 0; i < (a->size + 7) / 8; ++i)
        result->data[i] = a->data[i] | b->data[i];
    return result;
}

Set *set_intersection(const Set *a, const Set *b) {
    Set *result = set_create(a->size);
    for (size_t i = 0; i < (a->size + 7) / 8; ++i)
        result->data[i] = a->data[i] & b->data[i];
    return result;
}

Set *set_difference(const Set *a, const Set *b) {
    Set *result = set_create(a->size);
    for (size_t i = 0; i < (a->size + 7) / 8; ++i)
        result->data[i] = a->data[i] & ~b->data[i];
    return result;
}

Set *set_symmetric_difference(const Set *a, const Set *b) {
    Set *result = set_create(a->size);
    for (size_t i = 0; i < (a->size + 7) / 8; ++i)
        result->data[i] = a->data[i] ^ b->data[i];
    return result;
}

Set *set_complement(const Set *set) {
    Set *result = set_create(set->size);
    for (size_t i = 0; i < (set->size + 7) / 8; ++i)
        result->data[i] = ~set->data[i];
    result->data[(set->size + 7) / 8 - 1] &= (1 << (set->size % 8)) - 1;
    return result;
}

void set_print(const Set *set) {
    printf("{ ");
    for (size_t i = 0; i < set->size; ++i) {
        if (set_contains(set, i))
            printf("%zu ", i);
    }
    printf("}\n");
}
