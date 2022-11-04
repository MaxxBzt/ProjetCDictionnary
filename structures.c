//
// Created by Maxime Bézot on 02/11/2022.
//

#include "structures.h"

p_node createNode(char letter){
    p_node node = malloc(sizeof(t_node));
    node->letter = letter;
    return node;
}

p_dictionarycell createCell_DictionaryList(char *forme_flechie, char *base_word, char *declinaison)
{
    p_dictionarycell cell = (t_dictionarycell*)malloc(sizeof(t_dictionarycell));
    cell->forme_flechie = forme_flechie;
    cell->base_word = base_word;
    cell->declinaison = declinaison;
    cell->next = NULL;
    return cell;

}

p_node createTreeNode(char letter)
{
    p_node new;

    new = (p_node)malloc(sizeof(t_node));
    new->letter = letter;
    new->child = new->next = NULL;
    new->formes_flechies = NULL;

    return new;
}

t_tree createTree(char letter){
    t_tree new_tree;

    new_tree.root = createTreeNode(letter);
    return new_tree;
}

