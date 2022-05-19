#include <iostream>
#include "list.h"

using namespace std;

int main() {

    cout << "Size of list: ";
    int n;
    cin >> n;
    cout << "List:\n";
    int val;
    cin >> val;
    listnode *list = list_create(val);
    for (int i = 1; i < n; i++) {
        int val;
        cin >> val;
        list_add(list, val);
    }
    listnode *revlist = list_copy(list);
    //listnode *revlist = list;
    revlist = list_reverse(revlist);
    list_display(revlist);
    return 0;
}
