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
    if (is_empty(tree) == FALSE) {
        print_tree_real_noFake_conMedicina_1LinkMega_UTorrent(tree, prof);
    } else {
        printf(COLOR_RED STR_EMPTY_TREE COLOR_RESET);
    }
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

void print_manual_tree(BinaryTree* tree) {
    char option[MAXLENGTH3];
    if (is_empty(tree) == FALSE) {
        while ((tree->left != NULL && tree->rigth != NULL)) {
            printf(tree->info);
            printf(" (yes or no) ");
            while (!scanf("%s", &option) ||
                    strcmp(option, STR_YES) != 0
                    && strcmp(option, STR_NO) != 0) dump_line_error(stdin);
            dump_line(stdin);
            if (strcmp(option, STR_YES) == 0) {
                tree = left_tree(tree);
            } else if (strcmp(option, STR_NO) == 0) {
                tree = right_tree(tree);
            }
        }
        printf(tree->info);
        printf(STR_JUMP);
    } else {
        printf(COLOR_RED STR_EMPTY_TREE COLOR_RESET);
    }
}

BinaryTree* create_tree_from_string(char* strTree) {
    int j = 0;
    while (strTree[j] != '\0') {
        if (strTree[j] == STRG_OPEN) {

        }
    }
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

    root = create_tree(root, TREE2_1, root2);

    return root;
}

char *chose_tence1(int num) {
    switch (num) {
        case 1:
            return TREE1_1;
        case 2:
            return TREE1_2;
        case 3:
            return TREE1_3;
        case 4:
            return TREE1_4;
        case 5:
            return TREE1_5;
        case 6:
            return TREE1_6;
        case 8:
            return TREE1_8;
        case 9:
            return TREE1_9;
        case 10:
            return TREE1_10;
        case 11:
            return TREE1_11;
        case 12:
            return TREE1_12;
        case 13:
            return TREE1_13;
        case 14:
            return TREE1_14;
        default:
            return "ERROR";
    }
}

char *chose_tence2(int num) {
    switch (num) {
        case 1:
            return TREE2_1;
        case 2:
            return TREE2_2;
        case 3:
            return TREE2_3;
        case 4:
            return TREE2_4;
        case 5:
            return TREE2_5;
        case 6:
            return TREE2_6;
        case 8:
            return TREE2_8;
        case 9:
            return TREE2_9;
        case 10:
            return TREE2_10;
        case 11:
            return TREE2_11;
        case 12:
            return TREE2_12;
        case 13:
            return TREE2_13;
        case 14:
            return TREE2_14;
        default:
            return "ERROR";
    }
}

char*hash(char A, int num, int type) {
    if (A == 'R') {
        num += 8;
    } else {
        num = A - 64;
    }

    if (type == TRUE) {
        return chose_tence1(num);
    }
    if (type == FALSE) {
        return chose_tence2(num);
    }
}

BinaryTree* create_from_file(FILE* f, int type) {

    BinaryTree *left, *right, *root;
    int num;
    char* str, A;
    fscanf(f, "%s", str);
    sscanf(str, "%c%d", &A, &num);
    if (A == '(' || A == ')') {
        return create_from_file(f, type);
    }
    if (A == 'R') {
        if (type == TRUE) {
            root = create_tree(NULL, hash(A, num, TRUE), NULL);
            return root;
        }
        if (type == FALSE) {
            root = create_tree(NULL, hash(A, num, FALSE), NULL);
            return root;
        }
    } else if (A > 64 && A < 91) {
        sscanf(str, "%c", &A);
        left = create_from_file(f, type);
        right = create_from_file(f, type);
        if (type == TRUE) {
            root = create_tree(left, hash(A, FALSE, TRUE), right);
        }
        if (type == FALSE) {
            root = create_tree(left, hash(A, FALSE, FALSE), right);
        }
    }


}

void dump_line(FILE * fp) {//funcio per evitar el borrat de inputs
    int ch;
    while ((ch = fgetc(fp)) != EOF && ch != '\n');
}

void dump_line_error(FILE * fp) {// creida dump_line i imprimeix error per pantalla
    printf(COLOR_RED STR_ERR_INPUT COLOR_RESET);
    dump_line(fp);
}