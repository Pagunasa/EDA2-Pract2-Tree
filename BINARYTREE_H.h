/* 
 * File:   BINARYTREE_H.h
 * Author: U140172
 *
 * Created on 25 de mayo de 2017, 13:01
 */

#ifndef BINARYTREE_H_H
#define	BINARYTREE_H_H

typedef struct _BinaryTree {
    char info[MAXLENGTH];
    struct _BinaryTree *left;
    struct _BinaryTree *rigth;
} BinaryTree;

BinaryTree* create_empty_tree();
BinaryTree* create_tree(BinaryTree* left, char* content, BinaryTree* right); 
BinaryTree* left_tree(BinaryTree* tree); 
BinaryTree* right_tree(BinaryTree* tree); 
char* get_content(BinaryTree* tree); 
int is_empty(BinaryTree* tree);

void print_tree(BinaryTree* tree);

BinaryTree* create_example1();
BinaryTree* create_example2();

//BinaryTree* create_tree_from_string(char* strTree);
#endif	/* BINARYTREE_H_H */

