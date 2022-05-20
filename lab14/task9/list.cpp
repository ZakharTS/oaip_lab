#include "list.h"
#include <iostream>

listnode *list_create(int value) {
    listnode *current = new listnode;
    current->value = value;
    current->next = current;
    return current;
}

void list_push_back(listnode *&list, int value) {
    if (list == nullptr) {
        list = list_create(value);
        return;
    }
    listnode *head = list;
    while (list->next != head) {
        list = list->next;
    }
    listnode *cur = new listnode;
    list->next = cur;
    cur->value = value;
    cur->next = head;
    list = head;
}

void list_display(listnode *list) {
    if (list == nullptr) return;
    listnode *head = list;
    do {
        std::cout << list->value << std::endl;
        list = list->next;
    } while (list != head);
}

void list_pop_back(listnode *&list) {
    listnode *head = list;
    if (list->next == head) {
        delete list;
        list = nullptr;
        return;
    }
    if (list == nullptr) return;
    while (list->next->next != head) {
        list = list->next;
    }
    delete list->next;
    list->next = head;
    list = head;
}

void list_delete_range(listnode *&list, int n, int k) {
    if (list == nullptr) return;
    if (k <= n) return;
    listnode *head = list, *temp;
    int count = 0;
    do {
        if (count == n) {
            temp = list;
            list = list->next;
            temp->next = head;
            count++;
            continue;
        }
        if (count == k) {
            temp->next = list;
            break;
        }
        if (count > n) {
            listnode *todel = list;
            list = list->next;
            count++;
            delete todel;
            continue;
        }
        count++;
        list = list->next;
    } while (list != head);
    list = head;
}