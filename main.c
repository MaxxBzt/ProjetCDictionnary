//
// Created by NGASSA Yoke, LIM Emy, BEZOT Maxime on 17/10/2022.
//
#include <stdio.h>
#include "structures.h"
#include "menus.h"


int main()
{
    p_tree verb_tree = createTree('0');
    p_tree adjective_tree = createTree('0');
    p_tree adverb_tree = createTree('0');
    p_tree noun_tree = createTree('0');
    p_tree determinants = createTree('0');
    srand(time(NULL));
    init_trees(verb_tree, adjective_tree, adverb_tree, noun_tree,determinants);
    starter_menu(verb_tree, adjective_tree, adverb_tree, noun_tree,determinants);
    return 0;
}

