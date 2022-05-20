#ifndef TASK_DATABASE_H
#define TASK_DATABASE_H

#include <iostream>
#include <string.h>

using namespace std;

struct students {
    char surname[256];
    char name[256];
    char patronymic[256];
    enum groups {
        po8, po9, ii21, ii22, unknown
    } grp;
    double avrMark;
    int income;
    short bit: 4;
    union {
        int integer;
        double real;
    };
};

void display_record(students);

void add_record(students *&, size_t &, const char *);

void add_to_array(students *&, size_t &, students);

void list(students *, size_t);

void sort_by(students *, size_t);

void delete_by(students *&, size_t &);

void delete_by_id(students *&, size_t &, size_t);

void list_by_income(students *, size_t, int);

#endif
