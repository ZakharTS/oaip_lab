#ifndef TASK5_LIST_H
#define TASK5_LIST_H

struct listnode {
    int value;
    listnode *next;
};

listnode *list_create(int value);

void list_add(listnode *list, int value);

void list_display(listnode *list);

listnode *list_copy(listnode *listsrc);

listnode *list_reverse(listnode *list);

#endif //TASK5_LIST_H
