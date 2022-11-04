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

t_tree createTree(char letter){
    t_tree new_tree;

    new_tree.root = createNode(letter);
    return new_tree;
}

p_flechiescell createFlechieCell(char* flechie, char* type){
    p_flechiescell new;

    new = (p_flechiescell)malloc(sizeof(t_flechiescell));
    new->flechie_word = flechie;
    new->type = type;

    return new;
}