//
// Created by Maxime Bézot on 17/10/2022.
//
#include <stdio.h>
#include "structures.h"
#include "fonctions.h"
#include "menus.h"


int main()
{
    printf("!--WARNING--!\nPlease make sure that the path of the dictionary file is correct \n");
    printf("The path can be found in the initTree functions, in fonctions.c \n");
    p_tree verbe_arbre = createTree('0');
    p_tree adj_arbre = createTree('0');
    p_tree adv_arbre = createTree('0');
    p_tree nom_arbre = createTree('0');
    char** phrase;
    init_trees(verbe_arbre, adj_arbre, adv_arbre, nom_arbre);
    srand(time(NULL));

    starter_menu(verbe_arbre, adj_arbre, adv_arbre, nom_arbre);
    return 0;
}

