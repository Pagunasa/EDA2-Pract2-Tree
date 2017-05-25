/* 
 * File:   binaryTree.c
 * Author: U140172
 *
 * Created on 25 de mayo de 2017, 13:05
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "BINARYTREE_H.h"

/*
 * 
 */

BinaryTree* create_empty_tree() {
    
    BinaryTree *tree;
    tree = (BinaryTree*) malloc(sizeof (BinaryTree));
    
    strlcpy(tree->info, STRINGDEFAULT, MAXLENGTH);

    tree->left = NULL;
    tree->rigth = NULL;
    
    return tree;
}

BinaryTree* create_tree(BinaryTree* left, char* content, BinaryTree * right) {
    
    BinaryTree *tree_root;
    tree_root = create_empty_tree();
    
    strlcpy(tree_root->info, STRINGDEFAULT, content);

    tree_root->left = left;
    tree_root->rigth = right;
    
    return tree_root;
}

BinaryTree* left_tree(BinaryTree * tree) {
    return tree->left;
}

BinaryTree* right_tree(BinaryTree * tree) {
    return tree->rigth;
}

char* get_content(BinaryTree * tree) {
    return tree->info;
}

int is_empty(BinaryTree * tree) {
    if (tree->info == STRINGDEFAULT) {
        return TRUE;
    } else {
        return FALSE;
    }
}

void print_tree(BinaryTree * tree) {
    if (is_empty(tree)) {
        return;
    } else { 
        printf("%s", tree->info);
        printf("Yes \n");
        print_tree(left_tree(tree));
        printf("No \n");
        print_tree(right_tree(tree));
    }
}

BinaryTree* create_example1() {

}

BinaryTree* create_example2() {

}