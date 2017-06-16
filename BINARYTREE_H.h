/* 
 * File:   BINARYTREE_H.h
 * Author: U140172
 *
 * Created on 25 de mayo de 2017, 13:01
 */
#include "constants.h"

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

BinaryTree* create_tree_from_string(char* strTree);
char *chose_tence1(int num);
char *chose_tence2(int num);
char*hash(char A, int num, int type);
BinaryTree* create_from_file(FILE* f, int type);


void print_tree_real(BinaryTree * tree, int prof);
void dump_line(FILE * fp);
void dump_line_error(FILE * fp);
void print_manual_tree(BinaryTree* tree);
void menu();
#endif	/* BINARYTREE_H_H */

