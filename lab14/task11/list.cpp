#include "list.h"
#include <iostream>

listnode *list_create(int value) {
    listnode *current = new listnode;
    current->value = value;
    current->next = nullptr;
    current->prev = nullptr;
    return current;
}

void list_push_front(listnode *&list, int value) {
    if (list == nullptr) {
        list = list_create(value);
        return;
    }
    listnode *current = list_create(value);
    current->next = list;
    list->prev = current;
    list = current;
}

void list_display(listnode *list) {
    while (list != nullptr) {
        std::cout << list->value << std::endl;
        list = list->next;
    }
}

void list_insert(listnode *pos, int value) {
    listnode *cur = list_create(value);
    cur->next = pos->next;
    cur->prev = pos;
    pos->next->prev = cur;
    pos->next = cur;
}

void list_double(listnode *list, int toDouble) {
    while (list != nullptr) {
        if (list->value == toDouble) {
            list_insert(list, toDouble);
            list = list->next;
        }
        list = list->next;
    }
}