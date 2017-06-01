/* 
 * File:   main.c
 * Author: U140172
 *
 * Created on 25 de mayo de 2017, 12:48
 */

#include <stdio.h>
#include <stdlib.h>

#include "BINARYTREE_H.h"

/*
 * 
 */
int main(int argc, char** argv) {

    printf(STR_WLC);
    getc(stdin);

    menu();

    return (EXIT_SUCCESS);
}

void menu() {
    int option = 2;
    BinaryTree *tree;

    do {
        
            printf(STR_ENTOP);
            printf(STR_EX1AUTO);
            printf(STR_EX2AUTO);
            printf(STR_EX1MN);
            printf(STR_EX2MN);
            printf(STR_LDTRE);
            printf(STR_EXIT);
        while (!scanf("%d", &option)) dump_line_error(stdin);

        switch (option) {
            case MTAUTO:
                tree = create_example1();
                print_tree(tree);
                break;
            case FTAUTO:
                tree = create_example2();
                print_tree(tree);
                break;
            case MTMANU:
                tree = create_example1();
                print_manual_tree(BinaryTree* tree);
                break;
            case FTMANU:
                tree = create_example2();
                print_manual_tree(BinaryTree* tree);
                break;
            case LDTRIF:
                break;
            case EXITOV:
                printf(STR_THNK);
                break;
            default:
                printf(COLOR_RED STR_NTVA COLOR_RESET);
        }
    } while (option != 0);
}