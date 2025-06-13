#ifndef SET_H
#define SET_H

#include <stdbool.h>
#include <stddef.h>

typedef struct {
    size_t size;
    unsigned char *data;
} Set;

Set *set_create(size_t size);
void set_free(Set *set);

void set_add(Set *set, size_t element);
void set_remove(Set *set, size_t element);
bool set_contains(const Set *set, size_t element);

bool set_is_subset(const Set *a, const Set *b);
bool set_is_strict_subset(const Set *a, const Set *b);
Set *set_union(const Set *a, const Set *b);
Set *set_intersection(const Set *a, const Set *b);
Set *set_difference(const Set *a, const Set *b);
Set *set_symmetric_difference(const Set *a, const Set *b);
Set *set_complement(const Set *set);

void set_print(const Set *set);

#endif
