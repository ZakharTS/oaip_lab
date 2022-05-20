#include "index.h"
#include <string.h>

void read_index_file(const char *filename, int *ind, int *values, size_t n) {
    FILE *f;
    if ((f = fopen(filename, "r")) == NULL) {
        cout << "Failed to open index file.\n";
        return;
    }
    for (size_t i = 0; i < n; i++) {
        fscanf(f, "%d %d", ind+i, values+i);
    }
    fclose(f);
}

void rewrite_index_file(const char *filename, int *ind, int *values, size_t n) {
    FILE *f;
    if ((f = fopen(filename, "w")) == NULL) {
        cout << "Failed to open index file.\n";
        return;
    }
    for (int i = 0; i < n; i++) {
        fprintf(f, "%d %d\n", ind[i], values[i]);
    }
    fclose(f);
}

void add_to_index(size_t id, students cur) {
    FILE *f;
    f = fopen("group_index.txt", "a");
    fprintf(f, "%d %d\n", id, cur.grp);
    fclose(f);
    f = fopen("income_index.txt", "a");
    fprintf(f, "%d %d\n", id, cur.income);
    fclose(f);
}