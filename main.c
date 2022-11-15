//
// Created by Maxime Bézot on 17/10/2022.
//
#include <stdio.h>
#include "structures.h"
#include "fonctions.h"
#include "menus.h"


int main()
{
    p_tree verbe_arbre = createTree('0');
    p_tree adj_arbre = createTree('0');
    p_tree adv_arbre = createTree('0');
    p_tree nom_arbre = createTree('0');
    char** phrase;
    init_trees(verbe_arbre, adj_arbre, adv_arbre, nom_arbre);
    srand(time(NULL));

    //phrase = generateurPhraseBase(verbe_arbre, nom_arbre, adj_arbre, adv_arbre, 1);
    //printf("%s %s %s %s", phrase[0], phrase[1],phrase[2],phrase[3]);

    starter_menu(verbe_arbre, adj_arbre, adv_arbre, nom_arbre);
    return 0;
}

