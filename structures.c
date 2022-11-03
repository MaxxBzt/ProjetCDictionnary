//
// Created by Maxime Bézot on 02/11/2022.
//

#include "structures.h"

p_node createNode(char letter){
    p_node node = malloc(sizeof(t_node));
    node->letter = letter;
    return node;
}

p_dictionarycell createCell_DictionaryList(char *forme_flechie, char *base_word, char *troisieme_cate)
{
    p_dictionarycell cell = (t_dictionarycell*)malloc(sizeof(t_dictionarycell));
    cell->forme_flechie = forme_flechie;
    cell->base_word = base_word;
    cell->troisieme_cate = troisieme_cate;
    cell->next = NULL;
    return cell;

}



