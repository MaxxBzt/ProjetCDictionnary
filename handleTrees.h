//
// Created by nolwen on 11/20/2022.
//

#ifndef PROJETCDICTIONNARY_HANDLETREES_H
#define PROJETCDICTIONNARY_HANDLETREES_H

#include "structures.h"


void addToTree(p_dictionarycell temp_line, p_tree word_tree);
void init_trees(p_tree tree_ver,p_tree tree_adj,p_tree tree_adv,p_tree tree_nom,p_tree determinants);
p_node createNodeInTree(p_node node,char* word);
void ask_to_add_flechie_word(p_tree tree,char* word,p_node node);
void displayFlechieList(p_flechieslist list);

// ---------- FUNCTIONS USED WHEN SEARCHING A WORD IN A TREE --------

p_node isWordInTree(char* word, p_tree tree);
char* Extract_random_base_word_from_tree(p_tree tree);
p_flechiescell randomFlechiesWord(char* word, p_tree tree);
p_flechiesearch searchFormeFlechie(p_node node, char* word);
p_flechiesearch searchBaseWord(p_node node, char* word);

#endif //PROJETCDICTIONNARY_HANDLETREES_H
