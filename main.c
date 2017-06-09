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

    menu(); //cridem a la funció menu

    return (EXIT_SUCCESS);
}

void menu() {
    int option = 2;
    BinaryTree *tree;
    FILE* f;

    do {
        printf(STR_ENTOP);
        printf(STR_EX1AUTO);
        printf(STR_EX2AUTO);
        printf(STR_EX1MN);
        printf(STR_EX2MN);
        printf(STR_EX1F);
        printf(STR_EX2F);
        printf(STR_EXIT);
        while (!scanf("%d", &option)) dump_line_error(stdin);
        dump_line(stdin);//comprova que l'usuari entri les dades correctes

        switch (option) {
            case MTAUTO://imprimir totes les opcions arbre menjar
                tree = create_example1();//crea l'arbre de menjar
                print_tree(tree);//imprimeix arbre menjar 
                break;
            case FTAUTO://imprimir totes les opcions arbre cinema
                tree = create_example2();//crea l'arbre de cinema
                print_tree(tree);//imprimeix arbre cinema 
                break;
            case MTMANU:// aconsellar usuari a partir d'arbre menjar
                tree = create_example1();//crea l'arbre de menjar
                print_manual_tree(tree);//imprimim l'arbre segons les respostes de l'usuari
                break;
            case FTMANU:// aconsella usuaria a partir d'arbre cinema
                tree = create_example2();//crea l'arbre de cinema
                print_manual_tree(tree);//imprimim l'arbre segons les respostes de l'usuari
                break;
            case MTFILE://crea arbre menjar a partir de fitxer
                f = fopen("tree1.txt", "r");
                if (f == NULL) {
                    printf("ERROR");
                }
                tree = create_from_file(f, TRUE);
                fclose(f);
                print_tree(tree);
                break;
            case FTFILE://crea arbre cinema a partir de fitxer
                f = fopen("tree2.txt", "r");
                if (f == NULL) {
                    printf("ERROR");
                }
                tree = create_from_file(f, FALSE);
                fclose(f);
                print_tree(tree);
                break;
            case EXITOV://acabar el programa
                printf(STR_THNK);
                break;
            default:
                printf(COLOR_RED STR_NTVA COLOR_RESET);
        }
    } while (option != 0);//bucle per que pogem realitzar tantes operacions com desitjem 
}