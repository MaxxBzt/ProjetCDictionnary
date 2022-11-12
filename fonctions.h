//
// Created by nolwen ngassa on 11/3/22.
//

#ifndef PROJETCDICTIONNARY_FONCTIONS_H
#define PROJETCDICTIONNARY_FONCTIONS_H

#include "structures.h"

t_dictionarylist Split_dictionary_in_linked_list();
char** split_a_string(char* , char , int*);
int Search_string_in_string(char*, char*);

void addToTree(p_dictionarycell, p_tree);

void displayNodeChild(p_node);

void init_trees(p_tree,p_tree,p_tree,p_tree,p_tree);

p_node findIfLetterInList(p_node ,char );
int isWordInTree(char *word, p_tree);
p_node createNodeInTree(p_node ,char* );


#endif //PROJETCDICTIONNARY_FONCTIONS_H
