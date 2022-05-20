#ifndef TASK9_LIST_H
#define TASK9_LIST_H

struct listnode {
    int value;
    listnode *next;
};

listnode *list_create(int value);

void list_push_back(listnode *&list, int value);

void list_display(listnode *list);

void list_pop_back(listnode *&list);

void list_delete_range(listnode *&list, int n, int k);

#endif //TASK9_LIST_H
