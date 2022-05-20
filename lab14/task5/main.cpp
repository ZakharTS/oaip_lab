#include <iostream>
#include "list.h"
#include "baltree.h"

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
    revlist = list_reverse(revlist);
    list_display(revlist);

    cout << "Size of tree: ";
    cin >> n;
    cout << "Tree:\n";
    cin >> val;
    treenode *tree = tree_create(val);
    for (int i = 1; i < n; i++) {
        int val;
        cin >> val;
        tree_add(tree, val);
    }
    cout << "Number of leaves: " << tree_count_leaves(tree);
    return 0;
}
