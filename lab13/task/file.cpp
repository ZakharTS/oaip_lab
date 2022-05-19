#include "file.h"

void import_file(const char *filename, students *&studs, size_t &n) {
    FILE *f;
    if ((f = fopen(filename, "rb")) == NULL) {
        f = fopen(filename, "wb");
        fclose(f);
        return;
    }
    for (;;) {
        struct students input;
        if (fread(&input, sizeof(students), 1, f) != 1) break;
        add_to_array(studs, n, input);
    }
    fclose(f);
}

void rewrite_file(const char *filename, students *studs, size_t n) {
    FILE *f = fopen(filename, "wb");
    for (size_t i = 0; i < n; i++) {
        fwrite(&studs[i], sizeof(students), 1, f);
    }
    fclose(f);
}