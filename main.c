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
    p_tree determinants = createTree('0');
    init_trees(verbe_arbre, adj_arbre, adv_arbre, nom_arbre,determinants);
    srand(time(NULL));

    starter_menu(verbe_arbre, adj_arbre, adv_arbre, nom_arbre,determinants);
    return 0;
}

