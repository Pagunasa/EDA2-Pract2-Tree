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

BinaryTree* create_empty_tree() {//inicialitza i crea un node

    BinaryTree *tree;
    tree = (BinaryTree*) malloc(sizeof (BinaryTree)); //agafem l'espai necessari per el node

    strlcpy(tree->info, STRINGDEFAULT, MAXLENGTH); //informació del node

    //node sense fills
    tree->left = NULL;
    tree->rigth = NULL;

    return tree;
}

BinaryTree* create_tree(BinaryTree* left, char* content, BinaryTree * right) {//uneix tres nodes per crear un arbre binari

    BinaryTree *tree_root;
    tree_root = create_empty_tree(); //cream l'arrel de l'arbre

    strlcpy(tree_root->info, content, MAXLENGTH); //omplir inf de l'arrel

    tree_root->left = left; //unim el ndoe esquerra amb l'arrel
    tree_root->rigth = right; //unim el node dret amb l'arrel

    return tree_root; //returnem punter a l'arrel
}

BinaryTree* left_tree(BinaryTree * tree) {//retorna arbre esquerra del node passat
    return tree->left;
}

BinaryTree* right_tree(BinaryTree * tree) {//retorna arbre dret del node passat
    return tree->rigth;
}

char* get_content(BinaryTree * tree) {//retorna informació node
    return tree->info;
}

int is_empty(BinaryTree * tree) {//mira si el node està buid
    if (tree->info == STRINGDEFAULT) {//comproba si la inf es la mateixa que el inicialitzar
        return TRUE;
    } else {
        return FALSE;
    }
}

void print_tree(BinaryTree * tree) {//imprimeix arbre
    int prof = 0; //profunditat del node a analitzar
    if (is_empty(tree) == FALSE) {
        print_tree_real_noFake_conMedicina_1LinkMega_UTorrent(tree, prof); //imprimir tot l'arbre
    } else {
        printf(COLOR_RED STR_EMPTY_TREE COLOR_RESET);
    }
}

void print_tree_real_noFake_conMedicina_1LinkMega_UTorrent(BinaryTree * tree, int prof) {//imprimiex tot l'arbre amb les seves preguntes i respostes
    int i;

    for (i = 0; i < prof; i++) {// segons la profunditat en que estem fem més tabulacions
        printf("\t");
    }
    //recorregut en post-order
    if (tree->left == NULL && tree->rigth == NULL) {//mira si el node es una fulla
        printf(STR_SGST, tree->info); //imprimeix el consell
        return;
    } else {
        prof++; //augmentem profunditat
        printf(STR_ANSY, tree->info); //imprimir pregunta si la resposta és si
        print_tree_real_noFake_conMedicina_1LinkMega_UTorrent(left_tree(tree), prof);

        //controlem profunitat per que no es produeixin errors
        if (prof > 0) {
            prof--;
        }
        for (i = 0; i < prof; i++) {
            printf("\t");
        }

        printf(STR_ANSN, tree->info); //imprimim pregunta si la resposta és no
        prof++;
        print_tree_real_noFake_conMedicina_1LinkMega_UTorrent(right_tree(tree), prof++);
    }
}

void print_manual_tree(BinaryTree* tree) {//recorrem l'arbre segons les respotes de l'usuari
    char option[MAXLENGTH3];
    if (is_empty(tree) == FALSE) {//mira si el node esta buid
        while ((tree->left != NULL && tree->rigth != NULL)) {
            printf(tree->info); //imprimeix pregunta
            printf(" (yes or no) ");
            while (!scanf("%s", &option) ||
                    strcmp(option, STR_YES) != 0
                    && strcmp(option, STR_NO) != 0) dump_line_error(stdin);
            dump_line(stdin); //escaneja respota i evita errors de escriptura per pantalla
            if (strcmp(option, STR_YES) == 0) {
                tree = left_tree(tree); //si la resposta es si mira l'arbre esqurra
            } else if (strcmp(option, STR_NO) == 0) {
                tree = right_tree(tree); // si la resposta és no mira l'arbre dret
            }
        }
        printf(tree->info); //imprimeix consell
        printf(STR_JUMP);
    } else {
        printf(COLOR_RED STR_EMPTY_TREE COLOR_RESET); //missatge error
    }
}

BinaryTree* create_example1() {// crea l'arbre de menjar
    BinaryTree *left, *right, *root, *root2;

    //3 es l'arrel dels nodes 8 i 9
    left = create_tree(NULL, TREE1_8, NULL);
    right = create_tree(NULL, TREE1_9, NULL);
    root = create_tree(left, TREE1_3, right);

    //2 es l'arrel de 10 i 3
    right = create_tree(NULL, TREE1_10, NULL);
    root = create_tree(root, TREE1_2, right);

    //uneix nodes 11 i 12 amb 5, la seva arrel
    left = create_tree(NULL, TREE1_11, NULL);
    right = create_tree(NULL, TREE1_12, NULL);
    root2 = create_tree(left, TREE1_5, right);

    //uneix nodes 13 i 14 amb 6, la seva arrel
    left = create_tree(NULL, TREE1_13, NULL);
    right = create_tree(NULL, TREE1_14, NULL);
    right = create_tree(left, TREE1_6, right);

    //uneix nodes 5 i 6 amb 4, la seva arrel
    root2 = create_tree(root2, TREE1_4, right);

    //uneix nodes 2 i 4 amb la seva arrel, el node 1
    root = create_tree(root, TREE1_1, root2);

    return root;
}

BinaryTree* create_example2() {//crea l'arbre de cinema
    BinaryTree *left, *right, *root, *root2;

    //uneix nodes amb informacio 10 i informacio 15 amb 8, la seva arrel
    left = create_tree(NULL, TREE2_10, NULL);
    right = create_tree(NULL, TREE2_15, NULL);
    root = create_tree(left, TREE2_8, right);

    //uneix nodes amb informacio 9 i informacio 8 amb 4, la seva arrel
    left = create_tree(NULL, TREE2_9, NULL);
    root = create_tree(left, TREE2_4, root);

    //uneix nodes amb informacio 13 i informacio 14 amb 3, la seva arrel
    left = create_tree(NULL, TREE2_13, NULL);
    right = create_tree(NULL, TREE2_14, NULL);
    root2 = create_tree(left, TREE2_3, right);

    //uneix nodes amb informacio 14 i 12 amb 4, la seva arrel
    left = create_tree(NULL, TREE2_14, NULL);
    right = create_tree(NULL, TREE2_12, NULL);

    //uneix nodes amb informacio 4 i 11 amb 5, la seva arrel
    right = create_tree(left, TREE2_4, right);
    left = create_tree(NULL, TREE2_11, NULL);
    right = create_tree(left, TREE2_5, right);

    //uneix nodes amb informacio 2 i 4 amb 1, la seva arrel
    root2 = create_tree(root2, TREE2_2, right);

    root = create_tree(root, TREE2_1, root2);

    return root;
}



//Funció que, al rebre un enter, retorna la resposta corresponent

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
//Funció que, al rebre un enter, retorna la resposta corresponent

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
        case 15:
            return TREE2_15;
            break;
        default:
            return "ERROR";
    }
}
//Taula de hash per aconseguir l'enter adient a partir de les dades dels fitxers
//Si l'entrada conté una R és una resposta, com que les respostes estan del vuit
//en amunt, li suma vuit (En el cas de l'arbre de menjar 7). Si l'entrada no
//conté R retorna el valor numèric del caracter

char*hash(char A, int num, int type) {
    if (A == 'R') {
        num += 8;
        if (type == TRUE) {
            num -= 1;
        }
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

//Crea un arbre a partir d'un codi concret dins un fitxer .txt

BinaryTree* create_from_file(FILE* f, int type) {

    BinaryTree *left, *right, *root;
    int num;
    char* str, A;
    fscanf(f, "%s", str);
    //Escanejem l'entrada i en cuardem els valors
    sscanf(str, "%c%d", &A, &num);
    //Anulem els parèntesis
    if (A == '(' || A == ')') {
        return create_from_file(f, type);
    }
    //El cas base de la funció és si l'entrada conté una R ja que serà una
    //resposta i per tant serà una fulla de l'arbre
    if (A == 'R') {
        //si es tracta de l'arbre de menjar, cridem a la funció hash
        //corresponent a aquest
        if (type == TRUE) {
            root = create_tree(NULL, hash(A, num, TRUE), NULL);
            return root;
        }
        //Sino, es crida al de pelicules
        if (type == FALSE) {
            root = create_tree(NULL, hash(A, num, FALSE), NULL);
            return root;
        }
        //Si no és el cas base es crida recursivament dos cops per fer l'arbre
        //dret i l'esquerra i en crea un arbre on l'arrel és l'entrada rebuda.
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
