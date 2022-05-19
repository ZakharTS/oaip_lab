#include <iostream>
#include "list.h"

using namespace std;

int main() {
    listnode *list = nullptr;
    cout << "List size: ";
    int n;
    cin >> n;
    cout << "List\n";
    for (int i = 0; i < n; i++) {
        int temp;
        cin >> temp;
        list_push_front(list, temp);
    }
    list_display(list);
    cout << endl << "Value to double: ";
    int toDouble;
    cin >> toDouble;
    list_double(list, toDouble);
    list_display(list);
    return 0;
}
