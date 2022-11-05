//
// Created by nolwen ngassa on 11/3/22.
//

#ifndef PROJETCDICTIONNARY_FONCTIONS_H
#define PROJETCDICTIONNARY_FONCTIONS_H

#include "structures.h"

t_dictionarylist Split_dictionary_in_linked_list();
char** split_a_string(char* , char , int*);
int Search_string_in_string(char*, char*);

t_tree addToTree(t_dictionarylist);
p_node findIntersection(p_node, char*, int*);

void displayNodeChild(p_node);
void init_trees(p_tree,p_tree,p_tree,p_tree,p_tree,t_dictionarylist*);


#endif //PROJETCDICTIONNARY_FONCTIONS_H
