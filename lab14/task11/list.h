#ifndef TASK11_LIST_H
#define TASK11_LIST_H

struct listnode {
    int value;
    listnode *next, *prev;
};

listnode *list_create(int value);

void list_push_front(listnode *&list, int value);

void list_display(listnode *list);

void list_insert(listnode *pos, int value);

void list_double(listnode *list, int toDouble);

#endif //TASK11_LIST_H
