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

    strlcpy(tree_root->info, content, MAXLENGTH);

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
    int prof = 0;
    print_tree_real_noFake_conMedicina_1LinkMega_UTorrent(tree, prof);
}

//el problema de las tabulaciones era pk habia una /t al final de la 2ª llamada recurs
void print_tree_real_noFake_conMedicina_1LinkMega_UTorrent(BinaryTree * tree, int prof) {
    int i;
    
    for (i = 0; i < prof; i++) {
        printf("\t");
    }
    
    if (tree->left == NULL && tree->rigth == NULL) {
        printf(STR_SGST, tree->info);
        return;
    } else {
        prof++;
        printf(STR_ANSY, tree->info);
        print_tree_real_noFake_conMedicina_1LinkMega_UTorrent(left_tree(tree), prof);

        if (prof > 0) {
            prof--;
        }
        for (i = 0; i < prof; i++) {
            printf("\t");
        }
  
        printf(STR_ANSN, tree->info);
        prof++;
        print_tree_real_noFake_conMedicina_1LinkMega_UTorrent(right_tree(tree), prof++);
    }
}

void print_manual_tree(BinaryTree* tree){
    
}

BinaryTree* create_example1() {
    BinaryTree *left, *right, *root, *root2;

    left = create_tree(NULL, TREE1_8, NULL);
    right = create_tree(NULL, TREE1_9, NULL);
    root = create_tree(left, TREE1_3, right);

    right = create_tree(NULL, TREE1_10, NULL);
    root = create_tree(root, TREE1_2, right);

    left = create_tree(NULL, TREE1_11, NULL);
    right = create_tree(NULL, TREE1_12, NULL);
    root2 = create_tree(left, TREE1_5, right);

    left = create_tree(NULL, TREE1_13, NULL);
    right = create_tree(NULL, TREE1_14, NULL);
    right = create_tree(left, TREE1_6, right);

    root2 = create_tree(root2, TREE1_4, right);

    root = create_tree(root, TREE1_1, root2);

    return root;
}

BinaryTree* create_example2() {
    BinaryTree *left, *right, *root, *root2;

    left = create_tree(NULL, TREE2_10, NULL);
    right = create_tree(NULL, TREE2_15, NULL);
    root = create_tree(left, TREE2_8, right);

    left = create_tree(NULL, TREE2_9, NULL);
    root = create_tree(left, TREE2_4, root);

    left = create_tree(NULL, TREE2_13, NULL);
    right = create_tree(NULL, TREE2_14, NULL);
    root2 = create_tree(left, TREE2_3, right);

    left = create_tree(NULL, TREE2_14, NULL);
    right = create_tree(NULL, TREE2_12, NULL);

    right = create_tree(left, TREE2_4, right);
    left = create_tree(NULL, TREE2_11, NULL);
    right = create_tree(left, TREE2_5, right);

    root2 = create_tree(root2, TREE2_2, right);

    root = create_tree(root, TREE1_1, root2);

    return root;
}

void dump_line(FILE * fp) {//funcio per evitar el borrat de inputs
    int ch;

    while ((ch = fgetc(fp)) != EOF && ch != '\n');
}

void dump_line_error(FILE * fp) {// creida dump_line i imprimeix error per pantalla
    printf(COLOR_RED STR_ERR_INPUT COLOR_RESET);
    dump_line(fp);
}