#include "baltree.h"

treenode *tree_create(int value) {
    auto *node = new treenode;
    node->left = nullptr;
    node->right = nullptr;
    node->value = value;
    node->leftChildren = 0;
    node->rightChildren = 0;
    return node;
}

void tree_add(treenode *tree, int value) {
    while (tree->left != nullptr && tree->right != nullptr) {
        if (tree->leftChildren <= tree->rightChildren) {
            tree->leftChildren++;
            tree = tree->left;
        } else {
            tree->rightChildren++;
            tree = tree->right;
        }
    }
    if (tree->left == nullptr) {
        tree->left = tree_create(value);
        tree->leftChildren++;
    } else {
        tree->right = tree_create(value);
        tree->rightChildren++;
    }
}

int tree_count_leaves(treenode *tree) {
    return tree_dfs(tree);
}

int tree_dfs(treenode *tree) {
    int leaves = 0;
    if (tree->left != nullptr) {
        leaves += tree_dfs(tree->left);
    }
    if (tree->right != nullptr) {
        leaves += tree_dfs(tree->right);
    }
    if (tree->left == nullptr && tree->right == nullptr) return 1;
    return leaves;
}