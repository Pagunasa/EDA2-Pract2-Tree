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
    
    BinaryTree *tree;
    tree = create_example1();
    
    print_tree(tree);

    return (EXIT_SUCCESS);
}

