#ifndef TASK5_BALTREE_H
#define TASK5_BALTREE_H

struct treenode {
    int value;
    treenode *left;
    treenode *right;
    int leftChildren;
    int rightChildren;
};

treenode *tree_create(int value);

void tree_add(treenode *tree, int value);

int tree_count_leaves(treenode *tree);

int tree_dfs(treenode *tree);

#endif
