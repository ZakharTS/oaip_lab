#ifndef TASK_INDEX_H
#define TASK_INDEX_H
#include "database.h"
void read_index_file(const char *, int *, int *, size_t);

void rewrite_index_file(const char *, int *, int *, size_t);

void add_to_index(size_t, students);

static char currentIndexFileName[32];
#endif
