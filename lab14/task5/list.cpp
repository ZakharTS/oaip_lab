#include "list.h"
#include <iostream>

listnode *list_create(int value) {
    listnode *current = new listnode;
    current->value = value;
    current->next = nullptr;
    return current;
}

void list_add(listnode *list, int value) {
    while (list->next != nullptr) {
        list = list->next;
    }
    listnode *cur = new listnode;
    list->next = cur;
    cur->value = value;
    cur->next = nullptr;
}

void list_display(listnode *list) {
    while (list != nullptr) {
        std::cout << list->value << std::endl;
        list = list->next;
    }
}

listnode *list_copy(listnode *listsrc) {
    listnode *listdst = list_create(listsrc->value);
    listsrc = listsrc->next;
    while (listsrc != nullptr) {
        list_add(listdst, listsrc->value);
        listsrc = listsrc->next;
    }
    return listdst;
}

listnode *list_reverse(listnode *list) {
    listnode *temp = nullptr;
    while (list->next != nullptr) {
        listnode *next = list->next;
        list->next = temp;
        temp = list;
        list = next;
    }
    list->next = temp;
    return list;
}