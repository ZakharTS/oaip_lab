#include <iostream>
#include "list.h"

using namespace std;

int main() {
    listnode *list = nullptr;
    cout << "List size: ";
    int s;
    cin >> s;
    cout << "List:\n";
    for (int i = 0; i < s; i++) {
        int val;
        cin >> val;
        list_push_back(list, val);
    }
    list_display(list);
    cout << endl;
    list_pop_back(list);
    list_display(list);
    cout << endl;
    cout << "Range to delete (n & k): ";
    int n, k;
    cin >> n >> k;
    list_delete_range(list, n, k);
    list_display(list);
    return 0;
}
